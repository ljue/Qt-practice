//// GL.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
//
//float
//ax=30, ay=45,// Углы поворота изображения вокруг осей X и Y
//dx, dy, dz = -6,// Сдвиги вдоль координат
//color[] = { 0.1f, 0.6f, 0.1f };
//short posX, posY;// Текущая позиция указателя мыши
//bool leftButton, twoSide, culling, flat;// Нажата левая кнопка мыши. Свет отражается от обеих поверхностей (лицевой и обратной)
//
//uint
//nRings = 20,	// Количество колец (широта)
//nSects = 20,	// Количество секций (долгота)
//nTria, nVert;
//
//const uint clr1 = RGB(0, 255, 0), clr2 = RGB(0, 0, 255);	// Два цвета
//const float
//rad = 1.5f, 		// Радиус сферы
//PI = acos(-1.0f);
//float
//pos[] = { 0, 0, 5, 0 },	// Позиция источника света
//amb[] = { 0.05f, 0.05f, 0.05f },	// Фоновая подсветка
//dif[] = { 0.9f, 0.9f, 0.9f },	// Свет, обеспечивающий иллюзию трехмерности
//spec[] = { 0.8f, 0.8f, 0.8f };	// Свет, обеспечивающий блик
//char buf[128];		// Буфер текста
//int shine = 40; 	// Блескость материала
//
//
//float
//rotX, rotY,	// Скорости поворота
//rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };// Матрица, суммирующая малые вращения
//
//
//class Point3D // инкапсулирующий функциональность точки трехмерного пространства
//{
//public:
//	float x, y, z;
//
//	Point3D() { x = y = z = 0; } 
//	Point3D(float c1, float c2, float c3) 
//	{
//		x = c1;
//		y = c2;
//		z = c3;
//	}
//	Point3D& operator +=(const Point3D& coeff)  
//	{
//		x += coeff.x;
//		y += coeff.y;
//		z += coeff.z;
//	}
//};
//
//struct VERT { Point3D v, n; uint c; };// Координаты вершины, нормали и ее цвет
//struct TRIA { int i1, i2, i3; };	// Индексы трех вершин треугольника, выбираемых из массива вершин типа VERT
//
//void Sphere(VERT *v, TRIA* t) //алгоритм последовательного обхода сначала всех сферических треугольников вокруг полюсов сферы, а затем обхода сферических четырехугольников, образованных пересечением параллелей и меридианов. В процессе обхода формируется массив вершин Vert. После этого обходы повторяются для того, чтобы заполнить массив индексов Tria. Северный и южный полюса обрабатываются индивидуально.
//{
//
//	uint last = nVert - 1;// Индекс последней вершины (на южном полюсе)
//
//	v[0].v = Point3D(0, rad, 0);// Формирование массива вершин. Северный полюс
//	v[0].n = Point3D(0, 1, 0);
//	v[0].c = clr2;
//
//	v[last].v = Point3D(0, -rad, 0); // Южный полюс
//	v[last].n = Point3D(0, -1, 0);
//	v[last].c = nVert & 1 ? clr2 : clr1;
//
//	float
//		da = PI / (nRings + 2),
//		db = 2 * PI / nSects,
//		af = PI - da / 2,
//		bf = 2 * PI - db / 2;
//
//	uint n = 1;	// Индекс вершины, следующей за северным полюсом
//
//	for (float a = da; a < af; a += da) 	// Циклпошироте
//	{
//		float
//			y = rad * cos(a), 		// Координата y постоянна для всего кольца
//			xz = rad * sin(a);
//
//		for (float b = 0.; b < bf; n++, b += db)// Циклподолготе
//		{
//			float// Координаты проекции в экваториальной плоскости
//				x = xz * sin(b),
//				z = xz * cos(b);
//
//			v[n].v = Point3D(x, y, z);
//			v[n].n = Point3D(x / rad, y / rad, z / rad);
//			v[n].c = n & 1 ? clr1 : clr2;
//		}
//	}
//
//	for (uint n = 0; n<nSects; n++)	// Формирование массива индексов. Треугольники вблизи полюсов
//	{
//		t[n].i1 = 0;// Индекс общей вершины (северный полюс)
//		t[n].i2 = n + 1;// Индекс текущей вершины
//		t[n].i3 = n == nSects - 1 ? 1 : n + 2;// Замыкание
//
//		t[nTria - nSects + n].i1 = nVert - 2 - ((1 + n) % nSects);	// Южныйполюс
//		t[nTria - nSects + n].i2 = nVert - 1;
//		t[nTria - nSects + n].i3 = nVert - 2 - n;
//	}
//
//	int k = 1;		// Вершина, следующая за полюсом
//	n = nSects;
//	for (uint i = 0; i<nRings; i++, k += nSects)// Треугольникиразбиенияколец
//	{
//		for (uint j = 0; j < nSects; j++, n += 2)
//		{
//			t[n].i1 = k + j;
//			t[n].i2 = k + nSects + j;
//			t[n].i3 = k + nSects + ((j + 1) % nSects);
//
//			t[n + 1].i1 = t[n].i1;
//			t[n + 1].i2 = t[n].i3;
//			t[n + 1].i3 = k + ((j + 1) % nSects);
//		}
//	}
//}
//
//void Print(float x, float y, char *format, ...)
//{
//	va_list args;
//	char buffer[200];
//	va_start(args, format);
//	vsprintf_s(buffer, format, args);
//	va_end(args);
//	glPushMatrix();
//	glTranslatef(x, y, 0);
//	for (char* p = buffer; *p; p++)
//		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p); // GLUT_STROKE_MONO_ROMAN // GLUT_STROKE_ROMAN
//	glPopMatrix();
//}
//
//void DrawInfo()
//{
//	glPushAttrib(GL_ENABLE_BIT);
//	glDisable(GL_DEPTH_TEST);
//	glDisable(GL_LIGHTING);
//	glMatrixMode(GL_PROJECTION);
//	glPushMatrix();
//	glLoadIdentity();
//	gluOrtho2D(0, 3000, 0, 3000);
//	glMatrixMode(GL_MODELVIEW);
//	glColor3f(0.7f, 1, 0);
//	Print(80, 2800, "Rings: %d", nRings);
//	Print(80, 2650, "Sects: %d", nSects);
//	Print(80, 2500, "Triangles: %d", nTria);
//	Print(80, 200, "Light is: %s", buf);
//	Print(80, 60, "Coordinates: (%3.1f, %3.1f, %3.1f)", pos[0], pos[1], pos[2]);
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//	glPopAttrib();
//}
//
//
//void OnPaint()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPushMatrix(); //запоминают ММ
//
//	DrawInfo();
//
//	glTranslated(dx, dy, dz);
//	glMultMatrixf(rotMatrix);// Вместо поворотов умножаем на матрицу, вобравшую все вращения
//
//	glCallList(1);// проиграет список команд, среди которых главную роль играют команды вида glVertex3f(x, y, z)
//
//	glPopMatrix();//восстанавливают ММ
//	glutSwapBuffers();
//}
//
//
//void AddRotation(float angle, float x, float y, float z)
//{
//	glPushMatrix();
//	glLoadIdentity();
//	glRotatef(angle, x, y, z);
//	glMultMatrixf(rotMatrix);
//	glGetFloatv(GL_MODELVIEW_MATRIX, rotMatrix);
//	glPopMatrix();
//}
//
//
//void OnSize(int w, int h)	// Реакция на WM_SIZE
//{
//	glViewport(0, 0, w, h);// Задаем видовой порт окна (вся клиентская область)
//	glMatrixMode(GL_PROJECTION); //определяет в качестве текущей матрицу моделирования
//	glLoadIdentity();//загружает в нее матрицу с единицами на диагонали
//	gluPerspective(45, double(w) / h, 0.1, 100); // угол, боковые грани(дисбаланс), передняя и задняя грани
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//}
//void DrawScene()
//{
//	nTria = 2 * (nRings + 1) * nSects; // Общее количество треугольников
//	nVert = (nRings + 1) * nSects + 2;	// Общее количество вершин
//	VERT *Vert = new VERT[nVert];
//	TRIA *Tria = new TRIA[nTria];
//
//	Sphere(Vert, Tria);	// Вычисление координат, нормалей и индексов
//
//	// Задание адресов трех массивов (вершин, нормалей и цветов),  а также шага перемещения по ним
//	glVertexPointer(3, GL_FLOAT, sizeof(VERT), &Vert->v);
//	glNormalPointer(GL_FLOAT, sizeof(VERT), &Vert->n);
//	glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(VERT), &Vert->c);
//
//	glNewList(1, GL_COMPILE);	// Формирование списка рисующих команд
//	glDrawElements(GL_TRIANGLES, nTria * 3, GL_UNSIGNED_INT, Tria);
//	glEndList();
//	delete[] Vert;
//	delete[] Tria;
//
//}
//void Init()
//{
//	strcpy_s(buf, (pos[3] == 1 ? "Positional" : "Directional"));
//	glClearColor(0, 0, 0, 0);		// Цвет фона (на сей раз традиционно черный)
//	glEnable(GL_LIGHT0);// Источник света, размещенный в точке z = ∞
//	glEnable(GL_LIGHTING);// "Рубильник в подвале"
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_CULL_FACE); 		// Culling говорит о том, что невидимые поверхности можно не рисовать
//	glShadeModel(flat ? GL_FLAT : GL_SMOOTH);
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);// Небольшая фоновая подсветка
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
//	glMaterialf(GL_FRONT, GL_SHININESS, shine);
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_NORMAL_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//	DrawScene();
//}
//
//
//void OnIdle()
//{
//	AddRotation(rotX / 200, 1, 0, 0);
//	AddRotation(rotY / 200, 0, 1, 0);
//	glutPostRedisplay();
//}
//
//void OnMouse(int button, int state, int x, int y)
//{
//	leftButton = button == GLUT_LEFT_BUTTON;
//	if (state == GLUT_DOWN)
//	{
//		glutIdleFunc(0);
//		rotX = rotY = 0;
//	}
//	else
//	{
//		if (fabs(rotX) > 1 || fabs(rotY) > 1)
//			glutIdleFunc(OnIdle);
//		else
//			glutIdleFunc(0);
//	}
//	posX = x;
//	posY = y;
//}
//
//void OnMouseMove(int x, int y)
//{
//	rotX = y - posY;
//	rotY = x - posX;
//
//	if (leftButton)
//	{
//		AddRotation(rotX / 10, 1, 0, 0);
//		AddRotation(rotY / 10, 0, 1, 0);
//	}
//	else
//		dz += (rotX + rotY) / 60;
//	posX = x;
//	posY = y;
//	glutPostRedisplay();
//}
//
//
//void OnKey(byte ch, int x, int y)
//{
//	switch (ch)
//	{
//	case 27: exit(0); break;
//	case '2': twoSide = !twoSide;
//		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, twoSide);
//		break;
//	case 'n': glShadeModel(((flat = !flat) ? GL_FLAT : GL_SMOOTH)); break;
//	case 'p': pos[3] = 1;  break; // источник света находится там, где находится конец вектора pos, а свет имеет обычное направление (вдоль оси –Z). 
//	case 'd': pos[3] = 0;  break; //свет удален в бесконечность, а свет имеет направление, заданное вектором (0, 0, 5). 
//	case 's': pos[0] += 0.1f; break;
//	case 'a': pos[0] -= 0.1f; break;
//	}
//	strcpy_s(buf, (pos[3] == 1 ? "Positional" : "Directional"));
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
//	glutPostRedisplay();
//}
//
//void OnSpecialKey(int key, int x, int y)
//{
//	float delta = -0.005 * dz;
//	switch (key)
//	{
//	case GLUT_KEY_DOWN:
//		if (nRings > 30)
//			nRings -= 15;
//		else if (nRings > 0)
//			nRings--;
//		break;
//	case GLUT_KEY_UP:  
//		if (nRings > 30)
//			nRings += 15;
//		else 
//			nRings++;
//		break;
//	case GLUT_KEY_RIGHT: 
//		if (nSects > 30)
//			nSects += 15;
//		else 
//			nSects++;
//		break;
//	case GLUT_KEY_LEFT:  
//		if (nSects > 30)
//			nSects -= 15;
//		else if (nSects > 2)
//			nSects--;
//		break;
//	}
//	DrawScene();
//	glutPostRedisplay();
//}
//
//
//
//
//
//void main()
//{
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(900, 900);
//	glutCreateWindow("");
//	Init();
//
//	glutMouseFunc(OnMouse);
//	glutMotionFunc(OnMouseMove);
//	glutKeyboardFunc(OnKey);
//	glutSpecialFunc(OnSpecialKey);
//
//	glutIdleFunc(OnIdle); //сообщает системе адрес функции, когда приложению(временно) нечего делать.
//	//glutIdleFunc(0); //для остановки анимации
//
//	glutReshapeFunc(OnSize);
//	glutDisplayFunc(OnPaint);
//	glutMainLoop();
//	//===Здесь нельзя размещать код, так как предыдущий оператор является псевдо бесконечным циклом выборки сообщений о событиях
//}
//
//

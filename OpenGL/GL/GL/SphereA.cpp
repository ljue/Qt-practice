#include "stdafx.h"

uint
	nRings = 20,	// Количество колец (широта)
	nSects = 20, 	// Количество секций (долгота)
	nTria, nVert;
const uint clr1 = RGB(0, 255, 0), clr2 = RGB(0, 0, 255);	// Два цвета
const float
	rad = 1.5f, 		// Радиус сферы
	PI = acos(-1.0f);
float
	pos[] = { 0, 0, 5, 0 },	// Позиция источника света
	amb[] = { 0.05f, 0.05f, 0.05f },	// Фоновая подсветка 
	dif[] = { 0.9f, 0.9f, 0.9f },	// Свет, обеспечивающий иллюзию трехмерности
	spec[] = { 0.8f, 0.8f, 0.8f };	// Свет, обеспечивающий блик
char buf[128];		// Буфер текста
int shine = 40; 	// Блескость материала
float
	dx, dy, dz = -7,
	color[] = { 0.1f, 0.6f, 0.1f };
bool flat, leftButton, twoSide;
float rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
short posX, posY;
float rotX, rotY;
int posdir = 0;
void DrawInfo();

class Point3D 
{
public:
	float x, y, z;
	Point3D(void) { x = 0; y = 0; z = 0; };
	Point3D(float ax, float ay, float az) { x = ax; y = ay; z = az; };
	Point3D operator += (Point3D arg) { x += arg.x; y += arg.y; z += arg.z;	return *this; };
};
struct VERT { Point3D v, n; uint c; };  // Координаты вершины, нормали и ее цвет
struct TRIA { int i1, i2, i3; }; 	// Индексы трех вершин треугольника, выбираемых из массива вершин типа VERT
void Sphere(VERT *v, TRIA* t)
{
	uint last = nVert - 1; // Индекс последней вершины (на южном полюсе)

	v[0].v = Point3D(0, rad, 0); // Формирование массива вершин. Северный полюс
	v[0].n = Point3D(0, 1, 0);
	v[0].c = clr2;

	v[last].v = Point3D(0, -rad, 0); // Южный полюс
	v[last].n = Point3D(0, -1, 0);
	v[last].c = nVert & 1 ? clr2 : clr1;

	float
		da = PI / (nRings + 2),
		db = 2 * PI / nSects,
		af = PI - da / 2,
		bf = 2 * PI - db / 2;

	uint n = 1;	// Индекс вершины, следующей за северным полюсом

	for (float a = da; a < af; a += da) 	// Цикл по широте
	{
		float
			y = rad * cos(a), 		// Координата y постоянна для всего кольца
			xz = rad * sin(a);

		for (float b = 0.; b < bf; n++, b += db) // Цикл по долготе
		{
			float // Координаты проекции в экваториальной плоскости
				x = xz * sin(b),
				z = xz * cos(b);

			v[n].v = Point3D(x, y, z);
			v[n].n = Point3D(x / rad, y / rad, z / rad);
			v[n].c = n & 1 ? clr1 : clr2;
		}
	}

	for (n = 0; n < nSects; n++) 	// Формирование массива индексов. Треугольники вблизи полюсов
	{
		t[n].i1 = 0; // Индекс общей вершины  (северный полюс)
		t[n].i2 = n + 1; // Индекс текущей вершины
		t[n].i3 = n == nSects - 1 ? 1 : n + 2; // Замыкание

		t[nTria - nSects + n].i1 = nVert - 2 - ((1 + n) % nSects); 	// Южный полюс
		t[nTria - nSects + n].i2 = nVert - 1;
		t[nTria - nSects + n].i3 = nVert - 2 - n;
	}

	int k = 1;		// Вершина, следующая за полюсом
	n = nSects;
	for (uint i = 0; i < nRings; i++, k += nSects) // Треугольники разбиения колец
	{
		for (uint j = 0; j < nSects; j++, n += 2)
		{
			t[n].i1 = k + j;
			t[n].i2 = k + nSects + j;
			t[n].i3 = k + nSects + ((j + 1) % nSects);

			t[n + 1].i1 = t[n].i1;
			t[n + 1].i2 = t[n].i3;
			t[n + 1].i3 = k + ((j + 1) % nSects);
		}
	}
}

void OnSize(int w, int h)	//При изменении размеров окна
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, double(w) / h, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Print(float x, float y, char *format, ...)
{
	va_list args;
	char buffer[200];
	va_start(args, format);
	vsprintf_s(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	for (char* p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p); // GLUT_STROKE_MONO_ROMAN // GLUT_STROKE_ROMAN
	glPopMatrix();
}
void OnPaint()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	DrawInfo();
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix);

	glCallList(1);

	glPopMatrix();
	glutSwapBuffers();
}

void DrawInfo()
{
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 3000, 0, 3000);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.7f, 1, 0);
	Print(80, 2800, "Rings: %d", nRings);
	Print(80, 2650, "Sects: %d", nSects);
	Print(80, 2500, "Triangles: %d", nTria);
	Print(80, 200, "Light is: %s", buf);
	Print(80, 60, "Coordinates: (%3.1f, %3.1f, %3.1f)", pos[0], pos[1], pos[2]);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}

void AddRotation(float angle, float x, float y, float z)
{
	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle, x, y, z);
	glMultMatrixf(rotMatrix);
	glGetFloatv(GL_MODELVIEW_MATRIX, rotMatrix);
	glPopMatrix();
}
void OnIdle()
{
	AddRotation(rotX / 200, 1, 0, 0);
	AddRotation(rotY / 200, 0, 1, 0);
	glutPostRedisplay();
}

void OnMouse(int button, int state, int x, int y)
{
	leftButton = button == GLUT_LEFT_BUTTON;
	if (state == GLUT_DOWN)	//Не очень понятная логика включения и выключения вращений при нажатии-отпускании мыши
	{
		glutIdleFunc(0);
		rotX = rotY = 0;
	}
	else
	{
		if (fabs(rotX) > 1 || fabs(rotY) > 1)
			glutIdleFunc(OnIdle);
		else
			glutIdleFunc(0);
	}
	posX = x;	// Запоминаем координаты мыши
	posY = y;
}

void OnMouseMove(int x, int y)
{
	rotX = y - posY;
	rotY = x - posX;
	if (leftButton)
	{
		AddRotation(rotX / 10, 1, 0, 0);
		AddRotation(rotY / 10, 0, 1, 0);
	}
	else
		dz += (rotX + rotY) / 60;
	posX = x;	// Запоминаем новые координаты мыши
	posY = y;
	glutPostRedisplay();
}
void Recalc()
{
	nTria = 2 * (nRings + 1) * nSects; // Общее количество треугольников
	nVert = (nRings + 1) * nSects + 2; 	// Общее количество вершин

	VERT *Vert = new VERT[nVert];
	TRIA *Tria = new TRIA[nTria];

	Sphere(Vert, Tria); 	// Вычисление координат, нормалей и индексов

												// Задание адресов трех массивов (вершин, нормалей и цветов),  а также шага перемещения по ним
	glVertexPointer(3, GL_FLOAT, sizeof(VERT), &Vert->v);
	glNormalPointer(GL_FLOAT, sizeof(VERT), &Vert->n);
	glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(VERT), &Vert->c);

	glNewList(1, GL_COMPILE); 	// Формирование списка рисующих команд
	glDrawElements(GL_TRIANGLES, nTria * 3, GL_UNSIGNED_INT, Tria);
	glEndList();
	delete[] Vert;
	delete[] Tria;
}
void OnKey(byte ch, int x, int y)
{
	switch (ch)
	{
	case 27: exit(0); break;
	case '2': twoSide = !twoSide;
		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, twoSide);
		break;
	case '3':glutIdleFunc(OnIdle); break;//Начало вращения
	case '4':glutIdleFunc(0); break;	//Остановка вращения
	case '9':posdir = !posdir;
		if (posdir)
			glLightfv(GL_LIGHT0, GL_POSITION, pos);
		else
			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, pos);
		break;	//Остановка вращения
	case 'f': glShadeModel(((flat = !flat) ? GL_FLAT : GL_SMOOTH)); break;
	}
	Recalc();
	glutPostRedisplay();
}

void OnSpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		if (nRings > 30)
			nRings -= 15;
		else if (nRings > 0)
			nRings--;
		break;
	case GLUT_KEY_UP:
		if (nRings > 30)
			nRings += 15;
		else
			nRings++;
		break;
	case GLUT_KEY_LEFT:
		if (nSects > 30)
			nSects -= 15;
		else if (nSects > 2)
			nSects--;
		break;
	case GLUT_KEY_RIGHT:
		if (nSects > 30)
			nSects += 15;
		else
			nSects++;
		break;
	default: return;
	}
	Recalc();
	glutPostRedisplay();
}


void Init()
{
	strcpy_s(buf, "Directional");
	glClearColor(0, 0, 0, 0); 		// Цвет фона (на сей раз традиционно черный)
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_CULL_FACE); 		// Culling говорит о том, что невидимые поверхности можно не рисовать
	glShadeModel(flat ? GL_FLAT : GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb); // Небольшая фоновая подсветка
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	Recalc();
}

void main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Sphere");

	Init();

	glutMouseFunc(OnMouse);
	glutMotionFunc(OnMouseMove);
	glutKeyboardFunc(OnKey);
	glutSpecialFunc(OnSpecialKey);
	glutReshapeFunc(OnSize);
	glutDisplayFunc(OnPaint);
	glutMainLoop();
	//=== Здесь нельзя размещать код, так как предыдущий оператор является псевдо бесконечным циклом выборки сообщений о событиях
}



//#include "stdafx.h"
//
//float rotX, rotY, dx, dy, dz = -7,
//rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
//pos[] = { 0, 0, 5, 0 },
//amb[] = { 0.05f, 0.05f, 0.05f },
//dif[] = { 0.9f, 0.9f, 0.9f },
//spec[] = { 0.8f, 0.8f, 0.8f };
//uint nRings = 20, nSects = 20, nVert, nTria;
//const uint clr1 = RGB(0, 255, 0), clr2 = RGB(0, 0, 255);
//const float rad = 1.5f, PI = acos(-1.0f);
//short posX, posY;
//bool leftButton, flat = true, culling;
//char buf[128];
//int shine = 40;
//
//class Point3D
//{
//public:
//	float x, y, z;
//	Point3D() { x = y = z = 0; }
//	Point3D(float c1, float c2, float c3) { x = c1; y = c2; z = c3; }
//	Point3D& operator+=(const Point3D& pt) { x += pt.x;	y += pt.y;	z += pt.z; return *this; }
//};
//
//struct VERT { Point3D v, n; uint c; };
//struct TRIA { int i1, i2, i3; };
//
//void Sphere(VERT *v, TRIA* t)
//{
//	uint last = nVert - 1;
//
//	// Top and bottom points
//	v[0].v = Point3D(0, rad, 0);
//	v[0].n = Point3D(0, 1, 0);
//	v[0].c = clr2;
//
//	v[last].v = Point3D(0, -rad, 0);
//	v[last].n = Point3D(0, -1, 0);
//	v[last].c = nVert & 1 ? clr2 : clr1;
//
//	// Generate vertex points for rings
//	float
//		da = PI / (nRings + 2),	 // Angles between each section and ring
//		db = 2 * PI / nSects,
//		af = PI - da / 2,
//		bf = 2 * PI - db / 2;
//
//	uint n = 1;	// vertex being generated, begins at 1 to skip top point
//
//	for (float a = da; a < af; a += da)
//	{
//		float
//			y = rad * cos(a),		// y is the same for each ring
//			xz = rad * sin(a);
//
//		for (float b = 0.; b < bf; n++, b += db)
//		{
//			float
//				x = xz * sin(b),
//				z = xz * cos(b);
//
//			v[n].v = Point3D(x, y, z);
//			v[n].n = Point3D(x / rad, y / rad, z / rad);
//			v[n].c = n & 1 ? clr1 : clr2;
//		}
//	}
//
//	// Generate triangles for top and bottom caps
//	for (n = 0; n < nSects; n++)
//	{
//		t[n].i1 = 0;
//		t[n].i2 = n + 1;
//		t[n].i3 = n == nSects - 1 ? 1 : n + 2;
//
//		t[nTria - nSects + n].i1 = nVert - 2 - ((1 + n) % nSects);
//		t[nTria - nSects + n].i2 = nVert - 1;
//		t[nTria - nSects + n].i3 = nVert - 2 - n;
//	}
//
//	// Generate triangles for the rings
//	int k = 1;		// first vertex in first ring,begins at 1 to skip top point
//	n = nSects;		// triangle being generated, skip the top cap
//	for (uint i = 0; i < nRings; i++, k += nSects)
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
//void Recalc()
//{
//	nVert = (nRings + 1) * nSects + 2;
//	nTria = 2 * (nRings + 1) * nSects; 	// Each quad has 2 triangles
//
//	VERT *Vert = new VERT[nVert];
//	TRIA *Tria = new TRIA[nTria];
//
//	Sphere(Vert, Tria);
//
//	glVertexPointer(3, GL_FLOAT, sizeof(VERT), &Vert->v);
//	glNormalPointer(GL_FLOAT, sizeof(VERT), &Vert->n);
//	glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(VERT), &Vert->c);
//
//	glNewList(1, GL_COMPILE);
//	glDrawElements(GL_TRIANGLES, nTria * 3, GL_UNSIGNED_INT, Tria);
//	glEndList();
//	delete[] Vert;
//	delete[] Tria;
//}
//
//void Print(float x, float y, char *format, ...)
//{
//	va_list args;
//	char buffer[200];
//	va_start(args, format);
//	vsprintf(buffer, format, args);
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
//
//	Print(80, 200, "Light is: %s", buf);
//	Print(80, 60, "Coordinates: (%3.1f, %3.1f, %3.1f)", pos[0], pos[1], pos[2]);
//	glMatrixMode(GL_PROJECTION);
//	glPopMatrix();
//	glMatrixMode(GL_MODELVIEW);
//	glPopAttrib();
//}
//
//void OnPaint()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPushMatrix();
//
//	DrawInfo();
//
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
//	glTranslated(dx, dy, dz);
//	glMultMatrixf(rotMatrix);
//
//	glCallList(1);
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
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
//void OnKey(byte ch, int x, int y)
//{
//	switch (ch)
//	{
//	case 'h': if (shine > 2) shine--; break;
//	case 'H': if (shine < 128) shine++; break;
//	case '+': pos[0] += 0.4f; break;
//	case '-': pos[0] -= 0.4f; break;
//	case 'f': glShadeModel(((flat = !flat) ? GL_FLAT : GL_SMOOTH)); break;
//	case 'p': pos[3] = 1; strcpy_s(buf, "Positional"); break;
//	case 'd': pos[3] = 0; strcpy_s(buf, "Directional"); break;
//	case 27: exit(0); break;
//	}
//	glMaterialf(GL_FRONT, GL_SHININESS, shine);
//	glutPostRedisplay();
//}
//
//void OnSpecialKey(int key, int x, int y)
//{
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
//	case GLUT_KEY_LEFT:
//		if (nSects > 30)
//			nSects -= 15;
//		else if (nSects > 2)
//			nSects--;
//		break;
//	case GLUT_KEY_RIGHT:
//		if (nSects > 30)
//			nSects += 15;
//		else
//			nSects++;
//		break;
//	default: return;
//	}
//	Recalc();
//	glutPostRedisplay();
//}
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
//void OnSize(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (double)w / h, 0.1, 100);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void Init()
//{
//	strcpy_s(buf, "Directional");
//	glClearColor(0, 0, 0, 0);
//
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_CULL_FACE);
//	glShadeModel(flat ? GL_FLAT : GL_SMOOTH);
//	
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
//	glMaterialf(GL_FRONT, GL_SHININESS, shine);
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glEnableClientState(GL_NORMAL_ARRAY);
//	glEnableClientState(GL_COLOR_ARRAY);
//
//	Recalc();
//}
//
//void main()
//{
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 800);
//	glutCreateWindow("Arrows, d, p, +, -, f");
//
//	Init();
//
//	glutIdleFunc(OnPaint);
//
//	glutMouseFunc(OnMouse);
//	glutMotionFunc(OnMouseMove);
//	glutKeyboardFunc(OnKey);
//	glutSpecialFunc(OnSpecialKey);
//	glutReshapeFunc(OnSize);
//	glutDisplayFunc(OnPaint);
//	glutMainLoop();
//}
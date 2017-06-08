//// GL.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
//
//float
//rotX, rotY,
//dx, dy, dz = -4,
//r = (1 + sqrt(5)) / 2, // Golden ratio
//v[12][3] =		// 12 vertices (x,y,z)
//{
//	0, 1, r, 0, -1, r, 0, 1, -r, 0, -1, -r,
//	1, r, 0, -1, r, 0, 1, -r, 0, -1, -r, 0,
//	r, 0, 1, -r, 0, 1, r, 0, -1, -r, 0, -1
//},
//rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
//color[] = { 0.1f, 0.6f, 0.1f },
//maxLight[] = { 1, 1, 1 }; // трехмерный вектор, определяющий максимально белый цвет света GL_SPECULAR
//
//	int id[20][3] =	// 20 triangular faces
//	{
//		0, 1, 8, 0, 9, 1, 0, 8, 4, 0, 4, 5, 0, 5, 9,
//		2, 3, 11, 2, 11, 5, 2, 5, 4, 2, 4, 10, 2, 10, 3,
//		1, 9, 7, 1, 7, 6, 1, 6, 8, 3, 10, 6, 3, 6, 7,
//		3, 7, 11, 4, 8, 10, 5, 11, 9, 6, 10, 8, 7, 9, 11
//	};
//
//	short posX, posY;
//	bool leftButton, flat, twoSide, showNorm;
//	int depth;
//	static bool bGrow = true; 	// Флаг определяющий знак приращения
//
//
//
//	void ToUnit(float v[3])// Нормируем вектор. используется как для масштабирования нормали, так и для нормировки координат вершин новых треугольников
//	{
//		float d = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
//		if (d == 0)
//		{
//			MessageBox(0, "Zero length vector", "Error", MB_OK);
//			return;
//		}
//		v[0] /= d; v[1] /= d; v[2] /= d;
//	}
//
//	void GetNorm(float a[3], float b[3], float n[3])
//	{
//		// Вычисляем координаты вектора нормали по формулам векторного произведения
//		n[0] = a[1] * b[2] - a[2] * b[1];
//		n[1] = a[2] * b[0] - a[0] * b[2];
//		n[2] = a[0] * b[1] - a[1] * b[0];
//		ToUnit(n);
//	}
//
//	void Scale(float v[3], float res[3], float d)
//	{
//		res[0] = v[0] * d; 
//		res[1] = v[1] * d; 
//		res[2] = v[2] * d;
//	}
//
//	void DrawTriaFlat(float* v1, float* v2, float* v3)// икосаэдр с четкоопределенными ребрами
//	{
//		glEnable(GL_LIGHTING); // без этого ничего не видно. "Рубильник в подвале"
//		float norm[3], a[3], b[3];
//		for (int i = 0; i< 3; i++)// Векторы a и b – это стороны треугольника
//		{
//			a[i] = v3[i] - v2[i];
//			b[i] = v1[i] - v2[i];
//		}
//		GetNorm(a, b, norm);	// Вычисляем нормаль и создаем треугольник
//
//		glColor3fv(color);
//		glBegin(GL_TRIANGLES);
//		glNormal3fv(norm);
//		glVertex3fv(v1);
//		glVertex3fv(v2);
//		glVertex3fv(v3);
//		glEnd();
//
//		if (showNorm)
//				{
//					glDisable(GL_LIGHTING);
//					glColor3f(1,1,0);
//					Scale(norm, norm, 1.5);
//					glBegin(GL_LINES);
//						glVertex3f(0, 0, 0);
//						glVertex3fv(norm);
//					glEnd();
//					glFlush();
//				}
//	}
//
//	void DrawTriaSmooth(float* v1, float* v2, float* v3)//функцию отображения одного треугольника с мягкой (неправильной) нормалью. (ребра задымлены)
//	{
//		glEnable(GL_LIGHTING); // без этого ничего не видно. "Рубильник в подвале"
//		glColor3fv(color);
//		glBegin(GL_TRIANGLES);
//		glNormal3fv(v1);		glVertex3fv(v1);
//		glNormal3fv(v2);		glVertex3fv(v2);
//		glNormal3fv(v3);		glVertex3fv(v3);
//		glEnd();
//
//
//		if (showNorm)
//				{
//					glDisable(GL_LIGHTING);
//					glColor3f(1,1,0);
//					glBegin(GL_LINE_STRIP);
//					glVertex3f(0, 0, 0);
//					float n1[3], n2[3], n3[3];
//					Scale(v1, n1, 1.5);
//					Scale(v2, n2, 1.5);
//					Scale(v3, n3, 1.5);
//					glVertex3f(0, 0, 0);
//					glVertex3fv(n1);
//					glVertex3fv(n2);
//					glVertex3fv(n3);
//					glVertex3fv(n1);
//					glEnd();
//				}
//	}
//
//	void DrawRecursive(float *v1, float *v2, float *v3, int depth)
//	{
//		float v12[3], v23[3], v31[3];
//		if (depth == 0)
//		{
//			if (flat)
//				DrawTriaFlat(v1, v2, v3);
//			else
//				DrawTriaSmooth(v1, v2, v3);
//			return;
//		}
//
//		for (int i = 0; i < 3; i++)
//		{
//			v12[i] = v1[i] + v2[i];
//			v23[i] = v2[i] + v3[i];
//			v31[i] = v3[i] + v1[i];
//		}
//
//		ToUnit(v12);	ToUnit(v23);	ToUnit(v31);
//		DrawRecursive(v1, v12, v31, depth - 1);
//		DrawRecursive(v2, v23, v12, depth - 1);
//		DrawRecursive(v3, v31, v23, depth - 1);
//		DrawRecursive(v12, v23, v31, depth - 1);
//	}
//
//	void DrawScene()
//	{
//		glNewList(1, GL_COMPILE);
//		glColor3fv(color);
//		glBegin(GL_TRIANGLES);
//
//		for (int i = 0; i < 20; i++)
//			DrawRecursive(v[id[i][0]], v[id[i][1]], v[id[i][2]], depth);
//
//		glEnd();
//		glEndList();
//	}
//
//
//void OnPaint()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(dx, dy, dz);
//	//glRotatef(ay, 0, 1, 0);
//	//glRotatef(ax, 1, 0, 0);
//	glMultMatrixf(rotMatrix);// Вместоповоротовумножаемнаматрицу, вобравшую все вращения
//
//	glCallList(1);	// проиграет список команд, среди которых главную роль играют команды вида glVertex3f(x, y, z)
//
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
//
//void OnSize(int w, int h)	// Реакция на WM_SIZE
//{
//	glViewport(0, 0, w, h);// Задаем видовой порт окна (вся клиентская область)
//	glMatrixMode(GL_PROJECTION); //определяет в качестве текущей матрицу моделирования
//	glLoadIdentity();//загружает в нее матрицу с единицами на диагонали
//	gluPerspective(45, double(w) / h, 0.1, 100); // угол, боковые грани(дисбаланс), передняя и задняя грани
//
//
//}
//void Init()	// Настройки
//{
//	float d = sqrt(1 + r * r);
//	for (int i = 0; i < 12; i++)
//	{
//		for (int j = 0; j < 3; j++)
//			v[i][j] /= d;
//	}
//
//	glClearColor(1, 1, 1, 0);	// Цвет фона - белый
//	glShadeModel(GL_SMOOTH);
//	glEnable(GL_DEPTH_TEST); // часть фигуры, видная глазу
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
//
//	glMaterialfv(GL_FRONT, GL_SPECULAR, maxLight); // чтобы сделать сферу блестящей
//	glMateriali(GL_FRONT, GL_SHININESS, 128);
//
//
//	glEnable(GL_LIGHTING);	// "Рубильник в подвале"
//	glEnable(GL_LIGHT0);		// Источник света, размещенный в точке z = ∞
//
//	glLineWidth(3);
//
//	int nLights;
//	glGetIntegerv(GL_MAX_LIGHTS, &nLights);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_NORMALIZE);
//	DrawScene();
//}
//
//
//
//
//
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
//	case 'n': flat = !flat; break;
//	case ' ': depth += bGrow ? 1 : -1;
//		if (!depth || depth == 4)
//			bGrow = !bGrow;
//		break;
//	case 'm': showNorm = !showNorm; break;
//	}
//	DrawScene();
//	glutPostRedisplay();
//}
//
//void OnSpecialKey(int key, int x, int y)
//{
//	float delta = -0.005 * dz;
//	switch (key)
//	{
//	case GLUT_KEY_LEFT: dx -= delta; break;
//	case GLUT_KEY_RIGHT: dx += delta; break;
//	case GLUT_KEY_DOWN: dy -= delta; break;
//	case GLUT_KEY_UP:  dy += delta; break;
//	}
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
//	glutInitWindowSize(500, 500);
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

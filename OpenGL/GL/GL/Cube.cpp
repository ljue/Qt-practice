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
//bool leftButton, twoSide, culling;;// Нажата левая кнопка мыши. Свет отражается от обеих поверхностей (лицевой и обратной)
//
//float v[8][3] = { -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1 };
//float norm[6][3] = { 0, 0, -1, 0, 0, 1, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1, 0 };
//int id[6][4] =//порядок выбора вершин
//{
//	0, 1, 2, 3,	// Rear (CCW - counterclockwise)
//	4, 5, 6, 7,	// Front
//	0, 3, 5, 4,	// Left
//	7, 6, 2, 1,	// Right
//	0, 4, 7, 1,	// Top
//	5, 3, 2, 6,	// Bottom
//};
//
//float
//rotX, rotY,	// Скорости поворота
//rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };// Матрица, суммирующая малые вращения
//
////void OnPaint()
////{
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////	glMatrixMode(GL_MODELVIEW);	// Будем пользоваться услугами MM
////	glLoadIdentity();
////	glTranslatef(dx, dy, dz);// Смещение координат точек будущих примитивов
////	glRotatef(ay, 0, 1, 0);	// Вращение координат точек примитивов
////	glRotatef(ax, 1, 0, 0);
////
////	glColor3fv(color);
////	glBegin(GL_QUADS);		// Выбор типа примитива
////	for (int i = 0; i< 6; i++)	// Долгоготовились - быстрорисуем
////	{
////		glNormal3fv(norm[i]);
////		for (int j = 0; j < 4; j++)
////			glVertex3fv(v[id[i][j]]);
////	}
////	glEnd();
////	glutSwapBuffers();// Быстрое переключение является причиной отсутствия мельканий. буфер видеопамяти
////}
//
//
//void DrawScene()
//{
//	glNewList(1, GL_COMPILE);	// Создаем новый список команд OpenGL
//	glColor3fv(color);
//	glBegin(GL_QUADS);
//	for (int i = 0; i < 6; i++)
//	{
//		glNormal3fv(norm[i]);
//		for (int j = 0; j < 4; j++)
//			glVertex3fv(v[id[i][j]]);
//	}
//	glEnd();
//	glEndList();
//}
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
//	glMatrixMode(GL_MODELVIEW);
//  glLoadIdentity();
//
//}
//void Init()	// Настройки
//{
//	glClearColor(1, 1, 1, 0);	// Цвет фона - белый
//	glShadeModel(GL_SMOOTH);
//	glEnable(GL_DEPTH_TEST); // часть фигуры, видная глазу
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
//
//	glEnable(GL_LIGHTING);	// "Рубильник в подвале"
//	glEnable(GL_LIGHT0);		// Источник света, размещенный в точке z = ∞
//
//	int nLights;
//	glGetIntegerv(GL_MAX_LIGHTS, &nLights);
//	glEnable(GL_COLOR_MATERIAL);
//
//	DrawScene();
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
//	}
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
//

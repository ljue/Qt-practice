//// GL.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
//
//float
//rotX, rotY,
//dx, dy, dz = -15, az,	// az - угол поворота всего колеса
//rotMatrix[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
//R = 4, 		// Радиус тора
//r = 0.4f, 	// Радиус сечения тора
//radius = R + r,// Внешний радиусколеса
//rn = 0.3, // Радиусгайки
//ToRad = acos(-1.0f) / 180,
//coeff = R * ToRad;// Коэффициент перевода в радианы
//short posX, posY;
//bool leftButton, twoSide;
//
//void DrawNut()// Рисуем одну (шестигранную) гайку
//{
//	float
//		x = rn * 0.5f,			// rn * cos(60)
//		y = rn * sqrt(3.0f) / 2;	// rn * sin(60)
//	glBegin(GL_LINE_LOOP);
//	glVertex2f(rn, 0); glVertex2f(x, y); glVertex2f(-x, y);
//	glVertex2f(-rn, 0); glVertex2f(-x, -y); glVertex2f(x, -y);
//	glEnd();
//}
//
//void DrawScene()
//{
//	glNewList(1, GL_COMPILE);
//	glPushMatrix();// Запоминаем единичное состояние MM
//
//	// Здесь должен быть ваш код, который заставит колесо катиться вдоль линии
//	glTranslatef(az*coeff, 0, 0);
//	glRotatef(-az, 0, 0, 1);
//
//
//	glColor3f(0, 0, 1);
//	glutSolidTorus(0.1, 0.8, 16, 16);// Внутренний диск колеса
//	glColor3f(1, 0, 0);
//	glutSolidTorus(r, R, 32, 32);  // Самоколесо (шина)
//	glColor3f(0, 0, 0);
//	for (int i = 0; i < 5; i++) // Пятьгаек
//	{
//		glPushMatrix();
//		glRotatef(72 * i, 0, 0, 1); // Поворотвокругцентра
//		glTranslatef(2.5f, 0, 0);   // Сдвиготцентра
//		DrawNut();
//		glPopMatrix();
//	}
//
//	// Здесь код работы со стеком,который заставит колесо катиться вдоль линии
//
//	glPopMatrix();
//	glPushMatrix();
//
//
//	glBegin(GL_LINES);// Линия, вдоль которой будет катиться колесо
//	glVertex3f(-100 * radius, -radius, 0);
//	glVertex3f(100 * radius, -radius, 0);
//	glEnd();
//	glPopMatrix();
//	glEndList();
//}
//
//
//void OnPaint()  //  осуществляется сдвиг и вращение всей сцены OpenGL
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glPushMatrix();
//	glTranslatef(dx, dy, dz);
//	glMultMatrixf(rotMatrix);
//
//	glCallList(1);
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
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
//
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
//	case 'a': az -= 1;
//		break;
//	case 's': az += 1;
//		break;
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
//

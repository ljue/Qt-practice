//// GL.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
//
//
//float sun, year, day, moon;		// Углы вращения
//
//
//
//float
//ax=30, ay=45,// Углы поворота изображения вокруг осей X и Y
//dx, dy, dz = -6,// Сдвиги вдоль координат
//color[] = { 0.1f, 0.6f, 0.1f };
//short posX, posY;// Текущая позиция указателя мыши
//bool leftButton, twoSide, culling;// Нажата левая кнопка мыши. Свет отражается от обеих поверхностей (лицевой и обратной)
//
//float
//SunDif[] = { 0.5f, 0.5f, 0 }, 
//SunEmis[] = { 0.6f, 0.6f, 0.0f }, //цвет собственного излучения материала
//EarthDif[] = { 0.2f, 0.4f, 1.0f }, 
//MoonDif[] = { 0.4f, 0.4f, 0 }, 
//EmisOff[] = { 0,0,0 }, 
//
//diff[] = { 0.7f, 0.7f, 0.7f }, 
//spec[] = { 1.0f, 1.0f, 1.0f },
//
//pos[] = { 0, 0, dz, 1 },// источник света - центр солнца. Positional
//pos1[] = { 0.5, 0.5, 1, 0}; // рассеянный свет.  Directional 
//int shine = 5; // блесткость материала
//
//float
//rotX, rotY,	// Скорости поворота
//rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };// Матрица, суммирующая малые вращения
//
//
//void DrawScene()
//{
//	glNewList(1, GL_COMPILE);	// Создаем новый список команд OpenGL
//	
//	glPushMatrix();	// Запоминаем единичное значение ММ в стеке
//	glPushMatrix();
//
//	glRotatef(sun, 1, 1, 1);	// Вращаем систему координат
//
//	glMultMatrixf(rotMatrix);
//	
//	glMaterialfv(GL_FRONT, GL_EMISSION, SunDif);
//	glMaterialfv(GL_FRONT, GL_EMISSION, SunEmis);
//	glutSolidSphere(1, 32, 32);	// Рисуем Солнце
//	glMaterialfv(GL_FRONT, GL_EMISSION, EmisOff);
//	
//	glPopMatrix();
//	
//	glRotatef(year, 0, 1, 0);	// Вращаем систему координат
//	glTranslatef(2, 0, 0);	// Смещаем вправо (Землю)
//
//	glMultMatrixf(rotMatrix);
//
//	glPushMatrix();
//
//	glRotatef(day, 0, 0, 1);	// Вращаем в смещенной системе
//
//	glMultMatrixf(rotMatrix);
//
//	glMaterialfv(GL_FRONT, GL_EMISSION, EarthDif);
//	glutSolidSphere(0.3, 32, 32);	// Рисуем Землю
// 
//	glPopMatrix();
//
//	glRotatef(moon, 1, 0, 0);	// Вращаем систему координат
//	glTranslatef(0, 0.45, 0);		// Смещаем вверх (луну)
//
//	glMultMatrixf(rotMatrix);
//
//	glMaterialfv(GL_FRONT, GL_EMISSION, MoonDif);
//	glutSolidSphere(0.08, 32, 32);  // Рисуем Луну
//	
//	glPopMatrix();		// Восстанавливаем единичное значение из стека
//
//
//	glEndList();
//}
//
//
//void OnPaint()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glPushMatrix();
//	glTranslated(dx, dy, dz);
//	glMultMatrixf(rotMatrix);
//
//	glCallList(1);
//
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
//	glMatrixMode(GL_MODELVIEW);
//  glLoadIdentity();
//
//}
//void Init()	// Настройки
//{
//	glClearColor(0, 0, 0, 0);	// Цвет фона - черный
//
//	glShadeModel(GL_FLAT);
//	glEnable(GL_DEPTH_TEST); // часть фигуры, видная глазу
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
//	glEnable(GL_CULL_FACE);
//
//	glEnable(GL_LIGHTING);	// "Рубильник в подвале"
//
//	glEnable(GL_LIGHT0);		// Источник света, размещенный в точке z = ∞
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
//
//	glEnable(GL_LIGHT1);
//	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, diff); // сила предыдущего вектора
//
//	
//	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
//
//	glMateriali(GL_FRONT, GL_SHININESS, shine);
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
//	{
//		pos[2] = dz;
//		glLightfv(GL_LIGHT0, GL_POSITION, pos);
//		dz += (rotX + rotY) / 60;
//	}		
//	posX = x;
//	posY = y;
//	//DrawScene();
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
//	case 'y': year += 2; break;
//	case 'd': day += 2; break;
//	case 's': sun += 2; break;
//	case 'm': moon += 2; break;
//	case 'h': shine++; glMateriali(GL_FRONT, GL_SHININESS, shine); break;
//	case 'g': shine--; glMateriali(GL_FRONT, GL_SHININESS, shine); break;	
//	case 'a': year += 2; day += 2; sun += 2; moon += 2; break;
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
//	pos[0] = dx;
//	pos[1] = dy;
//	glLightfv(GL_LIGHT0, GL_POSITION, pos);
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

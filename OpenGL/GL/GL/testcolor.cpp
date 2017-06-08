////// GL.cpp: определяет точку входа для консольного приложения.
//////
////
#include "stdafx.h"
//
////double eyeX, eyeY, eyeZ = 3;
////float
////zSphere = 1, zCube = -1, // Индексы списков команд изображений
////delta = 0.0008f,
////difs[] = { 0.7f, 0.7f, 0, 1 },
////difc[] = { 0, 0.8f, 0.8f, 0.6f },
////zero[] = { 0, 0, 0 },
////emic[] = { 0, 0.3f, 0.3f, 0.6f },
////pos[] = { 0.5f, 0.5f, 1, 0 },
////spec[] = { 1, 1, 1 };
////uint sphere, cube, shine = 40;
////bool moving, culling, emission, mask, flat;
////
////void OnPaint()
////{
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////	glPushMatrix();
////	gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0);
////	glPushMatrix();
////	glTranslatef(-0.05, 0, zSphere);
////	glMaterialfv(GL_FRONT, GL_DIFFUSE, difs);
////	glMaterialfv(GL_FRONT, GL_EMISSION, zero);
////	glCallList(sphere);
////	glPopMatrix();
////
////	glPushMatrix();
////	glTranslatef(0, 0, zCube);
////	glRotatef(15, 1, 1, 0);
////	glRotatef(30, 0, 1, 0);
////	glMaterialfv(GL_FRONT, GL_DIFFUSE, difc);
////	if (emission)
////		glMaterialfv(GL_FRONT, GL_EMISSION, emic);
////	glEnable(GL_BLEND);
////	if (mask)
////		glDepthMask(FALSE);
////	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
////	glCallList(cube);
////	if (mask)
////		glDepthMask(TRUE);
////	glDisable(GL_BLEND);
////	glPopMatrix();
////	glPopMatrix();
////
////	glutSwapBuffers();
////}
////
////void Animate()
////{
////	static bool b = true;
////	zSphere += b ? -delta : delta;
////	zCube += b ? delta : -delta;
////	if (zSphere < -1 || 1 < zSphere)
////		b = !b;
////	glutPostRedisplay();
////}
////
////void OnSize(int w, int h)
////{
////	glViewport(0, 0, w, h);
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////
////	gluPerspective(35, double(w) / double(h), 0.1, 100);
////	glMatrixMode(GL_MODELVIEW);
////	glLoadIdentity();
////}
////void OnSpecialKey(int key, int x, int y)
////{
////	switch (key)
////	{
////	case GLUT_KEY_LEFT: eyeX -= 0.1; break;
////	case GLUT_KEY_RIGHT: eyeX += 0.1; break;
////	case GLUT_KEY_DOWN: eyeY -= 0.1; break;
////	case GLUT_KEY_UP:  eyeY += 0.1; break;
////	}
////	glutPostRedisplay();
////}
////void OnKey(byte ch, int x, int y)
////{
////	switch (ch)
////	{
////	case 'f': glShadeModel(((flat = !flat) ? GL_FLAT : GL_SMOOTH)); break;
////	case '+': if (difc[3] < 1) difc[3] += 0.05f; break;
////	case '-': if (difc[3] > 0.1) difc[3] -= 0.05f; break;
////	case 'h': if (shine > 2) shine--; break;
////	case 'H': if (shine < 128) shine++; break;
////	case 'm': mask = !mask; cout << "Mask: " << mask << endl; break;
////	case 'e': emission = !emission; break;
////	case ' ':  moving = !moving; glutIdleFunc((moving ? Animate : 0)); break;
////	case 'c': culling = !culling;
////		if (culling)
////			glEnable(GL_CULL_FACE);
////		else
////			glDisable(GL_CULL_FACE);
////		break;
////	case 's':
////		moving = false;
////		zSphere = 1;
////		zCube = -1;
////		glutIdleFunc(0);
////		break;
////	case 27: exit(0); break;
////	}
////	glMateriali(GL_FRONT, GL_SHININESS, shine);
////	glutPostRedisplay();
////}
////
////void Init()
////{
////	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
////	glMateriali(GL_FRONT, GL_SHININESS, shine);
////	glLightfv(GL_LIGHT0, GL_POSITION, pos);
////
////	glShadeModel(flat);
////	glEnable(GL_LIGHTING);
////	glEnable(GL_LIGHT0);
////	glEnable(GL_DEPTH_TEST);
////	sphere = glGenLists(1);
////	glNewList(sphere, GL_COMPILE);
////	glutSolidSphere(0.35, 32, 32);
////	glEndList();
////
////	cube = glGenLists(1);
////	glNewList(cube, GL_COMPILE);
////	glutSolidCube(0.8);
////	glEndList();
////}
//
//float
//dens, a = 2, b = 12,
//eyeX, eyeY, eyeZ = 8,
//amb[] = { 0.17450, 0.01175, 0.01175 },
//dif[] = { 0.61424, 0.04136, 0.04136 },
//spec[] = { 0.727811, 0.626959, 0.626959 },
//clr[] = { 0.5, 0.5, 0.5 },
//pos0[] = { 10, 3, 3, 0 },
//x[] = { -1, 0, 1 },
//y[] = { 1, 0, -1 },
//z[] = { 0, -2, -4 },
//shine = 128;
//int mode = GL_EXP2;
//bool flat;
//
//void OnPaint()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPushMatrix();
//	gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0);
//
//	for (uint i = 0; i < 3; i++)
//	{
//		glPushMatrix();
//		glTranslatef(x[i], y[i], z[i]);
//		glCallList(1);
//		glPopMatrix();
//	}
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void RedTeapot()
//{
//	glNewList(1, GL_COMPILE);
//	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
//	glMaterialf(GL_FRONT, GL_SHININESS, shine);
//	glutSolidTeapot(1.0);
//	glEndList();
//}
//
//void SwitchFog()
//{
//	switch (mode)
//	{
//	case GL_EXP: mode = GL_EXP2; cout << "\nFog mode is GL_EXP2"; break;
//	case GL_EXP2: mode = GL_LINEAR; cout << "\nFog mode is GL_LINEAR"; break;
//	case GL_LINEAR: mode = GL_EXP; cout << "\nFog mode is GL_EXP"; break;
//	}
//	glFogi(GL_FOG_MODE, mode);
//}
//
//void OnKey(byte ch, int x, int y)
//{
//	static bool bGrow = true;
//	switch (ch)
//	{
//	case 'A': if (b - a > 0.2) a += 0.1; break;
//	case 'a': a -= 0.1; break;
//	case 'B': b += 0.1; break;
//	case 'b': if (b - a > 0.2) b -= 0.1; break;
//	case 'f': glShadeModel(((flat = !flat) ? GL_FLAT : GL_SMOOTH)); break;
//	case 'm': SwitchFog(); break;
//	case ' ':
//		if (mode == GL_LINEAR)
//		{
//			cout << "\nFog Density doesn't work in a linear mode";
//			break;
//		}
//		dens += bGrow ? 0.05f : -0.05f;
//		if (fabs(dens) < 0.01 || dens > 0.4)
//			bGrow = !bGrow;
//		glFogf(GL_FOG_DENSITY, dens);
//		cout << "\nFog Density: " << dens;
//		break;
//	case 27: exit(0); break;
//	}
//	glFogf(GL_FOG_START, a);
//	glFogf(GL_FOG_END, b);
//	glutPostRedisplay();
//}
//
//void OnSpecialKey(int key, int x, int y)
//{
//	switch (key)
//	{
//	case GLUT_KEY_LEFT: eyeX -= 1; break;
//	case GLUT_KEY_RIGHT: eyeX += 1; break;
//	case GLUT_KEY_DOWN: eyeY -= 1; break;
//	case GLUT_KEY_UP:  eyeY += 1; break;
//	}
//	glutPostRedisplay();
//}
//
//void OnSize(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(30, double(w) / h, 1, 40);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void Init()
//{
//	glClearColor(0.5, 0.5, 0.5, 1);
//	glShadeModel((flat ? GL_FLAT : GL_SMOOTH));
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_AUTO_NORMAL);
//	glEnable(GL_NORMALIZE);
//	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
//	RedTeapot();
//	glEnable(GL_FOG);
//	glFogfv(GL_FOG_COLOR, clr);
//	glFogf(GL_FOG_DENSITY, dens);
//	glHint(GL_FOG_HINT, GL_DONT_CARE);
//	glFogf(GL_FOG_START, a);
//	glFogf(GL_FOG_END, b);
//	SwitchFog();
//}
//
//
//void main()
//{
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(900, 700);
//	//glutCreateWindow("Space, Arrows, s, c, m, e, H,h, +, -");
//	glutCreateWindow("Space, Arrows, A, a, m, f, B, b");
//
//	Init();
//
//	glutKeyboardFunc(OnKey);
//	glutSpecialFunc(OnSpecialKey);
//	glutReshapeFunc(OnSize);
//	glutDisplayFunc(OnPaint);
//	glutMainLoop();
//}
//

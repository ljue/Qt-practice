//// GL.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
//
//const float PI = acos(-1.), ToRad = PI / 180;
//float
//speed = 0.1, dist = 14,
//spec[] = { 1, 1, 1 },
//pos0[] = { -3, 3, 3, 0 },
//pos1[] = { 3, 3, -3, 0 },
//amb[] = { 0.3f, 0.3f, 0.3f };
//
//
//
//class Point3D
//{
//public:
//	float x, y, z;
//
//	Point3D() { x = y = z = 0.; }
//	Point3D(float xx, float yy, float zz) { x = xx; y = yy; z = zz; }
//	Point3D(float v[3]) { x = v[0]; y = v[1]; z = v[2]; }
//	Point3D operator+ (Point3D& p) { return Point3D(x + p.x, y + p.y, z + p.z); }
//	Point3D operator- (Point3D& p) { return Point3D(x - p.x, y - p.y, z - p.z); }
//	void operator+= (Point3D& p) { x += p.x;	y += p.y;	z += p.z; }
//	void operator-= (Point3D& p) { x -= p.x;	y -= p.y;	z -= p.z; }
//	float operator! () { return sqrt(x*x + y*y + z*z); }
//	Point3D operator* (float d) { return Point3D(x*d, y*d, z*d); }
//	Point3D operator* (Point3D& p) { return Point3D(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x); }
//	void operator*= (float d) { x *= d; y *= d, z *= d; }
//	Point3D ToUnit() { float r = !*this; return Point3D(x / r, y / r, z / r); }
//	float Dist(Point3D& p) { return !Point3D(*this - p); }
//
//	/*Point3D& Rotate(Point3D& p, float a)
//	{
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		glRotatef(a, p.x, p.y, p.z);
//		float mm[16], t[3] = { x, y, z }, v[3];
//		glGetFloatv(GL_MODELVIEW_MATRIX, mm);
//		for (int i = 0; i < 3; i++)
//		{
//			v[i] = 0.;
//			for (int j = 0; j < 3; j++)
//				v[i] += mm[(i << 2) + j] * t[j];
//		}
//		x = v[0];	y = v[1];	z = v[2];
//		return *this;
//	}*/
//	Point3D &Rotate(Point3D& p, float a)
//	{
//		a *= ToRad;
//		p.ToUnit();
//		float
//			ca = cos(a),
//			sa = sin(a),
//			c = 1 - cos(a),
//			xs = p.x * sa,
//			ys = p.y * sa,
//			zs = p.z * sa,
//			xy = p.x * p.y * c,
//			xz = p.x * p.z * c,
//			yz = p.y * p.z * c,
//
//			xn = (p.x * p.x * c + ca) * x + (xy - zs) * y + (xz + ys) * z,
//			yn = (xy + zs) * x + (p.y * p.y * c + ca) * y + (yz - xs) * z,
//			zn = (xz - ys) * x + (yz + xs) * y + (p.z * p.z * c + ca) * z;
//		x = xn;  y = yn;  z = zn;
//		return *this;
//	}
//
//};
//
//Point3D	eye(0, 1.5, dist), center(0, 1.5, 0), up(0, 1, 0);
//
//void DrawPoints()
//{
//	srand(time(0));
//	glPointSize(5);
//	glDisable(GL_LIGHTING); //выключение света необходимо для того, чтобы точки всегда были белыми и не отражали свет. 
//	glColor3f(1, 1, 1);
//	glBegin(GL_POINTS);
//	for (int i = 0; i < 150; i++)
//	{
//		int
//			x = rand() % 60 - 30,
//			y = rand() % 30,
//			z = rand() % 200 - 100;
//		glVertex3f(x, y, z);
//		glVertex3f(x, -y, z);
//	}
//	glEnd();
//	glEnable(GL_LIGHTING);
//}
//
//void DrawPlane()
//{
//	glColor3f(0, 0.5, 0);
//	glBegin(GL_QUADS);
//	glNormal3f(0, 1, 0);
//	glVertex3f(-5, 0, 5); glVertex3f(5, 0, 5); glVertex3f(5, 0, -15); glVertex3f(-5, 0, -15);
//	glEnd();
//
//	glColor3f(1, 1, 1);
//	glDisable(GL_LIGHTING);
//	glLineWidth(2);
//	glBegin(GL_LINES);
//	for (float x = -4.4; x < 4.5; x += 0.4)
//	{
//		glVertex3f(x, 0.02, 5);
//		glVertex3f(x, 0.02, -15);
//	}
//	glEnd();
//	glEnable(GL_LIGHTING);
//}
//
//void DrawObjects()
//{
//	glColor3f(0.8, 0.6, 0.4);
//	glTranslatef(-3, 0.25, 0); glutSolidCube(0.5);
//	glTranslatef(0, 0, -5);    glutSolidCube(0.5);	// -3, 0.25, -5
//	glTranslatef(6, 0, 0);     glutSolidCube(0.5);	// 3, 0.25, -5
//	glTranslatef(0, 0, 5);     glutSolidCube(0.5);	// 3, 0.25, 0
//
//	glColor3f(0.4, 0.2, 0.1);
//	glTranslatef(0, 0.25, 0); glRotatef(-90, 1, 0, 0); glutSolidCone(0.28, 1, 16, 16); glRotatef(90, 1, 0, 0); 	// 3, 0.5, 0
//	glTranslatef(0, 0, -5);   glRotatef(-90, 1, 0, 0); glutSolidCone(0.28, 1, 16, 16); glRotatef(90, 1, 0, 0); // 3, 0.5, -5
//	glTranslatef(-6, 0, 0);   glRotatef(-90, 1, 0, 0); glutSolidCone(0.28, 1, 16, 16); glRotatef(90, 1, 0, 0); // -3, 0.5, -5 
//	glTranslatef(0, 0, 5);    glRotatef(-90, 1, 0, 0); glutSolidCone(0.28, 1, 16, 16); glRotatef(90, 1, 0, 0); // -3, 0.5, 0
//	glColor3f(0.6, 0, 0);
//	glTranslatef(0, -0.23, -9); glRotatef(-90, 1, 0, 0); glutSolidTorus(0.27, 0.8, 16, 16); glRotatef(90, 1, 0, 0);// -3,0.27, -14
//	glTranslatef(6, 0, 0);      glRotatef(-90, 1, 0, 0); glutSolidTorus(0.27, 0.8, 16, 16); glRotatef(90, 1, 0, 0);// 3,0.27,-14
//	glColor3f(0, 0.2, 1);
//
//}
//
//
//void DrawScene()
//{
//	glNewList(1, GL_COMPILE);
//	DrawPoints();
//	DrawPlane();
//	DrawObjects();
//	glEndList();
//}
//
//
//void OnPaint()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPushMatrix();
//	gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
//
//	glCallList(1);
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//
//void OnSize(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(35, float(w) / h, .1, 1000);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void Init()
//{
//	glClearColor(0, 0, 0, 0);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glEnable(GL_COLOR_MATERIAL);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
//	glMaterialf(GL_FRONT, GL_SHININESS, 128);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
//	glLightfv(GL_LIGHT0, GL_POSITION, pos0);
//	glLightfv(GL_LIGHT1, GL_POSITION, pos1);
//	DrawScene();
//}
//
//
//void OnIdle()
//{
//	//AddRotation(rotX / 200, 1, 0, 0);
//	//AddRotation(rotY / 200, 0, 1, 0);
//	glutPostRedisplay();
//}
//
//
//void Go(bool fwrd)
//{
//	Point3D pt((eye - center) * speed);
//	if (fwrd)
//	{
//		eye -= pt;
//		center -= pt;
//	}
//	else
//	{
//		eye += pt;
//		center += pt;
//	}
//}
//
//void Roll(float angle) { up.Rotate(center - eye, angle); }
//
//void Pitch(float angle)
//{
//	Point3D v = center - eye,
//		n = v*up;
//	center = eye + v.Rotate(n, angle);
//	up.Rotate(n, angle);
//}
//
//void Yaw(float angle)
//{
//	Point3D v = center - eye;
//	center = eye + v.Rotate(up, angle);
//}
//
//void OnKey(byte ch, int x, int y)
//{
//	switch (ch)
//	{
//	case '7': Roll(0.1);	break;
//	case '9': Roll(-0.1); break;
//	case '8': Pitch(0.1); break;
//	case '2': Pitch(-0.1); break;
//	case '4': Yaw(1); break;
//	case '6': Yaw(-1); break;
//	case '5': Go(true); break;
//	case '3': Go(false); break;
//	case '0':// Возврат в исходное состояние
//		eye = Point3D(0, 1.5, dist);
//		center = Point3D(0, 1.5, 0);
//		up = Point3D(0, 1, 0);
//		break;
//	case '1':// Помещаем глаз в симметричную позицию и поворачиваем его на 180 градусов
//		eye = Point3D(0, 1.5, -2 * dist);
//		center = Point3D(0, 1.5, 0);
//		up = Point3D(0, 1, 0);
//		break;
//	case 't':// Телепортируем глаз в удаленную позицию, чтобы оценить звездный кластер издалека
//		eye = Point3D(0, 1.5, 20 * dist);
//		center = Point3D(0, 1.5, 19 * dist);
//		up = Point3D(0, 1, 0);
//		break;
//	case ' ':
//		cout << "\nE = (" << eye.x << ", " << eye.y << ", " << eye.z << ')'
//			<< "\nC = (" << center.x << ", " << center.y << ", " << center.z << ')'
//			<< "\nU = (" << up.x << ", " << up.y << ", " << up.z << ")\n";
//		break;
//	case 27: exit(0); break;
//	}
//	glutPostRedisplay();
//}
//
//
//void OnSpecialKey(int key, int x, int y)
//{
//	Point3D pt;
//	switch (key)
//	{
//	case GLUT_KEY_LEFT: pt = Point3D(-0.1, 0, 0); break;
//	case GLUT_KEY_RIGHT: pt = Point3D(0.1, 0, 0); break;
//	case GLUT_KEY_DOWN: pt = Point3D(0, -0.1, 0); break;
//	case GLUT_KEY_UP: pt = Point3D(0, 0.1, 0); break;
//	}
//	eye += pt; center += pt;
//	glutPostRedisplay();
//}
//
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
//	//glutMouseFunc(OnMouse);
//	//glutMotionFunc(OnMouseMove);
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

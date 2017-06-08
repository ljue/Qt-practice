// GL.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#define Line(x1, y1, x2, y2) \
glBegin(GL_LINES);  \
glVertex2f((x1), (y1)); \
glVertex2f((x2), (y2)); \
glEnd();


float gx = 0.35f, gy = 0.58f, gw, gh;

void OnPaint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);			// �������� ������ ���� ���������

	glEnable(GL_LINE_STIPPLE);

	//======== � 1-� ���� ������ 3 ����� � ������ ���������� (stipple)
	glLineStipple(1, 0x0303);		// dot
	Line(.05, .1, .35, .1);
	glLineStipple(1, 0x00FF);		// dash
	Line(.35, .1, .65, .1);
	glLineStipple(1, 0x2727);		// dash/dot/dash
	Line(.65, .1, .95, .1);

	//======== �� 2-� ���� �� ��, �� ���� � 6 ���
	glLineWidth(6);
	glLineStipple(1, 0x0303);		// dot
	Line(.05, .2, .35, .2);
	glLineStipple(1, 0x00FF);		// dash
	Line(.35, .2, .65, .2);
	glLineStipple(1, 0x2727);		// dash/dot/dash
	Line(.65, .2, .95, .2);

	// � 3-� ���� 19 ����� �������� ������� ������ (strip). ��������� ���� �� �����������
	glLineStipple(2, 0x2727);

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 19; i++)
		glVertex2d(.05*(i + 1), .3);
	glEnd();

	// � 4-� ���� 18 �����������, ��������� �����.
	// ��� �� ����, �� �� ������ ��� ���������� ������
	for (int i = 0; i< 18; i++)
	{
		Line(0.05*(i + 1), .4, 0.05*(i + 2), .4);
	}
	//===== � 5-� ���� 1 ����� � ��� �� ������
	glLineStipple(6, 0x2727);
	Line(.05, .5, .95, .5);

	glDisable(GL_LINE_STIPPLE);
	glFlush();
}


void OnSize(int w, int h)	// ������� �� WM_SIZE
{
	glViewport(0, 0, w, h);		// ������ ������� ���� ���� (��� ���������� �������)
	glMatrixMode(GL_PROJECTION); //���������� � �������� ������� ������� �������������
	glLoadIdentity();//��������� � ��� ������� � ��������� �� ���������
	gluOrtho2D(0, 1, 0, 0.5);	// ����� ��������������� ��������
	gw = w;
	gh = h;
	glScissor((int)(gx * w), (int)(gy * h), (int)(0.3f * w), (int)(0.3f * h));

}
void Init()	// ���������
{
	glClearColor(1, 1, 1, 0);	// ���� ���� - �����
	glShadeModel(GL_FLAT);		// ��� ������������ ������ ��� ������������
	glPointSize(10);					// ������ ������ �����
	glEnable(GL_POINT_SMOOTH);		// ������ ������� ������ ��� �����
}
void OnSpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: gx -= 0.005f; break;
	case GLUT_KEY_RIGHT: gx += 0.005f; break;
	case GLUT_KEY_DOWN: gy -= 0.005f; break;
	case GLUT_KEY_UP:  gy += 0.005f; break;
	}
	glScissor((int)(gx * gw), (int)(gy * gh), (int)(0.3f * gw), (int)(0.3f * gh));
	glutPostRedisplay();
}

void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("");
	Init();
	glutSpecialFunc(OnSpecialKey);
	glutReshapeFunc(OnSize);
	glutDisplayFunc(OnPaint);
	glutMainLoop();
	//===����� ������ ��������� ���, ��� ��� ���������� �������� �������� ������ ����������� ������ ������� ��������� � ��������
}



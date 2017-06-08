// GL.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

void OnPaint()
{
	glClear(GL_COLOR_BUFFER_BIT);	// ������� ����� ����� framebuffer)
	glBegin(GL_QUADS);			// �������� ����� ������� �����
	glColor3f(1, 0, 0);		// �������� ���� ���������
	glVertex2f(-0.8, -0.8);
	glVertex2f(-0.8, 0.8);
	glColor3f(0, 0, 1);
	glVertex2f(0.8, 0.8);
	glVertex2f(0.8, -0.8);
	glEnd();
	glFlush();//������� ��������� ���������� �������
}

void OnSize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //���������� � �������� ������� ������� �������������
	glLoadIdentity(); //��������� � ��� ������� � ��������� �� ���������
	gluOrtho2D(-1, 1, -1, 1);	// ����� ��������������� ��������. ������� ������� ����������� ���������������� (�������������) ������������� � �������� �� ������ �� ��������� �������
}

void Init()	// ���������
{
	glClearColor(1, 1, 1, 0);	// ���� ���� - �����
	//glShadeModel(GL_FLAT);		// ��� ������������ ������ ��� ������������
	glPointSize(7);					// ������ ������ �����
	glEnable(GL_POINT_SMOOTH);		// ������ ������� ������ ��� �����
}
void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("");
	Init();
	glutReshapeFunc(OnSize);
	glutDisplayFunc(OnPaint);
	glutMainLoop();
	//===����� ������ ��������� ���, ��� ��� ���������� �������� �������� ������ ����������� ������ ������� ��������� � ��������
}


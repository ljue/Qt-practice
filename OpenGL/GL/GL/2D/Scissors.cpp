// GL.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

float gx = 0.35f, gy = 0.58f, gw, gh;

void OnPaint()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0, -0.2f);
	glVertex2f(0, -0.1f);
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0, 0.4f);
	glEnd();
	glEnable(GL_SCISSOR_TEST);// �������� �������
	glClearColor(0.9f, 0.8f, 0.7f, 0);// ������ ���� ����
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(0, 0, 1);
	glVertex2f(-0.2f, 0.2f);
	glVertex2f(0, 0.2f);
	glVertex2f(0, 0.1f);
	glVertex2f(0.2f, 0.2f);
	glVertex2f(0, -0.4f);
	glEnd();
	glDisable(GL_SCISSOR_TEST);// ��������� �������
	glutSwapBuffers();
	glFlush();
}

void OnSize(int w, int h)	// ������� �� WM_SIZE
{
	glViewport(0, 0, w, h);		// ������ ������� ���� ���� (��� ���������� �������)
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



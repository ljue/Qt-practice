// GL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void OnPaint()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Стираем буфер цвета framebuffer)
	glBegin(GL_QUADS);			// Включаем режим задания точек
	glColor3f(1, 0, 0);		// Выбираем цвет рисования
	glVertex2f(-0.8, -0.8);
	glVertex2f(-0.8, 0.8);
	glColor3f(0, 0, 1);
	glVertex2f(0.8, 0.8);
	glVertex2f(0.8, -0.8);
	glEnd();
	glFlush();//требует выполнить предыдущие команды
}

void OnSize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //определяет в качестве текущей матрицу проецирования
	glLoadIdentity(); //загружает в нее матрицу с единицами на диагонали
	gluOrtho2D(-1, 1, -1, 1);	// Режим ортографической проекции. создает матрицу двухмерного ортографического (параллельного) проецирования и умножает ее справа на единичную матрицу
}

void Init()	// Настройки
{
	glClearColor(1, 1, 1, 0);	// Цвет фона - белый
	//glShadeModel(GL_FLAT);		// Нет интерполяции цветов при растеризации
	glPointSize(7);					// Задаем размер точки
	glEnable(GL_POINT_SMOOTH);		// Задаем «мягкий» контур для точки
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
	//===Здесь нельзя размещать код, так как предыдущий оператор является псевдо бесконечным циклом выборки сообщений о событиях
}


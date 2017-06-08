// GL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BMPLoader.h"

float
rotX = 20, rotY = 30,
dx, dy, dz = -5,
v[8][3] = { -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1 },
norm[6][3] = { 0, 0, -1, 0, 0, 1, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1, 0 },
rotMatrix[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
green[] = { 0, 0.6, 0 },
white[] = { 0.9, 0.9, 0.9 },
sx, sy,
texX, texY, texZ;
//t[4][2] = { 0, 1, 0, 0, 1, 0, 1, 1 };

int
id[6][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 0, 3, 5, 4, 7, 6, 2, 1, 0, 4, 7, 1, 5, 3, 2, 6, },
posX, posY,
filter = GL_NEAREST,
wrap = GL_REPEAT;
bool leftButton, lighting, sphereMap, decal, colored, twoSide;
UINT texture;



//float
//ax=30, ay=45,// Углы поворота изображения вокруг осей X и Y



char* FileDlg()
{
	char *fn = new char[MAX_PATH], dir[MAX_PATH];
	fn[0] = 0;
	GetCurrentDirectory(MAX_PATH - 1, dir);
	OPENFILENAME ofn =
	{
		sizeof(OPENFILENAME), 0, 0, "BMP Files (*.bmp)\0*.bmp\0DIB Files (*.dib)\0*.dib\0", 0, 0, 1,
		fn, MAX_PATH, 0, 0, dir, "Find a bitmap file",
		OFN_EXPLORER | OFN_OVERWRITEPROMPT,
		0, 0, "bmp", 0, 0, 0, 0, 0, 0
	};
	return GetOpenFileName(&ofn) ? fn : 0;
}

bool LoadTexture(int id)
{
	char *fn = FileDlg();
	if (fn == 0)
		return false;
	BmpLoader* p = new BmpLoader(fn);
	if (!p)
		throw "Error reading texture.\n";
	glBindTexture(GL_TEXTURE_2D, id);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, p->sizeX, p->sizeY, GL_RGB, GL_UNSIGNED_BYTE, p->data);
	return true;
}

void SetLight()
{
	if (lighting)
	{
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
	}
	else
		glDisable(GL_LIGHTING);
}

void Print(float x, float y, char *format, ...)
{
	va_list args;
	char buffer[200];
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	for (char* p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void DrawInfo()
{
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 3000, 0, 3000);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.7f, 1, 0);
	Print(80, 2800, "Decal: %d", decal);
	Print(80, 2650, "Colored: %d", colored);
	Print(80, 2500, "Lighting: %d", lighting);
	Print(80, 200, "Wrapping: %s", (wrap == GL_REPEAT ? "Repeat" : "Clamp"));
	Print(80, 60, "Filtering: %s", (filter == GL_LINEAR ? "Linear" : "Nearest"));
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}

void DrawScene()
{
	float t[4][2] = { sx, 1 - sy, sx, sy, 1 - sx, sy, 1 - sx, 1 - sy };
	glNewList(1, GL_COMPILE);

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslated(0.5, 0.5, 0);
	glRotatef(texZ, 0, 0, 1);
	glTranslated(-0.5, -0.5, 0);
	glTranslated(texX, texY, 0);

	glColor3fv((colored ? green : white));
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++)
	{
		glNormal3fv(norm[i]);
		for (int j = 0; j < 4; j++)
		{
			glTexCoord2fv(t[j]);
			glVertex3fv(v[id[i][j]]);
		}
	}
	glEnd();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEndList();
}

void OnPaint()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap); // если wrap=GL_REPEAT, то текстура повторяется, если wrap=GL_CLAMP - закрашивается цветом пограничных точек текстуры
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
	glPushMatrix();
	DrawInfo();
	glTranslated(dx, dy, dz);
	glMultMatrixf(rotMatrix);
	glCallList(1);
	glPopMatrix();
	glutSwapBuffers();
}


void AddRotation(float angle, float x, float y, float z)
{
	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle, x, y, z);
	glMultMatrixf(rotMatrix);
	glGetFloatv(GL_MODELVIEW_MATRIX, rotMatrix);
	glPopMatrix();
}


void OnSize(int w, int h)	// Реакция на WM_SIZE
{
	glViewport(0, 0, w, h);// Задаем видовой порт окна (вся клиентская область)
	glMatrixMode(GL_PROJECTION); //определяет в качестве текущей матрицу проецирования
	glLoadIdentity();//загружает в нее матрицу с единицами на диагонали
	gluPerspective(45, double(w) / h, 0.1, 100); // угол, боковые грани(дисбаланс), передняя и задняя грани
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void OnIdle()
{
	AddRotation(rotX / 200, 1, 0, 0);
	AddRotation(rotY / 200, 0, 1, 0);
	glutPostRedisplay();
}

void OnMouse(int button, int state, int x, int y)
{
	leftButton = button == GLUT_LEFT_BUTTON;
	if (state == GLUT_DOWN)
	{
		glutIdleFunc(0);
		rotX = rotY = 0;
	}
	else
	{
		if (fabs(rotX) > 1 || fabs(rotY) > 1)
			glutIdleFunc(OnIdle);
		else
			glutIdleFunc(0);
	}
	posX = x;
	posY = y;
}

void OnMouseMove(int x, int y)
{
	rotX = y - posY;
	rotY = x - posX;

	if (leftButton)
	{
		AddRotation(rotX / 10, 1, 0, 0);
		AddRotation(rotY / 10, 0, 1, 0);
	}
	else
		dz += (rotX + rotY) / 60;
	posX = x;
	posY = y;
	glutPostRedisplay();
}


void OnKey(byte ch, int x, int y)
{
	switch (ch)
	{
	case 27: exit(0); break;
	case '2': twoSide = !twoSide;
		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, twoSide);
		break;
	case 'c': colored = !colored; break; // ась? нет такого
	case 'd': decal = !decal;
		if (decal)
		{
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL); //говорит, что цвет надо игнорировать
		}
		else
		{
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //с параметром GL_MODULATE говорит конвейеру OpenGL, что он должен учитывать и цвет и текстуру.
		}
		break;
	case 's': sphereMap = !sphereMap; // текстура проецируется на поверхность сферы, проходящей через глаз
		if (sphereMap)
		{
			glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);

		}
		else
		{
			glDisable(GL_TEXTURE_GEN_S);
			glDisable(GL_TEXTURE_GEN_T);
		}
		break;
	case 'l': lighting = !lighting; 
		SetLight();
		break;
	case 'o': LoadTexture(1); break;
	case 'w': wrap = (wrap==GL_REPEAT) ? GL_CLAMP : GL_REPEAT; break;
	case 'f': filter = (filter==GL_NEAREST) ? GL_LINEAR : GL_NEAREST; break; // GL_LINEAR -выбор тексела происходит с помощью процедуры линейной интерполяции. GL_NEAREST- выбор тексела происходит по принципу близости координат.
	}
	DrawScene();
	glutPostRedisplay();
}

void OnSpecialKey(int key, int x, int y)
{
	float delta = -0.005 * dz;
	switch (key)
	{
	case GLUT_KEY_LEFT: dx -= delta; break;
	case GLUT_KEY_RIGHT: dx += delta; break;
	case GLUT_KEY_DOWN: dy -= delta; break;
	case GLUT_KEY_UP:  dy += delta; break;
	/*case GLUT_KEY_F1:  
		for (int i = 0; i < 4; i++)
		{
				t[i][0] += delta;
		}
		break;
	case GLUT_KEY_F2:
		for (int i = 0; i < 4; i++)
		{
			t[i][0] -= delta;
		}
		break;
	case GLUT_KEY_F3:
		for (int i = 0; i < 4; i++)
		{
			t[i][1] += delta;
		}
		break;
	case GLUT_KEY_F4:
		for (int i = 0; i < 4; i++)
		{
			t[i][1] -= delta;
		}
		break;
	case GLUT_KEY_F5:
		for (int i = 0; i < 4; i++)
		{
			t[i][0] += delta;
			t[i][1] += delta;
		}
		break;
	case GLUT_KEY_F6:
		for (int i = 0; i < 4; i++)
		{
			t[i][0] -= delta;
			t[i][1] -= delta;
		}
		break;*/
	
	case GLUT_KEY_F1: texX += 0.01f; break;
	case GLUT_KEY_F2: texX -= 0.01f; break;
	case GLUT_KEY_F3: texY += 0.01f; break;
	case GLUT_KEY_F4: texY -= 0.01f; break;
	case GLUT_KEY_F5: texZ += 1; break;
	case GLUT_KEY_F6: texZ -= 1; break;
	case GLUT_KEY_F7: sx += 0.01f; break;
	case GLUT_KEY_F8: sx -= 0.01f; break;
	case GLUT_KEY_F9: sy += 0.01f; break;
	case GLUT_KEY_F10: sy -= 0.01f; break;
	}
	DrawScene();
	glutPostRedisplay();
}



void Init()
{
	glClearColor(0, 0, 0, 0);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);// часть фигуры, видная глазу
	glEnable(GL_LIGHT0);
	SetLight();
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D); // включение режима текстурирования
	if (LoadTexture(1))
		DrawScene();
}




void main()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("c d s l o f w f1-f6");
	Init();

	glutMouseFunc(OnMouse);
	glutMotionFunc(OnMouseMove);
	glutKeyboardFunc(OnKey);
	glutSpecialFunc(OnSpecialKey);

	glutIdleFunc(OnIdle); //сообщает системе адрес функции, когда приложению(временно) нечего делать.
	//glutIdleFunc(0); //для остановки анимации

	glutReshapeFunc(OnSize);
	glutDisplayFunc(OnPaint);
	glutMainLoop();
	//===Здесь нельзя размещать код, так как предыдущий оператор является псевдо бесконечным циклом выборки сообщений о событиях
}



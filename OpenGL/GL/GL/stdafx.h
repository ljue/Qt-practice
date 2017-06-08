// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#pragma warning(disable : 4136 4244 4305 4312)
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")

#define WIN32_LEAN_AND_MEAN

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>


#include <windows.h>
#include <assert.h>
#include <Commdlg.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/timeb.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "glut.h"

using namespace std;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned short ushort;

// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы

// stdafx.h: archivo de inclusión de los archivos de inclusión estándar del sistema
// o archivos de inclusión específicos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
//

#pragma once

#include "targetver.h"


#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
// Archivos de encabezado de Windows:
#include <windows.h>



// TODO: mencionar aquí los encabezados adicionales que el programa necesita
#include <atlbase.h>


// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

using namespace std;

#pragma comment (lib, "d3d9.lib")
#pragma comment ( lib, "winmm.lib" )


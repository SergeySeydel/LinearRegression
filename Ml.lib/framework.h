#pragma once
#ifdef _WIN32
/// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN            
/// Windows Header Files
#include <windows.h>
#endif

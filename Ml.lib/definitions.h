#pragma once


#if defined(_MSC_VER)
    ///for  Microsoft
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    /// for  GCC
    #define EXPORT __attribute__((visibility("default"))) //Defines for linux
    #define IMPORT
#else
    /// do nothing
    #define EXPORT
    #define IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

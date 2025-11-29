/*
    @author yuan
    @brief  some encoding conversion functions between unicode <-> ascii <-> utf8, only for windows platform.
*/
#ifndef __WIN_ENCODING_UTILS_H__
#define __WIN_ENCODING_UTILS_H__

#include <wchar.h>

/*
    For all the functions below:
    when success, return the converted string, and it is your duty to call free() to destroy them, 
    else return NULL. 
*/
wchar_t* weu_ascii_to_unicode(const char* str, int* wstrLen);
char*    weu_unicode_to_ascii(const wchar_t* wstr, int* strLen);

wchar_t* weu_utf8_to_unicode(const char* str, int* wstrLen);
char*    weu_unicode_to_utf8(const wchar_t* wstr, int* strLen);

char*    weu_utf8_to_ascii(const char* str, int* asciiLen);
char*    weu_ascii_to_utf8(const char* str, int* utf8Len);

#endif

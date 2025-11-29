#ifdef _WIN32
#include <stringapiset.h>
#endif

#include <stdlib.h>
#include "win_encoding_utils.h"

wchar_t* weu_ascii_to_unicode(const char* str, int* wstrLen) {
    int len;
    wchar_t* temp;

    len = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    if (len == 0) {
        return NULL;
    }
        
    temp = (wchar_t*)malloc(len * sizeof(wchar_t));
    if (temp == NULL) {
        return NULL;
    }
        
    *wstrLen = MultiByteToWideChar(CP_ACP, 0, str, -1, temp, len);
    return temp;
}

char* weu_unicode_to_ascii(const wchar_t* wstr, int* strLen) {
    int len;
    char* temp;

    len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
    if (len == 0) {
        return NULL;
    }

    temp = (char*)malloc(len * sizeof(char));
    if (temp == NULL) {
        return NULL;
    }

    *strLen = WideCharToMultiByte(CP_ACP, 0, wstr, -1, temp, len, NULL, NULL);
    return temp;
}

wchar_t* weu_utf8_to_unicode(const char* str, int* wstrLen) {
    int len;
    wchar_t* temp;

    len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    if (len == 0) {
        return NULL;
    }

    temp = (wchar_t*)malloc(len * sizeof(wchar_t));
    if (temp == NULL) {
        return NULL;
    }

    *wstrLen = MultiByteToWideChar(CP_UTF8, 0, str, -1, temp, len);
    return temp;
}

char* weu_unicode_to_utf8(const wchar_t* wstr, int* strLen) {
    int len;
    char* temp;

    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    if (len == 0) {
        return NULL;
    }

    temp = (char*)malloc(len * sizeof(char));
    if (temp == NULL) {
        return NULL;
    }

    *strLen = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, temp, len, NULL, NULL);
    return temp;
}

char* weu_utf8_to_ascii(const char* str, int* asciiLen) {
    int tmpLen;
    char* result;

    wchar_t* tmpWstr = weu_utf8_to_unicode(str, &tmpLen);
    if (tmpWstr == NULL) {
        return NULL;
    }

    result = weu_unicode_to_ascii(tmpWstr, &tmpLen);

    if (result != NULL) {
        *asciiLen = tmpLen;
    }

    free(tmpWstr);
    return result;
}

char* weu_ascii_to_utf8(const char* str, int* utf8Len) {
    int tmpLen;
    char* result;

    wchar_t* tmpWstr = weu_ascii_to_unicode(str, &tmpLen);
    if (tmpWstr == NULL) {
        return NULL;
    }

    result = weu_unicode_to_utf8(tmpWstr, &tmpLen);

    if (result != NULL) {
        *utf8Len = tmpLen;
    }

    free(tmpWstr);
    return result;
}

#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <string>
#include <memory>
#include <system_error>

namespace win_encoding {
    inline std::string unicode_to_ascii(const std::wstring& wstr, std::error_code& ec) {
        int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
        if (len == 0) {
            ec.assign(GetLastError(), std::system_category());
            return "";
        }

        auto buf = std::make_unique<char[]>(len);
        WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, buf.get(), len, nullptr, nullptr);

        ec.clear();
        return std::string(buf.get());
    }

    inline std::wstring ascii_to_unicode(const std::string& str, std::error_code& ec) {
        int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);
        if (len == 0) {
            ec.assign(GetLastError(), std::system_category());
            return L"";
        }
        
        auto buf = std::make_unique<wchar_t[]>(len);
        MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buf.get(), len);

        ec.clear();
        return std::wstring(buf.get());
    }

    inline std::wstring utf8_to_unicode(const std::string& str, std::error_code& ec) {
        int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
        if (len == 0) {
            ec.assign(GetLastError(), std::system_category());
            return L"";
        }

        auto buf = std::make_unique<wchar_t[]>(len);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, buf.get(), len);

        ec.clear();
        return std::wstring(buf.get());
    }

    inline std::string unicode_to_utf8(const std::wstring& wstr, std::error_code& ec) {
        int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
        if (len == 0) {
            ec.assign(GetLastError(), std::system_category());
            return "";
        }

        auto buf = std::make_unique<char[]>(len);
        WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, buf.get(), len, nullptr, nullptr);

        ec.clear();
        return std::string(buf.get());
    }

    inline std::string utf8_to_ascii(const std::string& str, std::error_code& ec) {
        std::wstring temp = utf8_to_unicode(str, ec);

        if (ec) {
            return "";
        }

        return unicode_to_ascii(temp, ec);
    }

    inline std::string ascii_to_utf8(const std::string& str, std::error_code& ec) {
        std::wstring temp = ascii_to_unicode(str, ec);

        if (ec) {
            return "";
        }

        return unicode_to_utf8(temp, ec);
    }

    inline std::string unicode_to_ascii(const std::wstring& wstr) {
        std::error_code ec;
        std::string result = unicode_to_ascii(wstr, ec);

        if (ec) {
            throw std::system_error{ ec, "unicode to ascii failed" };
        }

        return result;
    }

    inline std::wstring ascii_to_unicode(const std::string& str) {
        std::error_code ec;
        std::wstring result = ascii_to_unicode(str, ec);

        if (ec) {
            throw std::system_error{ ec, "ascii to unicode failed" };
        }

        return result;
    }

    inline std::wstring utf8_to_unicode(const std::string& str) {
        std::error_code ec;
        std::wstring result = utf8_to_unicode(str, ec);

        if (ec) {
            throw std::system_error{ ec, "utf8 to unicode failed" };
        }

        return result;
    }

    inline std::string unicode_to_utf8(const std::wstring& wstr) {
        std::error_code ec;
        std::string result = unicode_to_utf8(wstr, ec);

        if (ec) {
            throw std::system_error{ ec, "unicode to utf8 failed" };
        }

        return result;
    }

    inline std::string utf8_to_ascii(const std::string& str) {
        std::error_code ec;
        std::string result = utf8_to_ascii(str, ec);

        if (ec) {
            throw std::system_error{ ec, "utf8 to ascii failed" };
        }

        return result;
    }

    inline std::string ascii_to_utf8(const std::string& str) {
        std::error_code ec;
        std::string result = ascii_to_utf8(str, ec);

        if (ec) {
            throw std::system_error{ ec, "ascii to utf8 failed" };
        }

        return result;
    }
};

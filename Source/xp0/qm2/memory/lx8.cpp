#include "lx8.h"
#include <algorithm>
#include <vector>

static bool _c0(const std::string& a, const char* b) {
    return (_stricmp(a.c_str(), b) == 0);
}

static bool _c1(const std::string& a, const wchar_t* b) {
    int l = MultiByteToWideChar(CP_ACP, 0, a.c_str(), -1, NULL, 0);
    if (l <= 0) return false;
    std::vector<wchar_t> w(static_cast<size_t>(l));
    MultiByteToWideChar(CP_ACP, 0, a.c_str(), -1, w.data(), l);
    return (_wcsicmp(w.data(), b) == 0);
}

std::uint32_t _p2::_p3(const std::string& a) {
    std::uint32_t r = 0;
    HANDLE s = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (s == INVALID_HANDLE_VALUE) return r;
    PROCESSENTRY32W e{};
    e.dwSize = sizeof(PROCESSENTRY32W);
    if (Process32FirstW(s, &e)) {
        do {
            if (_c1(a, e.szExeFile)) { r = e.th32ProcessID; _p12 = r; break; }
        } while (Process32NextW(s, &e));
    }
    CloseHandle(s);
    return r;
}

std::uint64_t _p2::_p4(const std::string& a) {
    std::uint64_t r = 0;
    if (!_p14) return r;
    DWORD d = GetProcessId(_p14);
    HANDLE s = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, d);
    if (s == INVALID_HANDLE_VALUE) return r;
    MODULEENTRY32W e{};
    e.dwSize = sizeof(MODULEENTRY32W);
    if (Module32FirstW(s, &e)) {
        do {
            if (_c1(a, e.szModule)) { r = reinterpret_cast<uint64_t>(e.modBaseAddr); _p13 = r; break; }
        } while (Module32NextW(s, &e));
    }
    CloseHandle(s);
    return r;
}

bool _p2::_p5(const std::string& a) {
    std::uint32_t p = _p3(a);
    if (p == 0) return false;
    HANDLE h = OpenProcess(PROCESS_ALL_ACCESS, FALSE, p);
    if (h == INVALID_HANDLE_VALUE || h == NULL) return false;
    _p14 = h;
    return true;
}

std::string _p2::_p6(std::uint64_t a) const {
    std::int32_t l = _p7<std::int32_t>(a + 0x10);
    std::uint64_t s = (l >= 16) ? _p7<std::uint64_t>(a) : a;
    if (l <= 0 || l > 255) return "Unknown";
    std::vector<char> b(static_cast<size_t>(l) + 1, 0);
    _p0(_p14, reinterpret_cast<void*>(s), b.data(), static_cast<ULONG>(b.size()), nullptr);
    return std::string(b.data(), static_cast<size_t>(l));
}

std::uint32_t _p2::_p9() const { return _p12; }
std::uint64_t _p2::_p10() const { return _p13; }
HANDLE _p2::_p11() const { return _p14; }
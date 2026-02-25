#pragma once
#include <windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include <memory>
#include <cstdint>

inline intptr_t _p0(HANDLE a, PVOID b, PVOID c, ULONG d, PULONG e) {
    SIZE_T f = 0;
    BOOL g = ReadProcessMemory(a, b, c, d, &f);
    if (e) *e = static_cast<ULONG>(f);
    return g ? 0 : -1;
}

inline intptr_t _p1(HANDLE a, PVOID b, PVOID c, ULONG d, PULONG e) {
    SIZE_T f = 0;
    BOOL g = WriteProcessMemory(a, b, c, d, &f);
    if (e) *e = static_cast<ULONG>(f);
    return g ? 0 : -1;
}

class _p2 final
{
public:
    _p2() = default;
    ~_p2() = default;

    std::uint32_t _p3(const std::string& a);
    std::uint64_t _p4(const std::string& a);
    bool _p5(const std::string& a);
    std::string _p6(std::uint64_t a) const;

    template <typename T>
    T _p7(std::uint64_t a) const;

    template <typename T>
    void _p8(std::uint64_t a, T b) const;

    std::uint32_t _p9() const;
    std::uint64_t _p10() const;
    HANDLE _p11() const;

private:
    std::uint32_t _p12 = 0;
    std::uint64_t _p13 = 0;
    HANDLE _p14 = nullptr;
};

template <typename T>
T _p2::_p7(uint64_t a) const {
    T b{};
    _p0(_p14, reinterpret_cast<void*>(a), &b, sizeof(T), nullptr);
    return b;
}

template <typename T>
void _p2::_p8(uint64_t a, T b) const {
    _p1(_p14, reinterpret_cast<void*>(a), &b, sizeof(T), nullptr);
}

inline std::unique_ptr<_p2> memory = std::make_unique<_p2>();
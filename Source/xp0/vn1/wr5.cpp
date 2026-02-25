#include "wr5.h"
#include "ky4.h"
#include "tz6.h"
#include "hf3.h"
#include "../qm2/memory/lx8.h"
#include <cstdint>
#include <string>
#include <vector>

std::string _w0::_w9::_y1() const {
    uint64_t n = memory->_p7<uint64_t>(this->_x + _a5::_b13);
    if (n) return memory->_p6(n);
    return "unknown";
}

std::string _w0::_w9::_y2() const {
    uint64_t a = memory->_p7<uint64_t>(this->_x + _a5::_b11);
    uint64_t b = memory->_p7<uint64_t>(a + _a5::_b12);
    if (b) return memory->_p6(b);
    return "unknown_class";
}

std::vector<_w0::_w1> _w0::_w1::_y5() const {
    uint64_t s = memory->_p7<uint64_t>(this->_x + _a5::_b10);
    uint64_t e = memory->_p7<uint64_t>(s + _a5::_b9);
    std::vector<_w0::_w1> r;
    r.reserve(32);
    for (uint64_t i = memory->_p7<uint64_t>(s); i < e; i += sizeof(std::shared_ptr<void*>)) {
        _w0::_w1 c(memory->_p7<uint64_t>(i));
        if (c._x != 0) r.emplace_back(c);
    }
    return r;
}

std::vector<_w0::_w1> _w0::_w1::_y6() const {
    std::vector<_w0::_w1> r; r.reserve(128);
    std::vector<_w0::_w1> s; s.reserve(64);
    for (auto& c : this->_y5()) s.push_back(c);
    while (!s.empty()) {
        _w0::_w1 t = s.back(); s.pop_back();
        if (t._x == 0) continue;
        r.push_back(t);
        for (auto& c : t._y5()) if (c._x != 0) s.push_back(c);
    }
    return r;
}

_w0::_w1 _w0::_w1::_y3(std::string n) const {
    for (auto c : this->_y5()) if (c._y1() == n) return c;
    return {};
}

_w0::_w1 _w0::_w1::_y4(std::string c) const {
    for (auto l : this->_y5()) if (l._y2() == c) return l;
    return {};
}

_q3::_q4 _w0::_w1::_y7() const {
    uint64_t p = memory->_p7<uint64_t>(this->_x + _a1::_b1);
    return memory->_p7<_q3::_q4>(p + _a8::_b18);
}

float _w0::_w1::_y8() const {
    return memory->_p7<float>(this->_x + _a1::_b2);
}

_q3::_q4 _w0::_w1::_y9() const {
    uint64_t p = memory->_p7<uint64_t>(this->_x + _a1::_b1);
    return memory->_p7<_q3::_q4>(p + _a8::_b20);
}

_q5 _w0::_w1::_y10() const {
    std::string c = this->_y2();
    if (c == "Camera") {
        auto r = memory->_p7<_q1::_q2>(this->_x + _a2::_b4);
        auto p = memory->_p7<_q3::_q4>(this->_x + _a2::_b3);
        return { r._0,r._1,r._2,r._3,r._4,r._5,r._6,r._7,r._8,p.x,p.y,p.z };
    }
    else {
        uint64_t pm = memory->_p7<uint64_t>(this->_x + _a1::_b1);
        auto r = memory->_p7<_q1::_q2>(pm + _a8::_b19);
        auto p = memory->_p7<_q3::_q4>(pm + _a8::_b18);
        return { r._0,r._1,r._2,r._3,r._4,r._5,r._6,r._7,r._8,p.x,p.y,p.z };
    }
}

_w0::_w1 _w0::_w1::_y11() {
    return _w0::_w1(memory->_p7<uint64_t>(this->_x + _a5::_b14));
}

_w0::_w1 _w0::_w2::_y12() const {
    uint64_t m = memory->_p7<uint64_t>(this->_x + _a7::_b17);
    if (m != 0) return _w0::_w1(m);
    return {};
}

bool _w0::_w5::_y13() const { return memory->_p7<bool>(this->_x + _a6::_b15); }
int _w0::_w5::_y14() const { return memory->_p7<int>(this->_x + _a6::_b15); }
std::string _w0::_w5::_y15() const { return memory->_p7<std::string>(this->_x + _a6::_b15); }
double _w0::_w5::_y16() const { return memory->_p7<double>(this->_x + _a6::_b15); }
float _w0::_w6::_y17() const { return memory->_p7<float>(this->_x + _a4::_b8); }
float _w0::_w6::_y18() const { return memory->_p7<float>(this->_x + _a4::_b7); }
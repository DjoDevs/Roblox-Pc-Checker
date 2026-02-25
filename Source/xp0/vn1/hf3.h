#pragma once
#include <cmath>

namespace _q1 {
    struct _q2 {
        float _0, _1, _2, _3, _4, _5, _6, _7, _8;
    };
}

namespace _q3 {
    struct _q4 {
        float x, y, z;
        inline _q4 operator+(const _q4& o) const { return { x + o.x, y + o.y, z + o.z }; }
        inline _q4 operator-(const _q4& o) const { return { x - o.x, y - o.y, z - o.z }; }
        inline _q4 operator*(float s) const { return { x * s, y * s, z * s }; }
        float _m() const { return std::sqrt(x * x + y * y + z * z); }
        _q4 _n() const { float l = _m(); if (l == 0) return { 0,0,0 }; return { x / l, y / l, z / l }; }
        _q4 _c(const _q4& o) const { return { y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x }; }
        float _d(const _q4& o) const { float a = o.x - x, b = o.y - y, c = o.z - z; return std::sqrt(a * a + b * b + c * c); }
    };
}

struct _q5 {
    float _0, _1, _2, _3, _4, _5, _6, _7, _8, x, y, z;
    inline _q3::_q4 _p() const { return { x, y, z }; }
    inline _q3::_q4 _r() const { return { _0, _3, _6 }; }
    inline _q3::_q4 _u() const { return { _1, _4, _7 }; }
    inline _q3::_q4 _l() const { return { -_2, -_5, -_8 }; }
    _q5 operator+(const _q5& o) const { return { _0 + o._0,_1 + o._1,_2 + o._2,_3 + o._3,_4 + o._4,_5 + o._5,_6 + o._6,_7 + o._7,_8 + o._8,x + o.x,y + o.y,z + o.z }; }
    _q5 operator-(const _q5& o) const { return { _0 - o._0,_1 - o._1,_2 - o._2,_3 - o._3,_4 - o._4,_5 - o._5,_6 - o._6,_7 - o._7,_8 - o._8,x - o.x,y - o.y,z - o.z }; }
    _q5 operator*(float s) const { return { _0 * s,_1 * s,_2 * s,_3 * s,_4 * s,_5 * s,_6 * s,_7 * s,_8 * s,x * s,y * s,z * s }; }
    _q5 operator/(float s) const { return { _0 / s,_1 / s,_2 / s,_3 / s,_4 / s,_5 / s,_6 / s,_7 / s,_8 / s,x / s,y / s,z / s }; }
};
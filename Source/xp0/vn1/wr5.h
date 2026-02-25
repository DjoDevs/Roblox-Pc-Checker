#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "hf3.h"

#define _Z(t) t(uint64_t a) : _w1(a) {} t(const _w1& o) : _w1(o._x) {}

namespace _w0
{
class _w8 { public: uint64_t _x; _w8() : _x(0) {} _w8(uint64_t a) : _x(a) {} };
                  class _w9 : public _w8 { using _w8::_w8; public: std::string _y1() const; std::string _y2() const; };

                  class _w1 : public _w9
                  {
                      using _w9::_w9;
                  public:
                      _w1(const _w1& o) : _w9(o._x) {}
                      _w1 _y3(std::string n) const;
                      _w1 _y4(std::string c) const;
                      std::vector<_w1> _y5() const;
                      std::vector<_w1> _y6() const;
                      _q3::_q4 _y7() const;
                      float _y8() const;
                      _q3::_q4 _y9() const;
                      _q5 _y10() const;
                      _w1 _y11();
                  };

                  class _w2 : public _w1 { using _w1::_w1; public: _Z(_w2) _w1 _y12() const; };
                  class _w3 : public _w1 { using _w1::_w1; public: _Z(_w3) };
                  class _w4 : public _w1 { using _w1::_w1; public: _Z(_w4) };
                  class _w5 : public _w1 { using _w1::_w1; public: _Z(_w5) bool _y13() const; int _y14() const; std::string _y15() const; double _y16() const; };
                  class _w6 : public _w1 { using _w1::_w1; public: _Z(_w6) float _y17() const; float _y18() const; };
}
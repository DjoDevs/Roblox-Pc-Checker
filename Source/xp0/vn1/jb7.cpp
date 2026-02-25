#pragma once
#include "jb7.h"
#include "tz6.h"
#include "ky4.h"
#include "wr5.h"
#include "../qm2/memory/lx8.h"  
#include <string>
#include <vector>
#include <cstdint>
#include <chrono>
#include <thread>
#include <mutex>

void _k::_k15() {
    int _z0 = 0;
    while (true) {
        _w0::_w1 _z1 = _j::_j1;
        int _z2 = 0;
        if (_z1._x != 0) _z2 = static_cast<int>(_z1._y6().size());

        if (_z1._x != _k::_k8._x || _z0 != _z2) {
            _z0 = _z2;
            _k::_k8 = _z1;
            if (_z1._x == 0) { _k::_k11.clear(); _k::_k12.clear(); _k::_k13.clear(); _k::_k14.clear(); continue; }

            std::vector<_w0::_w1> _z3, _z4, _z5, _z6;
            _z3.reserve(7); _z4.reserve(20); _z5.reserve(2); _z6.reserve(7);

            for (auto& _z7 : _z1._y6()) {
                std::string _z8 = _z7._y1();
                if (_z8 == "ComputerTable") _z3.emplace_back(_z7);
                else if (_z8 == "SingleDoor" || _z8 == "DoubleDoor") _z4.emplace_back(_z7);
                else if (_z8 == "ExitDoor") _z5.emplace_back(_z7);
                else if (_z8 == "FreezePod") _z6.emplace_back(_z7);
            }

            _k::_k11 = _z3; _k::_k12 = _z4; _k::_k13 = _z5; _k::_k14 = _z6;
        }

        std::vector<_k::_k2> _z9;
        _z9.reserve(5);

        for (auto& _z10 : _j::_j2._y5()) {
            if (_z10._y2() != "Player") continue;
            _w0::_w2 _z11(_z10);
            _w0::_w3 _z12 = _z11._y12();

            _k::_k2 _z13;
            _z13._k3 = _z12;
            _z13._k4 = _z11;

            _w0::_w1 _z14 = _z11._y3("TempPlayerStatsModule");
            if (_z14._x != 0) {
                _w0::_w5 _z15 = _w0::_w5(_z14._y3("IsBeast"));
                _z13._k5._k1 = _z15._y13();
            }

            for (auto& _z16 : _z12._y5()) {
                std::string _z17 = _z16._y2();
                if (_z17 == "Part" || _z17 == "MeshPart") {
                    _w0::_w4 _z18(_z16);
                    _z13._k6[_z18._y1()] = _z18;
                }
            }
            _z9.emplace_back(_z13);
        }

        _k::_k9 = _z9;
        std::lock_guard<std::mutex> _z19(_k::_k7);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
}
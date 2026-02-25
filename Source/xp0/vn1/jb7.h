#pragma once
#include "wr5.h"
#include <vector>
#include <unordered_map>
#include <mutex>
#include <string>

namespace _k {
    struct _k0 { bool _k1 = false; };

    struct _k2 {
        _w0::_w3 _k3;
        _w0::_w2 _k4;
        _k0 _k5 = {};
        std::unordered_map<std::string, _w0::_w4> _k6;
    };

    inline std::mutex _k7;
    inline _w0::_w1 _k8;
    inline std::vector<_k2> _k9;
    inline _w0::_w2 _k10;
    inline std::vector<_w0::_w1> _k11;
    inline std::vector<_w0::_w1> _k12;
    inline std::vector<_w0::_w1> _k13;
    inline std::vector<_w0::_w1> _k14;

    void _k15();
}
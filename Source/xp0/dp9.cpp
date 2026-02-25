#include "dp9.h"
#include "vn1/jb7.h"
#include "vn1/tz6.h"
#include "vn1/ky4.h"
#include "vn1/wr5.h"
#include "vn1/hf3.h"
#include "qm2/memory/lx8.h"
#include <unordered_map>
#include <unordered_set>
#include <thread>
#include <vector>
#include <chrono>
#include <future>
#include <cmath>
#include <windows.h>
#include <algorithm>
#include <string>

bool _n::_n8 = false;
bool _n::_n9 = false;
bool _n::_n10 = false;
bool _n::_n11 = false;
bool _n::_n12 = false;
bool _n::_n13 = false;
bool _n::_n14 = false;
bool _n::_n15 = false;
bool _n::_n16 = false;
float _n::_n17 = 0.0f;
float _n::_n18 = 0.0f;
float _n::_n19 = 0.0f;
float _n::_n20 = 0.0f;
bool _n::_n21 = false;
float _n::_n22 = 0.0f;
std::unordered_map<std::string, std::string> _n::_n23;

static bool _v0(uint64_t a) { return a >= 0x1000 && a <= 0x7FFFFFFFFFFF; }

static int _v1(int(*f)()) {
    __try { return f(); }
    __except (EXCEPTION_EXECUTE_HANDLER) { return -1; }
}

static uint64_t _v2 = 0;
static bool _v3 = false;
static char _v4[512] = { 0 };

static int _v5() {
    _w0::_w1 m; m._x = _v2;
    std::string r;
    _v3 = _n::_n7(m, r);
    if (_v3 && !r.empty()) strncpy_s(_v4, r.c_str(), sizeof(_v4) - 1);
    else _v4[0] = '\0';
    return 0;
}

static bool _v6(uint64_t a, std::string& r) {
    _v2 = a; _v3 = false; _v4[0] = '\0';
    if (_v1(_v5) != 0) return false;
    if (_v3) r = _v4;
    return _v3;
}

static std::string _v7(const std::string& s) {
    std::string r = s;
    std::transform(r.begin(), r.end(), r.begin(), [](unsigned char c) { return (char)std::tolower(c); });
    return r;
}

std::unordered_map<std::string, _q3::_q4> _v8 = {
    {"Head",{2,1,1}},{"HumanoidRootPart",{2,2,1}},{"Left Arm",{1,2,1}},{"Left Leg",{1,2,1}},
    {"Right Arm",{1,2,1}},{"Right Leg",{1,2,1}},{"Torso",{2,2,1}},{"UpperTorso",{2,1.6f,1}},
    {"LowerTorso",{2,0.4f,1}},{"LeftUpperArm",{1,1.2f,1}},{"LeftLowerArm",{1,1.2f,1}},
    {"LeftHand",{1,0.6f,1}},{"RightUpperArm",{1,1.2f,1}},{"RightLowerArm",{1,1.2f,1}},
    {"RightHand",{1,0.6f,1}},{"LeftUpperLeg",{1,1.2f,1}},{"LeftLowerLeg",{1,1.2f,1}},
    {"LeftFoot",{1,0.6f,1}},{"RightUpperLeg",{1,1.2f,1}},{"RightLowerLeg",{1,1.2f,1}},
    {"RightFoot",{1,0.6f,1}},
};

float _v9 = 36;
static bool _v10 = false;
static char _v11[512] = { 0 };
static int _v12 = 0;

static int _v13() {
    _v10 = false; _v11[0] = '\0';
    if (!_v0(_j::_j1._x)) return 0;
    auto d = _j::_j1._y6();
    if (d.size() > 20000) return 0;
    for (size_t i = 0; i < d.size(); i++) {
        if (!_v0(d[i]._x)) continue;
        std::string n = d[i]._y1();
        bool m = false;
        if (_v12 == 0 && (n == "SingleDoor" || n == "DoubleDoor")) m = true;
        if (_v12 == 1 && n == "ExitDoor") m = true;
        if (_v12 == 2 && n == "ComputerTable") m = true;
        if (_v12 == 3 && n == "FreezePod") m = true;
        if (!m) continue;
        std::string r;
        if (_n::_n7(d[i], r)) { _v10 = true; strncpy_s(_v11, r.c_str(), sizeof(_v11) - 1); return 0; }
    }
    return 0;
}

static std::string _v14(const std::string& n) {
    if (n == "ComputerTable") return "PC";
    if (n == "SingleDoor" || n == "DoubleDoor") return "Door";
    if (n == "ExitDoor") return "Exit";
    if (n == "FreezePod") return "Tube";
    return "";
}

static std::string _v15(_w0::_w1 e) {
    _w0::_w1 c = e;
    for (int d = 0; d < 8; d++) {
        _w0::_w1 p;
        try { p = c._y11(); }
        catch (...) { break; }
        if (!_v0(p._x)) break;
        std::string pn;
        try { pn = p._y1(); }
        catch (...) { break; }
        std::string ct = _v14(pn);
        if (!ct.empty()) return ct;
        try { _w0::_w1 h = p._y4("Humanoid"); if (_v0(h._x)) return "Player"; }
        catch (...) {}
        try {
            auto sb = p._y5();
            if (sb.size() <= 500) {
                for (size_t i = 0; i < sb.size(); i++) {
                    if (sb[i]._x == c._x || !_v0(sb[i]._x)) continue;
                    std::string sn; try { sn = sb[i]._y1(); }
                    catch (...) { continue; }
                    std::string sc = _v14(sn); if (!sc.empty()) return sc;
                    try { _w0::_w1 sh = sb[i]._y4("Humanoid"); if (_v0(sh._x)) return "Player"; }
                    catch (...) {}
                    try {
                        auto sc2 = sb[i]._y5();
                        if (sc2.size() <= 200) for (size_t j = 0; j < sc2.size(); j++) {
                            if (!_v0(sc2[j]._x)) continue;
                            std::string sn2; try { sn2 = sc2[j]._y1(); }
                            catch (...) { continue; }
                            std::string sc3 = _v14(sn2); if (!sc3.empty()) return sc3;
                        }
                    }
                    catch (...) {}
                }
            }
        }
        catch (...) {}
        c = p;
    }
    return "Unknown";
}

static int _v16() {
    if (!_v0(_j::_j1._x)) return 0;
    std::vector<_w0::_w1> d;
    try { d = _j::_j1._y6(); }
    catch (...) { return 0; }
    if (d.size() > 30000) return 0;
    for (size_t i = 0; i < d.size(); i++) {
        if (!_v0(d[i]._x)) continue;
        std::string cn; try { cn = d[i]._y2(); }
        catch (...) { continue; }
        if (cn != "Highlight" && cn != "BoxHandleAdornment") continue;
        std::string ct; try { ct = _v15(d[i]); }
        catch (...) { ct = "Unknown"; }
        std::string pn = "?";
        try { _w0::_w1 p = d[i]._y11(); if (_v0(p._x)) pn = p._y1(); }
        catch (...) {}
        std::string dt = cn + " on '" + pn + "'";
        if (ct == "PC" && !_n::_n8) { _n::_n8 = true; _n::_n23["PC"] = dt; }
        else if (ct == "Door" && !_n::_n10) { _n::_n10 = true; _n::_n23["Door"] = dt; }
        else if (ct == "Exit" && !_n::_n9) { _n::_n9 = true; _n::_n23["Exit"] = dt; }
        else if (ct == "Tube" && !_n::_n12) { _n::_n12 = true; _n::_n23["Tube"] = dt; }
        else if (ct == "Player" && !_n::_n11) { _n::_n11 = true; _n::_n23["Player"] = dt; }
        else if (ct == "Unknown" && !_n::_n11) { _n::_n11 = true; _n::_n23["Player"] = dt; }
    }
    return 0;
}

void _n::_n6() {
    if (!_v0(_j::_j0._x)) {
        uint64_t f = memory->_p7<uint64_t>(memory->_p10() + _a3::_b5);
        if (_v0(f)) _j::_j0 = memory->_p7<_w0::_w1>(f + _a3::_b6);
    }
    if (!_v0(_j::_j0._x)) return;
    _j::_j2 = _j::_j0._y4("Players");
    if (!_v0(_j::_j2._x)) { _j::_j0._x = 0; return; }
    _j::_j3 = _j::_j0._y4("ReplicatedStorage");
    _j::_j1 = _j::_j0._y4("Workspace");
    _j::_j5 = _j::_j0._y4("CoreGui");
    if (_v0(_j::_j1._x)) _j::_j4 = _j::_j1._y4("Camera");
    if (_v0(_j::_j3._x)) { _j::_j6 = _w0::_w5(_j::_j3._y3("IsGameActive")); _j::_j7 = _w0::_w5(_j::_j3._y3("GameStatus")); }
    if (_v0(_j::_j2._x)) _k::_k10 = _w0::_w2(memory->_p7<_w0::_w2>(_j::_j2._x + _a7::_b16));
}

bool _n::_n7(_w0::_w1 m, std::string& r) {
    if (!_v0(m._x)) return false;
    std::string mn; try { mn = m._y1(); }
    catch (...) { mn = ""; }
    bool ie = (mn == "ExitDoor"), id = (mn == "SingleDoor" || mn == "DoubleDoor");
    bool ic = (mn.find("Computer") != std::string::npos || mn.find("Screen") != std::string::npos);
    try {
        auto ch = m._y5();
        if (ch.size() > 500) return false;
        for (size_t i = 0; i < ch.size(); i++) {
            if (!_v0(ch[i]._x)) continue;
            std::string cn = ch[i]._y2();
            if (cn == "Part" || cn == "BasePart" || cn == "MeshPart") {
                auto s = ch[i]._y9();
                if (s.x > 35.0f || s.y > 35.0f || s.z > 35.0f) {
                    r = "MP(" + cn + " " + std::to_string((int)s.x) + "x" + std::to_string((int)s.y) + "x" + std::to_string((int)s.z) + ")";
                    return true;
                }
            }
            if (cn == "Highlight") { r = "H"; return true; }
            if (cn == "BoxHandleAdornment") { r = "B"; return true; }
            if (cn == "SurfaceGui" && !ie && !id && !ic) { r = "S"; return true; }
            if (cn == "BillboardGui") {
                if (_v0(_j::_j7._x)) {
                    std::string sv = _j::_j7._y15();
                    if (sv != "FIND AN EXIT") {
                        if (id || ic || ie) continue;
                        _w0::_w1 lc = m._y3("Light");
                        if (lc._x == 0) { r = "BB(" + mn + ")"; return true; }
                    }
                }
            }
            if (_v0(ch[i]._x)) {
                auto sc = ch[i]._y5();
                if (sc.size() > 500) continue;
                for (size_t j = 0; j < sc.size(); j++) {
                    if (!_v0(sc[j]._x)) continue;
                    std::string sn = sc[j]._y2();
                    if (sn == "Highlight") { r = "H2"; return true; }
                    if (sn == "BoxHandleAdornment") { r = "B2"; return true; }
                    if (sn == "SurfaceGui" && !ie && !id && !ic) { r = "S2"; return true; }
                }
            }
        }
    }
    catch (...) { return false; }
    return false;
}

static void _v17() {
    if (!_v0(_j::_j5._x)) return;
    try {
        auto ch = _j::_j5._y5();
        if (ch.size() > 2000) return;
        std::unordered_set<std::string> sn = { "RobloxGui","PlayerList","Chat","BubbleChat","PurchasePromptApp","TopBarApp","EmotesMenu","InGameMenu","DevConsoleMaster","CoreScripts","NotificationFrame","VoiceChatPromptFrame","ControlFrame","PerformanceStats","HealthBar" };
        std::unordered_set<std::string> gk = { "singledoor","doubledoor","exitdoor","computertable","freezepod","dooresp","exitesp","computeresp","playeresp","tubeesp" };
        for (const auto& cl : ch) {
            if (!_v0(cl._x)) continue;
            std::string n = cl._y1(), cn = cl._y2();
            if (sn.count(n)) continue;
            if (n.length() > 4 && n.substr(n.length() - 4) == "_ESP") { _n::_n11 = true; _n::_n23["Player"] = "CI:" + n; return; }
            std::string ln = _v7(n);
            if (ln.find("esp") != std::string::npos || ln.find("chams") != std::string::npos || ln.find("wallhack") != std::string::npos) { _n::_n11 = true; _n::_n23["Player"] = "CK:" + n; return; }
            for (const auto& kw : gk) if (ln.find(kw) != std::string::npos) { _n::_n11 = true; _n::_n23["Player"] = "CG:" + n; return; }
            if (cn == "ScreenGui" || cn == "Folder") {
                auto sc = cl._y5();
                if (sc.size() > 500) continue;
                for (const auto& sb : sc) {
                    if (!_v0(sb._x)) continue;
                    std::string sn2 = sb._y2();
                    if (sn2 == "Highlight" || sn2 == "BoxHandleAdornment") { _n::_n11 = true; _n::_n23["Player"] = "CC:" + sn2 + ":" + n; return; }
                }
            }
        }
    }
    catch (...) {}
}

static bool _v18(std::vector<_w0::_w1>& cv, const char* lb, std::unordered_map<std::string, std::string>& di, bool& nf) {
    nf = false; int ck = 0, cr = 0;
    size_t sz = cv.size(); if (sz > 500) sz = 500;
    for (size_t i = 0; i < sz; i++) {
        if (i >= cv.size() || !_v0(cv[i]._x)) continue;
        ck++;
        _v2 = cv[i]._x; _v3 = false; _v4[0] = '\0';
        if (_v1(_v5) != 0) { cr++; continue; }
        if (_v3) { di[lb] = _v4; return true; }
    }
    if (cv.empty() || (ck > 0 && cr == ck)) { nf = true; if (ck > 0 && cr == ck) { _k::_k8._x = 0; cv.clear(); } }
    return false;
}

static _w0::_w1 _v19;
static bool _v20 = false;
static char _v21[512] = { 0 };

static int _v22() {
    _v20 = false; _v21[0] = '\0';
    if (!_v0(_v19._x)) return 0;
    _w0::_w1 pa; try { pa = _v19._y11(); }
    catch (...) { return 0; }
    if (!_v0(pa._x)) return 0;
    std::vector<_w0::_w1> sb; try { sb = pa._y5(); }
    catch (...) { return 0; }
    if (sb.size() > 500) return 0;
    for (size_t i = 0; i < sb.size(); i++) {
        if (sb[i]._x == _v19._x || !_v0(sb[i]._x)) continue;
        std::string cn; try { cn = sb[i]._y2(); }
        catch (...) { continue; }
        if (cn == "Highlight") { _v20 = true; strncpy_s(_v21, "HS", sizeof(_v21) - 1); return 0; }
        if (cn == "BoxHandleAdornment") { _v20 = true; strncpy_s(_v21, "BS", sizeof(_v21) - 1); return 0; }
        try {
            auto sc = sb[i]._y5();
            if (sc.size() <= 200) for (size_t j = 0; j < sc.size(); j++) {
                if (!_v0(sc[j]._x)) continue;
                std::string sn; try { sn = sc[j]._y2(); }
                catch (...) { continue; }
                if (sn == "Highlight") { _v20 = true; strncpy_s(_v21, "HSN", sizeof(_v21) - 1); return 0; }
                if (sn == "BoxHandleAdornment") { _v20 = true; strncpy_s(_v21, "BSN", sizeof(_v21) - 1); return 0; }
            }
        }
        catch (...) {}
    }
    _w0::_w1 gp; try { gp = pa._y11(); }
    catch (...) { return 0; }
    if (!_v0(gp._x)) return 0;
    std::vector<_w0::_w1> uc; try { uc = gp._y5(); }
    catch (...) { return 0; }
    if (uc.size() > 500) return 0;
    for (size_t i = 0; i < uc.size(); i++) {
        if (uc[i]._x == pa._x || !_v0(uc[i]._x)) continue;
        std::string cn; try { cn = uc[i]._y2(); }
        catch (...) { continue; }
        if (cn == "Highlight") { _v20 = true; strncpy_s(_v21, "HPS", sizeof(_v21) - 1); return 0; }
        if (cn == "BoxHandleAdornment") { _v20 = true; strncpy_s(_v21, "BPS", sizeof(_v21) - 1); return 0; }
    }
    return 0;
}

static bool _v23(std::vector<_w0::_w1>& cv, const char* lb, std::unordered_map<std::string, std::string>& di) {
    size_t sz = cv.size(); if (sz > 500) sz = 500;
    for (size_t i = 0; i < sz; i++) {
        if (i >= cv.size() || !_v0(cv[i]._x)) continue;
        _v19 = cv[i]; _v20 = false; _v21[0] = '\0';
        if (_v1(_v22) != 0) continue;
        if (_v20) { di[lb] = _v21; return true; }
    }
    return false;
}

void _n::_n0() {
    try {
        if (!_n::_n11) _v17();
        bool nf = false;
        if (!_n::_n10) { _n::_n10 = _v18(_k::_k12, "Door", _n::_n23, nf); if (!_n::_n10) _n::_n10 = _v23(_k::_k12, "Door", _n::_n23); if (!_n::_n10 && nf) { _v12 = 0; if (_v1(_v13) == 0 && _v10) { _n::_n10 = true; _n::_n23["Door"] = _v11; } } }
        if (!_n::_n9) { _n::_n9 = _v18(_k::_k13, "Exit", _n::_n23, nf); if (!_n::_n9) _n::_n9 = _v23(_k::_k13, "Exit", _n::_n23); if (!_n::_n9 && nf) { _v12 = 1; if (_v1(_v13) == 0 && _v10) { _n::_n9 = true; _n::_n23["Exit"] = _v11; } } }
        if (!_n::_n8) { _n::_n8 = _v18(_k::_k11, "PC", _n::_n23, nf); if (!_n::_n8) _n::_n8 = _v23(_k::_k11, "PC", _n::_n23); if (!_n::_n8 && nf) { _v12 = 2; if (_v1(_v13) == 0 && _v10) { _n::_n8 = true; _n::_n23["PC"] = _v11; } } }
        if (!_n::_n12) { _n::_n12 = _v18(_k::_k14, "Tube", _n::_n23, nf); if (!_n::_n12) _n::_n12 = _v23(_k::_k14, "Tube", _n::_n23); if (!_n::_n12 && nf) { _v12 = 3; if (_v1(_v13) == 0 && _v10) { _n::_n12 = true; _n::_n23["Tube"] = _v11; } } }
        if (!_n::_n11) {
            std::string r; size_t ps = _k::_k9.size(); if (ps > 100) ps = 100;
            for (size_t i = 0; i < ps; i++) { if (i >= _k::_k9.size() || !_v0(_k::_k9[i]._k3._x)) continue; if (_v6(_k::_k9[i]._k3._x, r)) { _n::_n11 = true; _n::_n23["Player"] = r; break; } }
        }
        if (!(_n::_n8 && _n::_n10 && _n::_n9 && _n::_n12 && _n::_n11)) {
            static auto lt = std::chrono::steady_clock::now();
            auto nw = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(nw - lt).count() >= 5) { lt = nw; _v1(_v16); }
        }
    }
    catch (...) {}
}

static _q3::_q4 _v24() {
    if (!_v0(_k::_k10._x)) return { 0,0,0 };
    for (size_t i = 0; i < _k::_k9.size(); i++) {
        if (!_v0(_k::_k9[i]._k4._x) || _k::_k9[i]._k4._x != _k::_k10._x) continue;
        auto h = _k::_k9[i]._k6.find("HumanoidRootPart");
        if (h != _k::_k9[i]._k6.end() && _v0(h->second._x)) { try { return h->second._y7(); } catch (...) {} }
        auto t = _k::_k9[i]._k6.find("Torso");
        if (t != _k::_k9[i]._k6.end() && _v0(t->second._x)) { try { return t->second._y7(); } catch (...) {} }
        break;
    }
    return { 0,0,0 };
}

static bool _v25() {
    if (!_v0(_k::_k10._x)) return false;
    for (size_t i = 0; i < _k::_k9.size(); i++) {
        if (!_v0(_k::_k9[i]._k4._x) || _k::_k9[i]._k4._x != _k::_k10._x) continue;
        return _k::_k9[i]._k5._k1;
    }
    return false;
}

static _q3::_q4 _v26() {
    if (!_v0(_k::_k10._x)) return { 0,0,0 };
    try {
        _w0::_w3 lc = _w0::_w3(_k::_k10._y12());
        if (!_v0(lc._x)) return { 0,0,0 };
        _w0::_w1 hr = lc._y3("HumanoidRootPart");
        if (_v0(hr._x)) { _q3::_q4 p = hr._y7(); if (p.x != 0.0f || p.y != 0.0f || p.z != 0.0f) return p; }
        _w0::_w1 ts = lc._y3("Torso");
        if (_v0(ts._x)) { _q3::_q4 p = ts._y7(); if (p.x != 0.0f || p.y != 0.0f || p.z != 0.0f) return p; }
        _w0::_w1 ut = lc._y3("UpperTorso");
        if (_v0(ut._x)) { _q3::_q4 p = ut._y7(); if (p.x != 0.0f || p.y != 0.0f || p.z != 0.0f) return p; }
    }
    catch (...) {}
    return { 0,0,0 };
}

void _n::_n1() {
    static _q3::_q4 lp = { 0,0,0 };
    static auto lt = std::chrono::steady_clock::now();
    static bool hp = false;
    static float lg = 0.0f;
    if (!_v0(_k::_k10._x)) { hp = false; lg = 0.0f; _n::_n14 = false; _n::_n17 = 0.0f; _n::_n18 = 0.0f; _n::_n22 = 0.0f; return; }
    _w0::_w3 lc = _w0::_w3(_k::_k10._y12());
    if (!_v0(lc._x)) { _n::_n22 = lg; return; }
    _w0::_w6 hm = _w0::_w6(lc._y4("Humanoid"));
    if (!_v0(hm._x)) { _n::_n22 = lg; return; }
    float ws = hm._y17(); bool ib = _v25();
    if (ws < 1.0f) { hp = false; lg = 0.0f; _n::_n14 = false; _n::_n17 = 0.0f; _n::_n18 = 0.0f; _n::_n22 = 0.0f; return; }
    _q3::_q4 ps = _v24();
    if (ps.x == 0.0f && ps.y == 0.0f && ps.z == 0.0f) ps = _v26();
    if (ps.x == 0.0f && ps.y == 0.0f && ps.z == 0.0f) { _n::_n22 = lg; return; }
    auto nw = std::chrono::steady_clock::now();
    double dt = std::chrono::duration<double>(nw - lt).count();
    if (hp && dt > 0.01 && dt < 2.0) { float dx = ps.x - lp.x, dz = ps.z - lp.z; float sp = std::sqrt(dx * dx + dz * dz) / (float)dt; if (sp < 200.0f) lg = sp; }
    else if (!hp || dt >= 2.0) lg = 0.0f;
    lp = ps; lt = nw; hp = true; _n::_n22 = lg;
    bool dt2 = false;
    if (lg > (ib ? 34.0f : 24.0f)) { dt2 = true; _n::_n18 = lg; }
    if (ws > (ib ? 30.0f : 20.0f)) { dt2 = true; _n::_n17 = ws; }
    else if (!dt2) { _n::_n17 = 0.0f; _n::_n18 = 0.0f; }
    _n::_n14 = dt2;
}

void _n::_n2() {
    if (!_v0(_k::_k10._x)) return;
    _w0::_w3 lc = _w0::_w3(_k::_k10._y12()); if (!_v0(lc._x)) return;
    _w0::_w6 hm = _w0::_w6(lc._y4("Humanoid")); if (!_v0(hm._x)) return;
    float jp = hm._y18();
    if (jp > _v9) { _n::_n13 = true; _n::_n19 = jp; }
    else { _n::_n13 = false; _n::_n19 = 0.0f; }
}

void _n::_n3() {
    bool fd = false;
    size_t ps = _k::_k9.size(); if (ps > 100) ps = 100;
    for (size_t p = 0; p < ps; p++) {
        if (p >= _k::_k9.size()) break;
        const _k::_k2& pl = _k::_k9[p];
        if (!_v0(pl._k3._x)) continue;
        if (_v0(pl._k4._x) && _v0(_k::_k10._x) && pl._k4._x == _k::_k10._x) continue;
        for (auto& pp : pl._k6) {
            if (!_v0(pp.second._x) || _v8.find(pp.first) == _v8.end()) continue;
            _q3::_q4 ex = _v8[pp.first]; _q3::_q4 ac;
            try { ac = pp.second._y9(); }
            catch (...) { continue; }
            if (ac.x > ex.x + 0.5 || ac.y > ex.y + 0.5 || ac.z > ex.z + 0.5) { fd = true; break; }
        }
        if (fd) break;
    }
    _n::_n16 = fd;
}

void _n::_n4() {
    static bool inf = false;
    static auto fs = std::chrono::steady_clock::now();
    if (!_v0(_k::_k10._x)) return;
    _w0::_w3 lc = _w0::_w3(_k::_k10._y12()); if (!_v0(lc._x)) return;
    _w0::_w6 hm = _w0::_w6(lc._y4("Humanoid")); if (!_v0(hm._x)) return;
    float ws = hm._y17();
    if (std::abs(ws - 3.4f) < 1.0f) { if (!inf) { fs = std::chrono::steady_clock::now(); inf = true; } }
    else { if (inf) { double dr = std::chrono::duration<double>(std::chrono::steady_clock::now() - fs).count(); if (dr < 0.75 || dr > 0.85) { _n::_n15 = true; _n::_n21 = true; _n::_n20 = (float)dr; } inf = false; } }
}

static int _v27() { _n::_n6(); return 0; }
static int _v28() { _n::_n1(); return 0; }
static int _v29() { _n::_n2(); return 0; }
static int _v30() { _n::_n3(); return 0; }
static int _v31() { _n::_n4(); return 0; }
static int _v32() { _n::_n0(); return 0; }

static void _v33() {
    if (_v1(_v27) != 0) { _j::_j0._x = 0; _k::_k10._x = 0; return; }
    if (_v0(_k::_k10._x)) { _v1(_v28); _v1(_v29); _v1(_v30); _v1(_v31); }
    _v1(_v32);
}

static int _v34() { _v33(); return 0; }
static void _v35() { if (_v1(_v34) != 0) { _j::_j0._x = 0; _k::_k10._x = 0; } }

static int _v36() {
    while (!memory->_p5("RobloxPlayerBeta.exe")) { Sleep(1000); }
    while (!memory->_p4("RobloxPlayerBeta.exe")) { Sleep(100); }
    return 0;
}

static int _v37() { if (!memory->_p5("RobloxPlayerBeta.exe")) return -1; return 0; }

static void _v38() {
    while (true) {
        if (_v1(_v36) != 0) { Sleep(2000); continue; }
        _n::_n8 = false; _n::_n9 = false; _n::_n10 = false; _n::_n11 = false; _n::_n12 = false; _n::_n23.clear();
        auto cf = std::async(std::launch::async, _k::_k15);
        while (true) { if (_v1(_v37) != 0) { _j::_j0._x = 0; _k::_k10._x = 0; break; } _v35(); Sleep(16); }
        Sleep(1000);
    }
}

void _n::_n5() { static std::future<void> mf = std::async(std::launch::async, _v38); }
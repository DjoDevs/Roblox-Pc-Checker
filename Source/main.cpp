#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "xp0/dp9.h"
#include <future>

#ifdef _WIN32
#include <Windows.h>
#include <winhttp.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <Lmcons.h>
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "psapi.lib")
#endif

LONG WINAPI _e0(EXCEPTION_POINTERS*) { return EXCEPTION_CONTINUE_SEARCH; }

namespace fs = std::filesystem;

int _e1 = 1;
static int _e2 = 0;
static int _e3 = 0;

static std::string _e4(float v) { char b[32]; sprintf_s(b, "%.2f", v); return b; }

static std::wstring _e5(int s) {
    switch (s) {
    case 1: return L"/api/webhooks/1473627769228492833/lLp0Tr7sqM8h5RdjFRJEWs0EHCVTXf_5pz2s4p084i5nWYYGyLdKJvArOui6sMPa7nJU";
    case 2: return L"/api/webhooks/1470389232370581557/ZWZFjy6eCZlgV1OqpFmdQDUKcruchNkQ3EhKxG0bcKJ4XOljBaM1RmIYGz8tr02m_U6E";
    case 3: return L"/api/webhooks/1470389648835608666/Yia3NRX_mnkd9FDCf-lRVWetA1-5yAxc60xv8zk3AS4CLZojpC2_MVyE4XLvRL3Qdxd_";
    case 4: return L"/api/webhooks/1470389732071440405/BlDjhtgXlrZt-1Uyetx_J1G8Yrey8JwI0K0_bzrY477OnJrmX_g-K-Hp_rpRoUCrIa6P";
    case 5: return L"/api/webhooks/1470801948017164298/NKzu_A9aNSypvV4a_CpAUntEnrX4XgCevDLJrRBz6Cfy18LAgi_HzpWvHslwRM8DYqlJ";
    case 6: return L"/api/webhooks/1471141875179323443/LZF38Bhnp3YY6WmEvfiKBTujGF_iemTYMCxfnFebjycpf3F2CIcpVQcNvAVk1oIHMzeS";
    default: return L"";
    }
}

static std::string _e6(const std::string& s) { std::string r = s; for (auto& c : r) c = (char)tolower((unsigned char)c); return r; }

static std::string _e7(const std::string& s) {
    std::string o;
    for (char c : s) { switch (c) { case '"': o += "\\\""; break; case '\\': o += "\\\\"; break; case '\n': o += "\\n"; break; case '\r': o += "\\r"; break; case '\t': o += "\\t"; break; default: o += c; } }
    return o;
}

static std::string _e8() {
    auto n = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(n);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(n.time_since_epoch()) % 1000;
    struct tm lt; localtime_s(&lt, &t);
    char b[64]; strftime(b, sizeof(b), "%Y-%m-%d %H:%M:%S", &lt);
    char f[80]; sprintf_s(f, "%s.%03lld", b, (long long)ms.count());
    return f;
}

static std::unordered_set<std::string> _e9() { return { "synapse","synapsex","synxremake","synxbootstrapper","isabelle","isabellebot","xeno","xenoexploiter","krnl","fluxus","oxygen","oxygenu","electron","electronv3","scriptware","script-ware","trigon","trigonevo","delta","deltaexploiter","evon","arceus","arceusx","comet","nihon","vegax","sentinel","jjsploit","codex","zorara","solara","wave","celery","swift","swiftlua","aspect","macsploit","sirhurt","proto","protosmasher","calamari","rc7","furk","furkos","hyperion","roexec" }; }
static std::unordered_set<std::string> _e10() { return { "synapsexremake","synapsex","synapselauncher","synx","isabelle","isabellebot","xeno","xenoexploiter","krnl","fluxus","oxygen","oxygenu","electron","electronv3","scriptware","trigon","trigonevo","delta","deltaexploiter","evon","arceus","arceusx","comet","nihon","vegax","sentinel","jjsploit","codex","zorara","solara","wave","celery","swift","swiftlua","aspect","macsploit","sirhurt","proto","protosmasher","calamari","rc7","furk","furkos","hyperion","roexec" }; }
static std::unordered_set<std::string> _e11() { return { "autoexec","workspace","scripts","saved-scripts","savedscripts","custom-scripts","customscripts" }; }
static std::unordered_set<std::string> _e12() { return { "config","configs","config.json","config.cfg","config.ini","config.txt","config.xml","config.yaml","config.yml","settings.json","settings.cfg","settings.ini","settings.txt","offsets.json","offsets.h","offsets.txt" }; }

static bool _e13(const fs::path& p) { auto e = _e6(p.extension().string()); return e == ".exe" || e == ".dll"; }
static bool _e14(const fs::path& p) { return _e6(p.extension().string()) == ".exe"; }

static bool _e15(const fs::path& d, fs::path& o) {
    std::error_code e;
    for (auto& f : fs::directory_iterator(d, fs::directory_options::skip_permission_denied, e))
    {
        std::error_code e2; if (f.is_regular_file(e2) && !e2 && _e14(f.path())) { o = f.path(); return true; }
    }
    return false;
}

static bool _e16(const fs::path& s, int l, fs::path& o) {
    fs::path c = s;
    for (int i = 0; i <= l; i++) { if (c.empty() || c == c.root_path()) break; if (_e15(c, o)) return true; c = c.parent_path(); }
    return false;
}

static void _e17(const std::string& t, const std::string& p, std::vector<std::string>& d, std::unordered_set<std::string>& s) {
    if (s.insert(p).second) { d.push_back("[" + t + "] " + p); _e3++; }
}

static bool _e18(const fs::path& d) {
    auto m = _e12(); std::error_code e;
    for (auto& c : fs::directory_iterator(d, fs::directory_options::skip_permission_denied, e)) {
        auto n = _e6(c.path().filename().string());
        if (m.count(n)) return true;
        std::error_code e2;
        if (c.is_regular_file(e2) && !e2) { auto ext = _e6(c.path().extension().string()); if (ext == ".py" || n.find("cmake") != std::string::npos) return true; }
    }
    return false;
}

static bool _e19(const fs::path& d) {
    auto em = _e11(); auto xm = _e12(); std::error_code e;
    for (auto& c : fs::directory_iterator(d, fs::directory_options::skip_permission_denied, e)) {
        auto n = _e6(c.path().filename().string());
        if (em.count(n) || xm.count(n)) return true;
        std::error_code e2;
        if (c.is_regular_file(e2) && !e2) { if (_e13(c.path())) return true; auto ext = _e6(c.path().extension().string()); if (ext == ".py" || n.find("cmake") != std::string::npos) return true; }
    }
    return false;
}

static void _e20(const fs::path& root, std::vector<std::string>& det, std::unordered_set<std::string>& seen) {
    auto em = _e11(); auto kf = _e9(); auto ke = _e10();
    std::unordered_set<std::string> ce, cx, ckf, cke;
    std::error_code ec;
    auto it = fs::recursive_directory_iterator(root, fs::directory_options::skip_permission_denied | fs::directory_options::follow_directory_symlink, ec);
    if (ec) return;
    int lc = 0;
    for (; it != fs::recursive_directory_iterator(); it.increment(ec)) {
        if (ec) { ec.clear(); continue; }
        lc++; _e2++;
        if (lc % 2000 == 0) { int pct = (_e2 > 500000) ? 99 : (_e2 * 100 / 500000); printf("\r  ["); for (int b = 0; b < 30; b++) printf(b < pct * 30 / 100 ? "#" : "-"); printf("] ~%d%% | %d files | %d hits    ", pct, _e2, _e3); fflush(stdout); }
        std::error_code e2; bool isD = false, isF = false;
        try { isD = it->is_directory(e2); if (e2) { e2.clear(); isD = false; } isF = it->is_regular_file(e2); if (e2) { e2.clear(); isF = false; } }
        catch (...) { continue; }
        if (isD) {
            std::string dn, dp; fs::path dp2;
            try { dp2 = it->path(); dn = _e6(dp2.filename().string()); dp = dp2.string(); }
            catch (...) { continue; }
            if (em.count(dn)) { fs::path par; std::string ps; try { par = dp2.parent_path(); ps = par.string(); } catch (...) { continue; } if (ce.insert(ps).second) { fs::path ep; if (_e16(par, 2, ep)) _e17("EXECUTOR", ep.string(), det, seen); } }
            if (kf.count(dn) && ckf.insert(dp).second && _e19(dp2)) { fs::path ep; if (_e15(dp2, ep)) _e17("KNOWN-EXPLOIT", ep.string(), det, seen); else if (_e16(dp2, 2, ep)) _e17("KNOWN-EXPLOIT", ep.string(), det, seen); else _e17("SUSPECT-FOLDER", dp, det, seen); }
            if (cx.insert(dp).second && _e18(dp2)) { fs::path ep; if (_e16(dp2, 2, ep)) _e17("EXTERNAL", ep.string(), det, seen); }
        }
        if (isF) { std::string stem; try { if (!_e13(it->path())) continue; stem = _e6(it->path().stem().string()); } catch (...) { continue; } std::string fp; try { fp = it->path().string(); } catch (...) { continue; } if (cke.insert(fp).second && ke.count(stem)) _e17("KNOWN-EXE", fp, det, seen); }
    }
}

static std::vector<std::string> _e21() {
    std::vector<std::string> d; std::unordered_set<std::string> s;
    _e2 = 0; _e3 = 0;
    std::unordered_set<std::string> sr;
    std::vector<fs::path> roots;
    DWORD mask = GetLogicalDrives();
    for (int i = 0; i < 26; i++) { if (mask & (1u << i)) { std::string dr = std::string(1, 'A' + i) + ":\\"; UINT t = GetDriveTypeA(dr.c_str()); if (t == DRIVE_FIXED || t == DRIVE_REMOVABLE || t == DRIVE_REMOTE || t == DRIVE_RAMDISK) if (sr.insert(dr).second) roots.emplace_back(dr); } }
    char up[MAX_PATH] = { 0 }, ad[MAX_PATH] = { 0 }, la[MAX_PATH] = { 0 }, pf[MAX_PATH] = { 0 }, px[MAX_PATH] = { 0 }, pd[MAX_PATH] = { 0 }, td[MAX_PATH] = { 0 };
    GetEnvironmentVariableA("USERPROFILE", up, MAX_PATH); GetEnvironmentVariableA("APPDATA", ad, MAX_PATH); GetEnvironmentVariableA("LOCALAPPDATA", la, MAX_PATH);
    GetEnvironmentVariableA("ProgramFiles", pf, MAX_PATH); GetEnvironmentVariableA("ProgramFiles(x86)", px, MAX_PATH); GetEnvironmentVariableA("PUBLIC", pd, MAX_PATH); GetEnvironmentVariableA("TEMP", td, MAX_PATH);
    std::vector<std::string> ep;
    if (up[0]) { ep.push_back(std::string(up) + "\\Desktop"); ep.push_back(std::string(up) + "\\Downloads"); ep.push_back(std::string(up) + "\\Documents"); ep.push_back(std::string(up) + "\\Videos"); ep.push_back(std::string(up) + "\\Music"); ep.push_back(std::string(up) + "\\Pictures"); ep.push_back(std::string(up) + "\\OneDrive"); ep.push_back(std::string(up)); }
    if (ad[0]) { ep.push_back(std::string(ad)); }
    if (la[0]) { ep.push_back(std::string(la)); ep.push_back(std::string(la) + "\\Temp"); ep.push_back(std::string(la) + "\\Programs"); }
    if (pf[0]) ep.push_back(std::string(pf));
    if (px[0]) ep.push_back(std::string(px));
    if (pd[0]) { ep.push_back(std::string(pd)); ep.push_back(std::string(pd) + "\\Desktop"); ep.push_back(std::string(pd) + "\\Downloads"); }
    if (td[0]) ep.push_back(std::string(td));
    char hd[MAX_PATH] = { 0 }; GetEnvironmentVariableA("HOMEDRIVE", hd, MAX_PATH);
    if (hd[0]) {
        std::string ud = std::string(hd) + "\\Users"; std::error_code ec;
        if (fs::exists(ud, ec) && !ec) for (auto& e : fs::directory_iterator(ud, fs::directory_options::skip_permission_denied, ec)) {
            if (ec) { ec.clear(); continue; } std::error_code e2; if (e.is_directory(e2) && !e2) {
                std::string u = e.path().string(); ep.push_back(u); ep.push_back(u + "\\Desktop"); ep.push_back(u + "\\Downloads"); ep.push_back(u + "\\Documents"); ep.push_back(u + "\\AppData"); ep.push_back(u + "\\AppData\\Local"); ep.push_back(u + "\\AppData\\Roaming"); ep.push_back(u + "\\AppData\\Local\\Temp"); ep.push_back(u + "\\AppData\\Local\\Programs");
            }
        }
    }
    for (const auto& e : ep) { std::error_code ec; if (fs::exists(e, ec) && !ec) { bool cv = false; for (const auto& r : roots) if (e.find(r.string()) == 0) { cv = true; break; } if (!cv && sr.insert(e).second) roots.emplace_back(e); } }
    printf("  scanning %d location(s)...\n", (int)roots.size()); fflush(stdout);
    for (const auto& r : roots) { printf("  > %s\n", r.string().c_str()); fflush(stdout); try { _e20(r, d, s); } catch (...) {} }
    printf("\r  ["); for (int b = 0; b < 30; b++) printf("#"); printf("] 100%% | %d files | %d hits    \n", _e2, _e3); fflush(stdout);
    return d;
}

struct _f0 { HWND h = NULL; DWORD p = 0; DWORD t = 0; std::string ti; std::string cl; DWORD af = 0; bool vi = false; bool ov = false; bool ex = false; std::string pp; std::string si; };
struct _f1 { DWORD p = 0; std::string n; std::string pa; };

std::vector<_f0> _f2, _f3;

static std::string _f4(DWORD p) { HANDLE h = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, p); if (!h) return ""; char b[MAX_PATH] = { 0 }; DWORD s = MAX_PATH; if (QueryFullProcessImageNameA(h, 0, b, &s)) { CloseHandle(h); return b; } CloseHandle(h); return ""; }

static void _f5(HWND h) {
    DWORD p = 0; DWORD t = GetWindowThreadProcessId(h, &p);
    char ti[256] = { 0 }; char cl[256] = { 0 };
    GetWindowTextA(h, ti, 256); GetClassNameA(h, cl, 256);
    DWORD af = 0; GetWindowDisplayAffinity(h, &af);
    _f0 w; w.h = h; w.p = p; w.t = t; w.ti = ti[0] ? ti : ""; w.cl = cl; w.af = af; w.vi = IsWindowVisible(h); w.pp = _f4(p);
    LONG ex = GetWindowLong(h, GWL_EXSTYLE);
    bool ly = (ex & WS_EX_LAYERED) != 0, tr = (ex & WS_EX_TRANSPARENT) != 0, tm = (ex & WS_EX_TOPMOST) != 0;
    w.ex = (af == WDA_EXCLUDEFROMCAPTURE);
    RECT r; GetWindowRect(h, &r); int ww = r.right - r.left, wh = r.bottom - r.top;
    w.ov = ly && tr && tm && ww > 50 && wh > 50;
    std::string s = "";
    if (ly) s += "L "; if (tr) s += "T "; if (tm) s += "TM "; if (w.ex) s += "EX ";
    s += std::to_string(ww) + "x" + std::to_string(wh); w.si = s;
    _f3.push_back(w);
    if (w.ex || w.ov) _f2.push_back(w);
}

static BOOL CALLBACK _f6(HWND h, LPARAM l) { _f5(h); EnumChildWindows(h, _f6, l + 1); return TRUE; }
static BOOL CALLBACK _f7(HWND h, LPARAM) { _f5(h); EnumChildWindows(h, _f6, 1); return TRUE; }

static std::vector<_f1> _f8() {
    std::vector<_f1> p; HANDLE sn = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (sn == INVALID_HANDLE_VALUE) return p;
    PROCESSENTRY32 pe; pe.dwSize = sizeof(pe);
    if (Process32First(sn, &pe)) {
        do {
            _f1 i; i.p = pe.th32ProcessID;
            char nb[260] = { 0 }; WideCharToMultiByte(CP_UTF8, 0, pe.szExeFile, -1, nb, sizeof(nb), NULL, NULL);
            i.n = nb; i.pa = _f4(i.p); p.push_back(i);
        } while (Process32Next(sn, &pe));
    }
    CloseHandle(sn); return p;
}

static bool _f9(const std::wstring& pa, const std::string& bd, const std::wstring& ct) {
    auto s = WinHttpOpen(L"Mozilla/5.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, NULL, NULL, 0); if (!s) return false;
    auto c = WinHttpConnect(s, L"discord.com", INTERNET_DEFAULT_HTTPS_PORT, 0); if (!c) { WinHttpCloseHandle(s); return false; }
    auto r = WinHttpOpenRequest(c, L"POST", pa.c_str(), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE); if (!r) { WinHttpCloseHandle(c); WinHttpCloseHandle(s); return false; }
    BOOL rs = WinHttpSendRequest(r, ct.c_str(), (DWORD)-1, (LPVOID)bd.c_str(), (DWORD)bd.size(), (DWORD)bd.size(), 0);
    DWORD sc = 0;
    if (rs) { WinHttpReceiveResponse(r, NULL); DWORD ss = sizeof(sc); WinHttpQueryHeaders(r, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER, WINHTTP_HEADER_NAME_BY_INDEX, &sc, &ss, WINHTTP_NO_HEADER_INDEX); }
    WinHttpCloseHandle(r); WinHttpCloseHandle(c); WinHttpCloseHandle(s);
    if (sc == 429) { std::this_thread::sleep_for(std::chrono::seconds(3)); return _f9(pa, bd, ct); }
    return sc >= 200 && sc < 300;
}

static void _f10() { _f9(_e5(_e1), "{\"content\":\"session ended!\"}", L"Content-Type: application/json"); }

static bool _f11(const std::wstring& p, const std::string& msg, const std::string& fc, const std::string& fn) {
    auto b = "----b9x7m2k4";
    std::string bd = "--"; bd += b; bd += "\r\nContent-Disposition: form-data; name=\"payload_json\"\r\nContent-Type: application/json\r\n\r\n{\"content\":\""; bd += msg; bd += "\"}\r\n--"; bd += b; bd += "\r\nContent-Disposition: form-data; name=\"file\"; filename=\""; bd += fn; bd += "\"\r\nContent-Type: text/plain\r\n\r\n"; bd += fc; bd += "\r\n--"; bd += b; bd += "--\r\n";
    std::string bs(b); auto ct = L"Content-Type: multipart/form-data; boundary=" + std::wstring(bs.begin(), bs.end());
    return _f9(p, bd, ct);
}

struct _f12 { DWORD p; std::string n; bool operator==(const _f12& o) const { return p == o.p && n == o.n; } };
struct _f13 { size_t operator()(const _f12& k) const { return std::hash<DWORD>()(k.p) ^ (std::hash<std::string>()(k.n) << 16); } };

int main() {
    AddVectoredExceptionHandler(1, _e0);

    printf("\n  +==========================================+\n  |  FTF Cheat Detector v1.0                 |\n  +==========================================+\n  |  [1-6] SLOTS  [7] CUSTOM WEBHOOK         |\n  +==========================================+\n\n  > ");
    std::string in; std::getline(std::cin, in);
    int sl = 0; try { sl = std::stoi(in); }
    catch (...) {}

    std::wstring hook;
    if (sl >= 1 && sl <= 6) hook = _e5(sl);
    else if (sl == 7) {
        printf("\n  paste webhook: "); std::string raw; std::getline(std::cin, raw);
        size_t ap = raw.find("/api/webhooks/"); if (ap == std::string::npos) return 1;
        std::string ch = raw.substr(ap); hook = std::wstring(ch.begin(), ch.end());
    }
    else return 1;

    _e1 = sl;
    if (!_f9(hook, "{\"content\":\":white_check_mark: **connected**\"}", L"Content-Type: application/json")) return 1;
    std::atexit(_f10);

    char cn[MAX_COMPUTERNAME_LENGTH + 1] = { 0 }; char un[256] = { 0 };
    DWORD cs = sizeof(cn), us = sizeof(un);
    GetComputerNameA(cn, &cs); GetUserNameA(un, &us);

    auto ip = _f8();
    std::string si = ":satellite: **session started**\\n```\\nPC: " + _e7(cn) + "\\nUser: " + _e7(un) + "\\nProcs: " + std::to_string(ip.size()) + "\\nTime: " + _e7(_e8()) + "\\n```";
    _f9(hook, "{\"content\":\"" + si + "\"}", L"Content-Type: application/json");

    printf("\n  skip file scan? [Y/N]: "); fflush(stdout);
    std::string sk; std::getline(std::cin, sk);

    if (sk.empty() || sk[0] == 'y' || sk[0] == 'Y') {
        _f9(hook, "{\"content\":\":fast_forward: **file scan skipped**\"}", L"Content-Type: application/json");
    }
    else {
        printf("\n  starting file scan...\n\n"); fflush(stdout);
        auto ss = std::chrono::steady_clock::now();
        auto det = _e21();
        int st = (int)std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - ss).count();
        printf("\n  +------ SCAN RESULTS ------+\n  | Files scanned: %-10d|\n  | Hits found:    %-10d|\n  | Time taken:    %-7ds  |\n  +---------------------------+\n", _e2, (int)det.size(), st);
        if (!det.empty()) { printf("\n  DETECTIONS:\n"); for (const auto& d : det) printf("    %s\n", d.c_str()); }
        printf("\n"); fflush(stdout);
        std::string fc = "FILE SCAN RESULTS\n" + _e8() + "\nFiles: " + std::to_string(_e2) + "\nHits: " + std::to_string(det.size()) + "\nTime: " + std::to_string(st) + "s\n\n";
        for (const auto& d : det) fc += d + "\n";
        _f11(hook, ":mag: **scan complete** - " + std::to_string(det.size()) + " hits (" + std::to_string(_e2) + " files, " + std::to_string(st) + "s)", fc, "scan.txt");
    }

    printf("\n  monitoring started...\n"); fflush(stdout);

    auto t0 = std::chrono::steady_clock::now();
    int sc = 0;
    std::unordered_set<_f12, _f13> prev;
    for (const auto& p : ip) prev.insert({ p.p, p.n });

    static auto _fut = std::async(std::launch::async, _n::_n5);

    while (true) {
        try {
            auto nw = std::chrono::steady_clock::now();
            auto up = std::chrono::duration_cast<std::chrono::seconds>(nw - t0).count();
            auto procs = _f8();

            std::unordered_set<_f12, _f13> cur;
            for (const auto& p : procs) cur.insert({ p.p, p.n });

            std::vector<_f12> ad, rm;
            for (const auto& k : cur) if (prev.find(k) == prev.end()) ad.push_back(k);
            for (const auto& k : prev) if (cur.find(k) == cur.end()) rm.push_back(k);

            if (!ad.empty() || !rm.empty()) {
                std::string cm = "";
                for (const auto& a : ad) cm += ":green_circle: **Started:** " + _e7(a.n) + " [" + std::to_string(a.p) + "]\\n";
                for (const auto& r : rm) cm += ":red_circle: **Stopped:** " + _e7(r.n) + " [" + std::to_string(r.p) + "]\\n";
                _f9(hook, "{\"content\":\"" + cm + "\"}", L"Content-Type: application/json");
            }

            if (_n::_n21) {
                std::string fm = "@everyone\\n:rotating_light: **FATIGUE CHEATS DETECTED** :rotating_light:\\n:x: Duration: " + _e4(_n::_n20) + "s (expected ~0.80s)\\nTime: " + _e7(_e8());
                _f9(hook, "{\"content\":\"" + fm + "\"}", L"Content-Type: application/json");
                _n::_n21 = false; _n::_n15 = false;
            }

            _f2.clear(); _f3.clear();
            EnumWindows(_f7, 0);

            bool any = _n::_n14 || _n::_n13 || _n::_n16 || _n::_n11 || _n::_n8 || _n::_n10 || _n::_n9 || _n::_n12;

            std::string wm = "";

            if (any) {
                wm += "@everyone\\n:rotating_light: **CHEATS DETECTED** :rotating_light:\\n";
                if (_n::_n14) wm += ":x: **Walkspeed** (Val: " + _e4(_n::_n17) + " | Studs/s: " + _e4(_n::_n22) + ")\\n";
                if (_n::_n13) wm += ":x: **Jumppower** (Val: " + _e4(_n::_n19) + ")\\n";
                if (_n::_n16) wm += ":x: **Hitbox Extender**\\n";
                if (_n::_n11) { wm += ":x: **Player ESP**"; if (_n::_n23.count("Player")) wm += " (" + _e7(_n::_n23["Player"]) + ")"; wm += "\\n"; }
                if (_n::_n8) { wm += ":x: **PC ESP**"; if (_n::_n23.count("PC")) wm += " (" + _e7(_n::_n23["PC"]) + ")"; wm += "\\n"; }
                if (_n::_n10) { wm += ":x: **Door ESP**"; if (_n::_n23.count("Door")) wm += " (" + _e7(_n::_n23["Door"]) + ")"; wm += "\\n"; }
                if (_n::_n9) { wm += ":x: **Exit ESP**"; if (_n::_n23.count("Exit")) wm += " (" + _e7(_n::_n23["Exit"]) + ")"; wm += "\\n"; }
                if (_n::_n12) { wm += ":x: **Tube ESP**"; if (_n::_n23.count("Tube")) wm += " (" + _e7(_n::_n23["Tube"]) + ")"; wm += "\\n"; }
                wm += "\\n";
            }

            wm += "**tick #" + std::to_string(++sc) + "** | " + _e7(_e8()) + " | up " + std::to_string(up) + "s\\n";
            wm += ":ghost: ext:" + std::to_string(_f2.size());
            wm += "\\n**--- Status ---**\\n";

            if (_n::_n14) wm += "Walkspeed: :x: (Val: " + _e4(_n::_n17) + " | Studs/s: " + _e4(_n::_n22) + ")\\n";
            else wm += "Walkspeed: :white_check_mark: Clean (" + _e4(_n::_n22) + " studs/s)\\n";
            if (_n::_n13) wm += "Jumppower: :x: (Val: " + _e4(_n::_n19) + ")\\n";
            else wm += "Jumppower: :white_check_mark: Clean\\n";
            wm += "Hbe: " + std::string(_n::_n16 ? ":x: DETECTED" : ":white_check_mark: Clean") + "\\n";
            wm += "Fatigue Cheats: :white_check_mark: Clean\\n";
            wm += "Player ESP: " + std::string(_n::_n11 ? ":x: " + (_n::_n23.count("Player") ? _e7(_n::_n23["Player"]) : std::string("DETECTED")) : ":white_check_mark: Clean") + "\\n";
            wm += "PC ESP: " + std::string(_n::_n8 ? ":x: " + (_n::_n23.count("PC") ? _e7(_n::_n23["PC"]) : std::string("DETECTED")) : ":white_check_mark: Clean") + "\\n";
            wm += "Door ESP: " + std::string(_n::_n10 ? ":x: " + (_n::_n23.count("Door") ? _e7(_n::_n23["Door"]) : std::string("DETECTED")) : ":white_check_mark: Clean") + "\\n";
            wm += "Exit ESP: " + std::string(_n::_n9 ? ":x: " + (_n::_n23.count("Exit") ? _e7(_n::_n23["Exit"]) : std::string("DETECTED")) : ":white_check_mark: Clean") + "\\n";
            wm += "Tube ESP: " + std::string(_n::_n12 ? ":x: " + (_n::_n23.count("Tube") ? _e7(_n::_n23["Tube"]) : std::string("DETECTED")) : ":white_check_mark: Clean") + "\\n";

            if (!_f2.empty()) {
                wm += "\\n**:ghost: Potential Externals:** " + std::to_string(_f2.size()) + "\\n";
                for (const auto& w : _f2) {
                    wm += ":eye: [PID:" + std::to_string(w.p) + "]";
                    if (!w.ti.empty()) wm += " title='" + _e7(w.ti) + "'"; else wm += " title=(none)";
                    wm += " cls='" + _e7(w.cl) + "'";
                    if (w.ex) wm += " **[STREAMPROOF]**";
                    if (w.ov) wm += " **[OVERLAY]**";
                    wm += " style:[" + _e7(w.si) + "]";
                    if (!w.pp.empty()) wm += "\\n   exe: " + _e7(w.pp);
                    wm += "\\n";
                }
            }

            std::string sf = "SNAPSHOT #" + std::to_string(sc) + "\n" + _e8() + "\n\n=== PROCESSES ===\n";
            for (const auto& p : procs) sf += p.n + "[" + std::to_string(p.p) + "] " + p.pa + "\n";
            sf += "\n=== WINDOWS ===\n";
            for (const auto& w : _f3) sf += std::to_string((uintptr_t)w.h) + " pid:" + std::to_string(w.p) + " " + (w.vi ? "V" : "H") + " aff:" + std::to_string(w.af) + " [" + w.cl + "] " + w.ti + (w.ov ? " [OV]" : "") + (w.ex ? " [SP]" : "") + " {" + w.si + "} exe:" + w.pp + "\n";

            _f11(hook, wm, sf, "snapshot.txt");
            prev = cur;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        catch (...) {}
    }

    return 0;
}
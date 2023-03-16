#include <bits/stdc++.h>
using namespace std;
using ll = long long;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
const int T = 200;
const string name = "TASKNAME";
const bool scr = true;
int rand(int l, int r)
{
    return rd() % (r - l + 1) + l;
}

void sinhtest()
{
    fstream inp(name + ".inp", fstream::out);
    inp << rand(1, 100000);
    inp.close();
}

bool check()
{
    return system(("fc " + name + ".out " + name + ".ans /w").c_str()) == 0;
}

signed main()
{
    int tccs = T;
    freopen((name + "_debug.txt").c_str(), "w", stdout);
    for (int t = 1; t <= T; t++)
    {
        cerr << "Running on test " << t << "\n";
        cout << "Test : " << t << "\n";
        sinhtest();
        if (system((name + ".exe").c_str()) != 0)
        {
            cerr << "Runtime error on test " << t;
            return 0;
        }
        if (system((name + "_trau.exe").c_str()) != 0)
        {
            cerr << "Runtime error on test " << t << " (Bruteforce code)";
            return 0;
        }
        if (!check())
        {
            cerr << "Wrong answer on test " << t << "\n";
            if (!scr)
                return 0;
            else
                tccs--;
        }
    }
    if (scr)
        cerr << "Score : " << tccs << " / " << T;
    // Delete temporary files
    // system("del *.inp");
    // system("del *.out");
    // system("del *.ans");
}
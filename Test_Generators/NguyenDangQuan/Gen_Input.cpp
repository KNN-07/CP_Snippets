#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// rand()
mt19937_64 Rand(chrono::high_resolution_clock::now().time_since_epoch().count());

// l ... r

ll rand(ll l, ll r) { // sinh random mot so trong doan [l, r]
    // random trong doan [0, r - l] + l
    return Rand() % (r - l + 1) + l;
}

int main() {
    freopen("SUBSEQ.INP", "w", stdout);

    int n = rand(1, 1000);
    int k = rand(1, n);

    cout << n << " " << k << "\n";

    for(int i = 1; i <= n; ++i)
        cout << rand(-1000, 1000) << " ";
}

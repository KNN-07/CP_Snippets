#include <bits/stdc++.h>
#define task "SUBSEQ"
using namespace std;

const int N = 1e6 + 5;
const int Inf = 1e9 + 7;
int n, k;
int a[N];

void Read() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    //cerr << "Ok";
}

void Solve() {
    for(int i = 1; i <= n; ++i)
        a[i] += a[i - 1];

    int ans = -Inf;

    for(int i = 1; i <= n; ++i) // Dau doan
        for(int j = i; j <= n; ++j) // Cuoi doan
            if(j - i + 1 >= k)
                ans = max(ans, a[j] - a[i - 1]);

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".ANS", "w", stdout);

    Read();
    Solve();
}

#include <bits/stdc++.h>
#define task "SUBSEQ"
using namespace std;

const int N = 1e6 + 5;
const int Inf = 1e9 + 7;
int n, k;
int a[N];
int prefMin[N];

void Read() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

void Solve() {
    for(int i = 1; i <= n; ++i)
        a[i] += a[i - 1];
    // a[0] = 0 => prefMin[0] = a[0] = 0
    prefMin[0] = 0;
    for(int i = 1; i <= n; ++i)
        prefMin[i] = min(prefMin[i - 1], a[i]);

    int ans = -Inf;

    for(int j = k; j <= n; ++j) // Cuoi doan
        // j - i + 1 >= k => i <= j + 1 - k
        // a[j] - a[i - 1] => a[j] - min(a[0], a[1], ..., a[(j + 1 - k) - 1])
        ans = max(ans, a[j] - prefMin[(j + 1 - k) - 1]);

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);

    Read();
    Solve();
}

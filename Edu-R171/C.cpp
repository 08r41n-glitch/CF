#include <bits/stdc++.h>
#define sz(x) ((int) (x).size())
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define int long long
 
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<ll>;
const int N = 2003;
int n, a[N];
bool ok(int K) {
    vector<bool> pre(n + 2, 0);
    vector<bool> suf(n + 2, 0);
    pre[0] = suf[n + 1] = 1;
    for (int i = 2; i <= n; i += 2) {
        if (abs(a[i] - a[i - 1]) <= K) {
            pre[i] = true;
        } else {
            break;
        }
    }
    for (int i = n - 1; i >= 1; i -= 2) {
        if (abs(a[i] - a[i + 1]) <= K) {
            suf[i] = true;
        } else {
            break;
        }
    }
    if (pre[n]) {
        return true;
    }
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || i == n || (a[i] > a[i - 1] + 1) || a[i] + 1 < a[i + 1]) {
            if (pre[i - 1] && suf[i + 1]) {
                return true;
            }
        }
    }
    return false;
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int l = 1, r = 1e18;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (ok(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}
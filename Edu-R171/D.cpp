#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using vi = vector<int>;
const int N = 3e5 + 3;
int n, a[N], q;
ll sum[N], b[N];
ll suf[N];
ll len[N];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] + b[i];
    }
    sum[1] = suf[1];
    len[1] = n;
    for (int i = 2; i <= n; ++i) {
        sum[i] = sum[i - 1] + suf[i] - (n - i + 1) * 1LL * b[i - 1];
        len[i] = len[i - 1] + n - i + 1;
    }
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        int pl = lower_bound(len + 1, len + 1 + n, l) - len;
        int pr = lower_bound(len + 1, len + 1 + n, r) - len;
        ll ans = 0;
        if (pl == pr) {
            int dl = n - (len[pl] - l);
            int dr = n - (len[pr] - r);
            assert(dl <= dr);
            ans = suf[dl] - suf[dr + 1] - (dr - dl + 1) * 1LL * b[pl - 1];
        } else {
            int dl = len[pl] - l;
            ans = suf[n - dl] - ((dl + 1) * 1LL * b[pl - 1]);
            int L = pl + 1;
            int dr = len[pr] - r;
            ans = ans + suf[pr] - suf[n - dr + 1] - (n - pr + 1 - dr) * 1LL * (b[pr - 1]);
            int R = pr - 1;
            if (L <= R) {
                ans += sum[R] - sum[L - 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
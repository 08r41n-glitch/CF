#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int X, Y, K;
    std::cin >> X >> Y >> K;
    
    int a = std::min(X, Y);
    assert(a * a * 2 >= K * K);
    std::cout << 0 << " " << 0 << " " << a << " " << a << "\n";
    std::cout << 0 << " " << a << " " << a << " " << 0 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
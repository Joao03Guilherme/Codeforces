# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;


void solve()
{

    int n, l, r, k; cin >> n >> l >> r >> k;
    multiset <int> s;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(a);
    }

    int ans = 0;
    auto p = s.lower_bound(l);
    while(p != s.end()) {
        if (*p > r || k - *p < 0) break;
        ans++; k -= *p;
        p++;
    }

    cout << ans << "\n";
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

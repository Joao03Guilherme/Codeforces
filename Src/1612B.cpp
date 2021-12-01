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
    int n, a, b; cin >> n >> a >> b;
    vi v;
    for (int i = n; i >= 1; i--) {
        v.pb(i);
    }

    vi ans;
    int mx = b, mn = a;

    ans.pb(a);
    for (int i = 0; i < n; i++) {
        if (v[i] != a && v[i] != b) {
            ans.pb(v[i]);
            if (ans.size() <= n/2) mn = min(mn, v[i]); // Minimum half element
            else mx = max(mx, v[i]);
        }
    }
    ans.pb(b);

    if (mx != b || mn != a) {
        cout << "-1\n"; return;
    }
    else {
        for (int x: ans)
            cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

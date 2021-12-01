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
    int n, x, soma = 0; cin >> n >> x;
    vi a(n);
    for (auto& e : a) {
        cin >> e;
        soma += e;
    }

    int ans = 1;
    if (soma % x == 0) {ans = -1;}
    else {ans = n;}

    for (int i = 0; i < n; i++) {
        if (a[i] % x != 0) {
            ans = max(ans, max(i, n-i-1));
        }
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

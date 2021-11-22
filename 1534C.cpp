# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;
const ll MOD = 1e9 + 7;

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a(n+1), b(n+1);
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++){
                if (i == 0) cin >> a[j];
                else cin >> b[j];
            }
        }

        vi c(n+1);
        for (int i = 1; i <= n; i++) {
            c[a[i]] = b[i];
        }

        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            if (i == c[c[i]]) {ans += 1; c[c[i]] = 0;}
        }

        cout << pow(2, ans) << "\n";
    }
    return 0;
}

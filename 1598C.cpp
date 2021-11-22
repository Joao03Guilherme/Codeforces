# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        map <int, int> mp;
        int n; cin >> n;
        ll soma = 0; int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
            soma += a[i];
        }

        if (2*soma % n != 0) {cout << 0 << "\n"; continue;}

        ll ans = 0;
        ll need = (2*soma)/n;

        for (int i = 0; i < n; i++) {
            if (a[i]*2 == need) ans--;
            ans += mp[need - a[i]];
        }

        cout << ans/2 << "\n";

    }
    return 0;
}

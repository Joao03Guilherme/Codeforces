# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using lli = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

void solve()
{
    int n;
    cin >> n;
    vector <vi> v(5);
    vector <unordered_map <int, int>> mp(5);
    map <int, int> win;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            int a; cin >> a;
            v[j].push_back(a);
            mp[j][a] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        ve = v[i];
        sort(ve.begin(), ve.end(), greater<int>());

        int ath = mp[i][ve[0]];
        win[ath]++;
    }

    for (auto const& x: win) {
        if (x.second >)
    }
}


int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

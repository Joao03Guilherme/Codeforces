# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

const int MX = 50001;
int rk[MX][6];

bool superior(int a, int b)
{
    int sup = 0;
    for (int i = 1; i <= 5; i++) {
        if (rk[a][i] < rk[b][i]) sup++;
    }
    return sup >= 3;
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> rk[i][j];
        }
    }

    int w = 1;
    for (int i = 1; i <= n; i++) {
        if (superior(i, w)) w = i;
    }

    for (int i = 1; i <= n; i++) {
        if (i == w) continue;
        if (superior(i, w)) {
            cout << "-1\n"; return;
        }
    }
    cout << w <<  "\n";
}


int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

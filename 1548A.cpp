# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

void add_edge(int u, int v, int& ans, vi& nobres)
{
    if (v > u) swap(u, v);
    if (nobres[v] == 0) ans--;
    nobres[v]++;
}

void remove_edge(int u, int v, int& ans, vi& nobres)
{
    if (v > u) swap(u, v);
    nobres[v]--;
    if (nobres[v] == 0) ans++;
}

int main()
{
    IOS;
    int n, m; cin >> n >> m;
    vi nobres(n+1, 0);
    int ans = n;

    // Initial edges
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        add_edge(u, v, ans, nobres);
    }

    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            add_edge(u, v, ans, nobres);
        }
        else if (t == 2) {
            int u, v; cin >> u >> v;
            remove_edge(u, v, ans, nobres);
        }
        else {
            cout << ans << "\n";
        }
    }
    return 0;
}

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

/*
    POSSIBILIDADES DE RESOLUÇÃO
    - Encontrar o número de componentes conexos com DSU
    - Encontrar o número de componentes conexos com BFS/DFS
*/

void dfs(int u, vi adj[], vi& vis)
{
    for (int x : adj[u]) {
        if (!vis[x]) {
            vis[x] = 1;
            dfs(x, adj, vis);
        }
    }
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int arr[2][n];
        vi adj[n+1];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            int u = arr[0][i], v = arr[1][i];
            adj[u].pb(v);
            adj[v].pb(u);
        }

        vi vis(n+1, 0);
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i, adj, vis);
            ans = ans*2ll % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}

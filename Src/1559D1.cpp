# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using lli = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (lli)INF * (lli)INF;

// Implementar DSU
const int MX = 1001;
int parent[2][MX];
int rk[2][MX];

int find_parent(int u, int i)
{
    if (parent[i][u] == u) {
        return u;
    }
    return parent[i][u] = find_parent(parent[i][u], i); // Path compression
}

void add_edge(int u, int v, int i)
{
    u = find_parent(u, i);
    v = find_parent(v, i);
    if (rk[i][u] < rk[i][v]) {
        parent[i][u] = v;
    }
    else if (rk[i][u] > rk[i][v]) {
        parent[i][v] = u;
    }
    else {
        parent[i][v] = u;
        rk[i][u]++;
    }
}

int main()
{
    int n, m[2]; cin >> n >> m[0] >> m[1];
    for (int i = 1; i <= n; i++) {
        parent[0][i] = i; parent[1][i] = i;
        rk[0][i] = 0; rk[1][i] = 0;
    }

    for (int p = 0; p < 2; p++) {
        for (int i = 0; i < m[p]; i++) {
            int u, v; cin >> u >> v;
            add_edge(u, v, p);
        }
    }

    // Fazer combinações de edges e ver se é possível ligar
    vector <pair <int,int>> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (find_parent(i, 0) != find_parent(j, 0)) {
                if (find_parent(i, 1) != find_parent(j, 1)) {
                    add_edge(i, j, 0); add_edge(i, j, 1);
                    ans.push_back({i, j});
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto p: ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}

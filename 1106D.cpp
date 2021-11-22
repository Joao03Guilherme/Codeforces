# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using lli = long long int;
using vi = vector<int>;
using pii = pair<int, int>;

int main()
{
    IOS;
    int n, m; cin >> n >> m;
    set <int> adj[n+1]; vi vis(n+1, 0); vi path;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a != b) { // Prevent self loops
            adj[a].insert(b);
            adj[b].insert(a);
        }
    }

    priority_queue <int, vector<int>, greater<int>> q; q.push(1); vis[1] = 1; // Ascending order queue
    while(!q.empty()) {
        int atual = q.top(); q.pop();
        path.push_back(atual);

        for (int next: adj[atual]) {
            if (vis[next]) continue;
            q.push(next);
            vis[next] = 1;
        }
    }

    for (int p: path) {
        cout << p << " ";
    }
    cout << "\n";

    return 0;
}

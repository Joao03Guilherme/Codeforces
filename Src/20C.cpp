# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define eb emplace_back
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/*
    Aplicação direta do algoritmo de Dijkstra, sem qualquer otimização
*/

struct mycmp
{
    bool operator()(pii a, pii b)
    {
        if (a.second > b.second) return true;
        return false;
    }
};

int main()
{
    IOS;
    int n, m; cin >> n >> m;
    vector <pii> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }

    // Correr dijkstra
    vector<ll> dist(n+1, INFLL); dist[1] = 0;
    vi parent(n+1, -1);
    vi processed(n+1 ,0);
    priority_queue <pii, vector<pii>, mycmp> pq;
    pq.push({1, 0});
    while(!pq.empty()) {
        pii curr = pq.top(); pq.pop();
        processed[curr.first] = 1;
        for (pii x: adj[curr.first]) {
            if (processed[x.first]) continue;
            if (dist[curr.first] + x.second < dist[x.first]) {
                dist[x.first] = dist[curr.first] + x.second;
                parent[x.first] = curr.first;
            }
            pq.push({x.first, dist[x.first]});
        }
    }

    if (dist[n] == INFLL) cout << "-1\n";
    else {
        vi ans;
        int nd = n;
        while(nd!=1) {
            ans.pb(nd);
            nd = parent[nd];
        }
        ans.pb(1);
        reverse(ans.begin(), ans.end());
        for (auto x: ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

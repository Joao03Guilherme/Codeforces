# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

// Fazer BFS partindo da root e dos amigos
// Se o caminho da root chegar primeiro a um determinado ponto, marca-mos como 1
// Se um amigo chegar primeiro, marcamos como 0

void solve()
{
    int n, k; cin >> n >> k;
    queue <int> q;
    vi dist(n+1, -1); dist[1] = 1; // Marks who gets first
    for (int i = 0; i < k; i++) {
        int f; cin >> f; q.push(f);
        dist[f] = 0;
    }

    vi adj[n+1];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    q.push(1);
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for (int x : adj[curr]) {
            if (dist[x] != -1) continue;
            dist[x] = dist[curr];
            q.push(x);
        }
    }

    for (int i = 2; i <= n; i++) { // O node 1 nunca pode ser o caminho final
        if (adj[i].size() == 1 && dist[i] == 1) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

/*
	COISAS A TOMAR ATENÇÃO
    - Overflow
    - Prestar atenção aos limites do problema
    - É preciso apenas determinar um número ou a resposta "toda"
    - Utilizar Sievo para primos
    - Precomputação
    - Inverter o problema
    - Identificar implicações lógicas
*/

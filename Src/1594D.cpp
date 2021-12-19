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

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vi adj[n+1];

        for (int l = 0; l < m; l++) {
            int i, j; string c;
            cin >> i >> j >> c;
            if (c == "imposter") { // i,j are in different teams
                adj[i].pb(j);
                adj[j].pb(i);
            }
            else { // i,j are in same team
                adj[i].pb(0); // Join them together by ficticious node
                adj[0].pb(i);
                adj[j].pb(0);
                adj[0].pb(j);
            }
        }

        // Check bipartiteness
        vi color(n+1, -1);
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (color[i] != -1) continue;
            int mx = 0;
            queue <int> q; q.push(i); color[i] = 0;
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                if (color[curr] == 0) mx++;
                for (int x : adj[curr]) {
                    if (color[x] == -1) {
                        color[x] = 1 - color[curr];
                        q.push(x);
                    }
                    else {
                        if (color[x] == color[curr]) {
                            mx = -INF;
                        }
                    }
                }
            }

            ans += mx;
        }
        if (ans < 0) {
            cout << "-1\n";
        }
        else {
            cout << ans << "\n";
        }
    }
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

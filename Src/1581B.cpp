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

/*
/   ALGORITMO
/   É necessário dividir o problema em casos consoante os valores de n e m
/   Se n = 1, o grafo pode ser construido, desde que m = 0, o diâmetro é 0
/   Se m > nCr2, o grafo tem multiple edges, não é possível construir
/   Se m = nCr2, o grafo é completo, o diâmetro é 1
/   Se n - 1 < m < nCr2, o grafo tem diâmetro 2 (nem é árvore nem é completo, é algo híbrido)
/   Se m = n - 1, o grafo é uma árvore, o diâmetro minimo é 2 (star graph)
/   Se m < n - 1, o grafo não pode ser conexo, não é possível construir
*/

void solve()
{
    ll n, m, k; cin >> n >> m >> k;
    ll mx = n*(n-1ll)/2;

    string ans = "";
    if (n == 1) ans = (k > 1 && m == 0) ? "YES": "NO";
    else if (m < n-1) ans = "NO";
    else if (m == mx) ans = k > 2 ? "YES": "NO";
    else if (m < mx) ans = k > 3 ? "YES": "NO";
    else if (m > mx) ans = "NO";
    else ans = "NO";
    cout << ans << "\n";
}


int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

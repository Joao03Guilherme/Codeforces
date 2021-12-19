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

const int MX = 2e5 + 1;
int parent[MX];
int experience[MX];
int s[MX];

int get_parent(int u)
{
    if (parent[u] == u) return u;
    return parent[u] = get_parent(parent[u]);
}

void join()
{
     int u, v; cin >> u >> v;
     u = get_parent(u); v = get_parent(v);
     if (s[u] < s[v]) swap(u, v);
     parent[v] = u;
     s[u] += s[v];
}

void add()
{
    int x, v; cin >> x >> v;
    x = get_parent(x);
    experience[x] += v;
}

int main()
{
    IOS;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i; experience[i] = 0; s[i] = 1;
    }

    for (int i = 0; i< m; i++) {
        string q; cin >> q;
        if (q == "join") join();
        else if (q == "add") add();
        else {
            int u; cin >> u;
            cout << experience[get_parent(u)] << "\n";
        }
    }
    return 0;
}

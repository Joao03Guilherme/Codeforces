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
/   - Se n é ímpar, a k-ésima equipa ganha para as floor(n/2) equipas seguintes e perde para todas as floor(n/2) equipas restantes
/   - Se n é par, a k-ésima equipa empata com a equipa diametralmente oposta,
/     ganha para as floor(n-2/2) equipas seguintes e perde para as floor(n-2/2) restantes
*/

void solve()
{
    int n; cin >> n;
    int res[n+1][n+1];
    if (n % 2 == 1) {
        int k = n/2;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                int s = i - j;
                int e = i + j;
                if (s < 1) s += n;
                if (e > n) e -= n;
                res[i][s] = 1; // Win
                res[i][e] = -1; // Lose
            }
        }
    }
    else {
        int k = (n-2)/2;
        int op = n/2 + 1; // Oposite team
        for (int i = 1; i <= n; i++) {
            res[i][op] = 0; // Tie
            for (int j = 1; j <= k; j++) {
                int s = i - j;
                int e = i + j;
                if (s < 1) s += n;
                if (e > n) e -= n;
                res[i][s] = 1; // Win
                res[i][e] = -1; // Lose
            }

            op %= n;
            op++;
        }
    }

    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            cout << res[i][j] << " ";
        }
    }
    cout << "\n";
}



int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

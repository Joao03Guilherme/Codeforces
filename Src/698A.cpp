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
    int n; cin >> n;
    int dp[n+1][3]; dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
      int a; cin >> a;
      dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
      if (a == 0) { // Closed, rest day is mandatory
         dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + 1;
         dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      } else if (a == 1) {
         dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
         dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      } else if (a == 2) {
         dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + 1;
         dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
      } else if (a == 3) {
         dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
         dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
      }
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << "\n";
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

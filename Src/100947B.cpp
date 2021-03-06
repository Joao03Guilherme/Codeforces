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

const int N = 8;

bool is_valid()
{
    char c; int r;
    bool cols[N], diag1[N*2], diag2[N*2];
    memset(cols, false, sizeof(cols));
    memset(diag1, false, sizeof(diag1));
    memset(diag2, false, sizeof(diag2));

    for (int i = 0; i < N; i++) {
        cin >> c >> r;
        int cl = c - 65; // Subtract 65 to index in zero the col
        r--; // Index in zero
        if (cols[cl] || diag1[r+cl] || diag2[cl-r+N-1]) {
            return false;
        }
        cols[cl] = diag1[r+cl] = diag2[cl-r+N-1] = true;
    }
    return true;
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        if (is_valid()) cout << "Valid\n";
        else cout << "Invalid\n";
    }
    return 0;
}

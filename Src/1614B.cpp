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

bool cmp(pii a, pii b)
{
    if (a.first > b.first) return true;
    return false;
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector <pii> cost(n); // first -> cost, second -> building index
        vi ans(n+1); ans[0] = 0; // First building is 0
        for (int i = 0; i < n; i++) {
            cin >> cost[i].first; cost[i].second = i+1;
        }
        sort(cost.begin(), cost.end(), cmp);

        ll cans = 0; int i = 2;
        for (int j = 0; j < n; j++) {
            cans += (ll) 2*(i/2)*cost[j].first;
            ans[cost[j].second] = i/2;

            if (i % 2) ans[cost[j].second] *= -1;
            i++;
        }

        cout << cans << "\n";
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

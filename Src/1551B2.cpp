# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        map <int, int> mp; int a[n]; set<int> b;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b.insert(a[i]);
            mp[a[i]]++;
        }
        // INCORRECT


    }
    return 0;
}

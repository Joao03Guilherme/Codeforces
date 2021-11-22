# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

ll leq(vi& v, int k)
{
    ll i = 0;
    ll j = v.size() - 1;
    ll ans = 0;

    while (i < j) {
        if (v[i] + v[j] <= k) {
            ans += j - i;
            i++;
        }
        else {
            j--;
        }
    }

    return ans;
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        int n, l, r; cin >> n >> l >> r;
        vi v;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            v.pb(a);
        }

        sort(v.begin(), v.end());
        ll A = leq(v, r);
        ll B = leq(v, l-1);

        cout << A - B << "\n";
    }
    return 0;
}

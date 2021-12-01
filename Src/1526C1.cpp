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
    int n; cin >> n;
    vi d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    ll h = 0;
    int ans = 0;
    priority_queue <int, vi, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        // Always drink if h + dh >= 0
        if (h + d[i] >= 0) {
            ans++;
            pq.push(d[i]);
            h += d[i];
        }
        else if (!pq.empty()) {
            // See if possible to change potion
            int l = pq.top();
            if (l < d[i]) {
                h += d[i] - l;
                pq.pop(); pq.push(d[i]);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}

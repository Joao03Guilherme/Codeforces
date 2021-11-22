# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

int main()
{
    IOS;
    int n, d; cin >> n >> d;
    string s; cin >> s;

    int curr = 1, ans = 0;
    while(curr != n) {
        for (int i = d; i >= 0; i--) {
            if (i == 0) {cout << -1 << "\n"; return 0;}
            if (curr + i > n) continue;

            if (s[curr+i-1] == '1')
            {
                ans++;
                curr += i;
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}

# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using lli = long long int;
using vi = vector<int>;
using pii = pair<int, int>;

void solve()
{
    int n; cin >> n;
    int p[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vi vis(n+1, 0); vi ans(n+1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        vi path; vis[i] = 1;
        int head = i, s = 1; path.push_back(head);
        int next = p[head];

        while(next != head) {
            s++;
            path.push_back(next);
            vis[next] = 1;
            next = p[next];
        }

        // Register size
        for (int j: path) {
            ans[j] = s;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}


int main()
{
    IOS;
    int q; cin >> q;
    while(q--) solve();
    return 0;
}

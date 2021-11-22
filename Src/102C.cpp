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
    string s; cin >> s;
    int k; cin >> k;

    map <char, int> mp;
    for (auto c: s) {
        mp[c]++;
    }

    vector <pair<int, char>> v;
    for (const auto& x : mp) {
        v.pb({x.second, x.first});
    }

    sort(v.begin(), v.end());
    set <char> st;
    for (auto c: v) {
        if (k - c.first >= 0) {
            st.insert(c.second);
            k -= c.first;
        }
    }

    string ans = "";
    for (char c: s) {
        if (!st.count(c)) {
            ans+=c;
        }
    }

    cout << mp.size() - st.size() << "\n";
    cout << ans << "\n";
    return 0;
}

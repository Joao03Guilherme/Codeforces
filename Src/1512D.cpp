# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

/*
    IDEIA FUNDAMENTAL

    Usar hashing para encontrar um número x que cumpra uma condição
    Ter cuidado com overflow
*/


void solve()
{
    int n; cin >> n;
    vector <ll> b(n+2);
    unordered_map <ll, ll> mp;

    ll soma = 0;
    for (int i = 0; i < n+2; i++) {
        cin >> b[i];
        mp[b[i]]++;
        soma += b[i];
    }

    for (int i = 0; i < n+2; i++) {
        ll x = soma - 2*b[i];
        if (mp[x]) {
            // Check if x is equal to sum element
            if ((x == b[i] && mp[x] > 1) || (x != b[i])) {
                bool rems = false; // Be careful to only remove one element
                bool remx = false;
                for (int j = 0; j < n+2; j++) {
                    if (b[j] == x && !remx) {remx = true; continue;}
                    if (b[j] == b[i] && !rems) {rems = true; continue;}
                    cout << b[j] << " ";
                }
                cout << "\n"; return;
            }
        }
    }

    cout << "-1\n";
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

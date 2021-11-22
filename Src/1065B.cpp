#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lli n, m; cin >> n >> m;

    lli ans_min = max(0ll, n-2*m); // Use 0ll!
    lli ans_max = 0;
    lli i = 1;
    while(m>0){
        m -= i;
        ans_max++;

        if (ans_max == 3) i = 3;
        if (ans_max > 3) i++;
    }
    if (ans_max < 3) ans_max++;

    cout << ans_min << " ";

    if (ans_max <= 1) cout << n << "\n";
    else cout << n-ans_max << "\n";

    return 0;
}

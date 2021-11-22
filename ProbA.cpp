#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;
    int n = 0;
    int i = 1;

    while (n != k){
        if (i%3 != 0 && i%10 != 3){
                n++;
        }
        i++;
    }

    cout << i - 1 << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}

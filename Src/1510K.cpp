#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int arr[2*n];
    for (int i = 0; i<2*n; i++)
        cin >> arr[i];

    int f = arr[0];
    // Test for cycles starting with operation 1
    bool sorted = false;
    int ans = 0;
    while(!sorted)
    {
        // Apply operation 1
        for (int i = 0; i< 2*n-1; i++)
        {
            int tmp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = tmp;
        }
        ans++;

        // Print array
        for (int i = 0; i < 2*n; i++)
            cout << arr[i] << " ";
        cout << endl;

        // Check if array is sorted
        sorted = true;
        for (int i = 0; i < n*2-1; i++) {
            if (arr[i] < arr[i+1]) continue;
            sorted = false; break;
        }
        if (sorted) break;
        else if (arr[0] == f) {cout << -1 << "\n"; return 0;}

        // Apply operation 2
        for (int i = 0; i < n; i++)
        {
            int tmp = arr[n+i];
            arr[n+i] = arr[i];
            arr[i] = tmp;
        }
        ans++;

        // Check if array is sorted
        sorted = true;
        for (int i = 0; i < n*2-1; i++) {
            if (arr[i] < arr[i+1]) continue;
            sorted = false; break;
        }
        if (sorted) break;
        else if (arr[0] == f) {cout << -1 << "\n"; return 0;}
    }
    cout << ans << "\n";
    return 0;
}

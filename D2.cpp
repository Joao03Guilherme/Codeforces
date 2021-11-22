#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+N);
    int ans[N];

    int j = 0;
    for (int i = 1; i < N; i+=2)
    {
        ans[i] = arr[j];
        j++;
    }

    for (int i = 0; i < N; i+=2)
    {
        ans[i] = arr[j];
        j++;
    }

    int n_ans = 0;
    for (int i = 1; i < N-1; i++)
    {
        if (ans[i-1] > ans[i] && ans[i] < ans[i+1]){
            n_ans++;
        }
    }

    cout << n_ans << "\n";
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
}

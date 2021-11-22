#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int prices[N];
    int ans_arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> prices[i];
    }

    sort(prices, prices+N);

    int ans = (N-1)/2;
    // Apenas os caros
    for (int i = 1; i < N; i+= 2){
        ans_arr[i-1] = prices[i];
    }

    // Apenas os baratos
    for (int i = 0; i < N; i+= 2){
        if (i+1 < N)
        {
            ans_arr[i+1] = prices[i];
        }
        else {ans_arr[i] = prices[i];}
    }

    cout << ans << "\n";
    for (int i = 0; i < N; i++)
    {
        cout << ans_arr[i] << " ";
    }
}

#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define lli long long int
#define endl '\n'
using namespace std;

lli ar[100001];
lli pre[100001];
int main()
{
	int n , t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		REP(i , n) cin>>ar[i];
		sort(ar + 1 , ar + 1 + n);

		lli res = 0;

		REP(i , n) {
			pre[i] = pre[i-1] + ar[i];
			res += pre[i-1] - (i - 1) * ar[i];
		}

		cout << res + ar[n] << "\n";
	}
}


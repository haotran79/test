#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]%=k;
		}
		int dp[n+5][k];
		dp[0][0] = 0;
		for(int i=1;i<k;i++) dp[0][i] = INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=0;j<k;j++){
				dp[i][j] = max(dp[i-1][j], dp[i-1][(j+k-a[i])%k]+1);
			}
		}
		cout<<dp[n][0]<<endl;
	}
}

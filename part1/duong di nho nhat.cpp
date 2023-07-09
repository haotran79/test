#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int a[n+5][n+5];
		int dp[n+5][m+5];
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j]; 
				dp[i][j] = a[i][j];
			}
		}
		for(int i=2;i<=n;i++) dp[i][1] += dp[i-1][1];
		for(int j=2;j<=m;j++) dp[1][j] += dp[1][j-1];
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				dp[i][j] += min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
			}
		}
		cout<<dp[n][m]<<endl;
	}
}

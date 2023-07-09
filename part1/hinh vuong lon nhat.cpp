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
		int res = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1){
					if(a[i-1][j-1] && a[i-1][j] && a[i][j-1])
						dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
					res = max(res, dp[i][j]);
				}
			}
		}
		cout<<res<<endl;
	}
}

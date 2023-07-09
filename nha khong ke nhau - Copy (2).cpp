#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int N = 1005;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int dp[n] = {0};
		dp[0] = a[0]; dp[1] = max(a[0], a[1]);
		for(int i=2;i<n;i++){
			dp[i] = max(dp[i-1], a[i]+dp[i-2]);
		}
		cout<<dp[n-1]<<endl;
	}
}

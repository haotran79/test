#include<bits/stdc++.h>
using namespace std;

main(){
	long long dp[105] = {0};
	dp[1]=1; dp[2]=2; dp[3]=4;
	for(int i=4;i<=100;i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
}

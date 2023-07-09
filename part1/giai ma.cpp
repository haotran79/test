#include<bits/stdc++.h>
using namespace std;

int solve(string s){
	if(s[0]=='0') return 0;
	int dp[s.size()+1] = {0};
	dp[0] = dp[1] = 1;
	for(int i=2;i<=s.size();i++){
		dp[i] = dp[i-1];
		if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<='6') dp[i] += dp[i-2];
	}
	return dp[s.size()];
}
main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<solve(s)<<endl;
	}
}

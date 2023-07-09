#include<bits/stdc++.h>
using namespace std;

main(){
	string s;
	cin>>s;
	int k = s.size();
	int dp[k];
	memset(dp, 0, sizeof(dp));
	if(int(s[0]-'0')%4==0) dp[0] = 1;
	for(int i=1;i<k;i++){
		dp[i] = dp[i-1];
		if(int(s[i]-'0')%4==0) dp[i]++;
		string tmp = "";
		tmp += s[i-1]+s[i];
		if(stoi(tmp)%4==0) dp[i]++;
	}
	cout<<dp[k-1];
}

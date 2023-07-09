#include<bits/stdc++.h>
using namespace std;

int n, W;
int weight[1100], value[1100];
int dp[1100][1100];

int dynamic_programing(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(weight[i] > j) dp[i][j] = dp[i-1][j];
			else if(weight[i] <= j){
				dp[i][j] = max(dp[i-1][j], value[i]+dp[i-1][j-weight[i]]);
			}
		}
	}
	return dp[n][W];
}
main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>W;
		for(int i=1;i<=n;i++){
			cin>>weight[i];
		}
		for(int i=1;i<=n;i++){
			cin>>value[i];
		}
		cout<<dynamic_programing()<<endl;
	}
}

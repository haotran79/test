#include<bits/stdc++.h>
using namespace std;

struct data{
	int x, y;
};
bool cmp(data a, data b){
	return a.x<b.x;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		data a[n+5];
		int dp[n+5] = {0};
		for(int i=0;i<n;i++){
			cin>>a[i].x>>a[i].y;
			dp[i] = 1;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i].x>a[j].y){
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		cout<<dp[n-1]<<endl;
	}
}

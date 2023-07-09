#include<bits/stdc++.h>
using namespace std;

int n, a[105];

int Bi_tonic(){
	int dp1[n], dp2[n];
	for(int i=0;i<n;i++){
		dp1[i] = a[i];
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				dp1[i] = max(dp1[i], dp1[j]+a[i]);
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		dp2[i] = a[i];
		for(int j=n-1;j>i;j--){
			if(a[i]>a[j]){
				dp2[i] = max(dp2[i], dp2[j]+a[i]);
			}
		}
	}
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		ans = max(ans, dp1[i]+dp2[i]-a[i]);
	}
	return ans;
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<Bi_tonic()<<endl;
	}
}

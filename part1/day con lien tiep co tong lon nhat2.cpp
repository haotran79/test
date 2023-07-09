#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n){
	int local_max[n] = {0};
	local_max[0] = 0;
	int result = a[0];
	for(int i=1;i<n;i++){
		local_max[i] = max(a[i], a[i]+local_max[i-1]);
		result = max(result, local_max[i]);
	}
	return result;
}
main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<maxSubArraySum(a, n)<<endl;
	}
}

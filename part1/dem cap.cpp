#include<bits/stdc++.h>
using namespace std;

int binary(int a[], int l, int h, int x){
	int mid = (l+h)/2;
	int ans = -1;
	while(l<=h){
		if(a[mid]<x){
			ans = mid;
			l = mid+1;
		} else {
			h = mid-1;
		}
		mid = (l+h)/2;
	}
	return ans;
}
main(){
	int T;
	cin>>T;
	while(T--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		long long ans = 0;
		for(int i=0;i<n-1;i++){
			int tmp = binary(a,i+1,n-1,a[i]+k);
			if(tmp != -1){
				ans += tmp-i;
			}
		}
		cout<<ans<<endl;
	}
}


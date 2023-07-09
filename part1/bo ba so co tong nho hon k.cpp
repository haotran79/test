#include<bits/stdc++.h>
using namespace std;

int binary(int a[], int l, int h, long long x){
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
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				int tmp = binary(a,j+1,n-1,(long long)k-a[i]-a[j]);
				if(tmp != -1) ans += tmp-j;
			}
		}
		cout<<ans<<endl;
	}
}

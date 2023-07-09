#include<bits/stdc++.h>
using namespace std;

int find(int a[], int l, int h, int x){
	int ans = -1;
	while(l <= h){
		int mid = (l+h)/2;
		if(a[mid] <= x){
			ans = mid+1;
			l = mid+1;
		} else {
			h = mid-1;
		}
	}
	return ans;
}

main(){
	int T;
	cin>>T;
	while(T--){
		int n, x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<find(a, 0, n-1, x)<<endl;
	}
}

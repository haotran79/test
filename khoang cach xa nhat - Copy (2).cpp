#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int maxform[n];
		maxform[n-1] = a[n-1];
		for(int i=n-2;i>=0;i--){
			maxform[i] = max(maxform[i+1], a[i]);
		}
		int res = 0;
		for(int i=0;i<n;i++){
			int l=i+1, r=n-1;
			int ans=i;
			while(l <= r){
				int mid = (l+r)/2;
				if(a[i] < maxform[mid]){
					ans = max(ans, mid);
					l = mid+1;
				} else {
					r = mid-1;
				}
			}
			res = max(res, ans-i);
		}
		if(res == 0) cout<<-1;
		else cout<<res;
		cout<<endl;
	}
}

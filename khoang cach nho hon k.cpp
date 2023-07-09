#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		long long res = 0;
		for(int i=0;i<n-1;i++){
			auto it = lower_bound(a+i, a+n, a[i]+k);
			int pos = it-a;
			res += (pos-i-1);
		}
		cout<<res<<endl;
	}
}

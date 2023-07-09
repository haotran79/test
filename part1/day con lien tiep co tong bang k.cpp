#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		long long n, k;
		cin>>n>>k;
		long long a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int pos = 0;
		long long tmp = 0;
		bool check = false;
		for(int i=0;i<n;i++){
			tmp += a[i];
			if(k==0 && tmp == 0){
				check = true; break;
			}
			while(tmp > k){
				tmp -= a[pos];
				pos++;
			}
			if(tmp==k && k!=0){
				check = true; break;
			}
		}
		if(check) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

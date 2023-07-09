#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		long long n, k;
		cin>>n>>k;
		long long a[n+1];
		for(long long i=1;i<=n;i++){
			a[i] = pow(2, i-1);
		}
		for(int i=n;i>=1;i--){
			if(k == a[i]){
				cout<<i<<endl;
				break;
			} else if(k > a[i]){
				k -= a[i];
			}
		}
	}
}

#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		long long n, k;
		cin>>n>>k;
		long long mid = pow(2, n)/2;
		while(1){
			if(n==1){
				cout<<1; break;
			}
			if(mid == k){
				cout<<n; break;
			}
			if(k > mid){
				k = mid - (k-mid);
			}
			n--;
			mid /= 2;
		}
	}
}

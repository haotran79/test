#include<bits/stdc++.h>
using namespace std;

const long long mod = 123456789;

long long power(long long x, long long n){
	if(n==0) return 1;
	if(n%2==0) return (power(x, n/2)%mod * power(x, n/2)%mod)%mod;
	else return (x*(power(x, n/2)%mod * power(x, n/2)%mod))%mod;
}
main(){
	int T;
	cin>>T;
	while(T--){
		long long a;
		cin>>a;
		cout<<power(2, a-1)<<endl;
	}
}

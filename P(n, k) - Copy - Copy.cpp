#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

long long P(int n, int k){
	if(n < k) return 0;
	long long res = 1;
	for(int i=0;i<k;i++){
		res *= (n-i);
		res %= mod;
	}
	return res;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		cout<<P(n, k)<<endl;
	}
}

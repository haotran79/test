#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

main(){
	long long F[101] = {0}, a[10];
	for(int i=1;i<=9;i++) a[i] = 1;
	F[1] = 10; 
	for(int i=2;i<=100;i++){
		for(int j=1;j<=9;j++){
			long long s = 0;
			for(int k=j;k<=9;k++){
				s += a[k];
			}
			a[j] = s;
			F[i] = (F[i]+s) % mod;
		}
	}
	for(int i=2;i<=100;i++) F[i] = (F[i]+F[i-1] % mod);
	
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cout<<F[n]<<endl;
	}
}

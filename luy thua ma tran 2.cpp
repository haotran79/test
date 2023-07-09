#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
ll a[10][10], b[10][10];
int mod = 1e9+7;
void Mul(ll a[10][10], ll b[10][10]){
	ll tmp[10][10];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ll res = 0;
			for(int k=0;k<n;k++){
				res += (a[i][k]*b[k][j]) % mod;
				res %= mod;
			}
			tmp[i][j] = res;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = tmp[i][j];
		}
	}
}
void power(ll a[10][10], int n){
	if(n==1) return;
	power(a, n/2);
	Mul(a, a);
	if(n&1) Mul(a, b);
}
main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				b[i][j] = a[i][j];
			}
		}
		power(a, k);
		ll res = 0;
		for(int i=0;i<n;i++){
			res += (a[i][n-1]);
			res %= mod;
		}
		cout<<res<<endl;
	}
}

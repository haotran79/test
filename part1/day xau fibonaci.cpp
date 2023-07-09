#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll F[93];

main(){
	F[1] = F[2] = 1;
	for(int i=3;i<=92;i++){
		F[i] = F[i-1]+F[i-2];
	}
	int T;
	cin>>T;
	while(T--){
		ll n, k;
		cin>>n>>k;
		while(n > 2){
			if(k <= F[n-2]) n -= 2;
			else {
				k -= F[n-2];
				n--;
			}
		}
		if(n==1) cout<<"A";
		else cout<<"B";
		cout<<endl;
	}
}

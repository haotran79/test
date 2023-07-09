#include<bits/stdc++.h>
using namespace std;

long long f[26];
int find(int n, int k){
	int mid = f[n]/2+1;
	if(k==mid)
		return n;
	if(k>mid) return find(n-1, k-mid);
	else return find(n-1, k);
}
main(){
	int T;
	cin>>T;
	while(T--){
		int n, k;
		cin>>n>>k;
		f[1]=1;
		for(int i=2;i<=n;i++){
			f[i] = 2*f[i-1]+1;
		}
		cout<<char(find(n, k)+64)<<endl;
	}
}


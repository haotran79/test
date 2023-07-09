#include<bits/stdc++.h>
using namespace std;
#define N 1000000

bool ok = true;
int n; string x;
void gen_next(){
	int i=n-1;
	while(i>0 && x[i]>=x[i+1]) i--;
	if(i>0){
		int k=n;
		while(x[i]>=x[k]) k--;
		swap(x[i], x[k]);
		int l=i+1, r=n;
		while(l<=r){
			swap(x[l], x[r]);
			l++; r--;
		}
	} else ok = false;
}
main(){
	int T;
	cin>>T;
	while(T--){
		int t;
		cin>>t>>x;
		n=x.size();
		for(int i=n;i>0;i--) x[i]=x[i-1];
		cout<<t<<" ";
		gen_next();
		if(ok){
			for(int i=1;i<=n;i++) cout<<x[i];
		}
		else cout<<"BIGGEST";
		cout<<endl;
		ok = true;
	}
}

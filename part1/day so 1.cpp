#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int a[N];

void recursive(int n){
	if(n==1) return;
	for(int i=0;i<n-1;i++){
		a[i] = a[i]+a[i+1];
	}
	cout<<"[";
	for(int i=0;i<n-2;i++){
		cout<<a[i]<<" ";
	}
	cout<<a[n-2]<<"]"<<endl;
	recursive(n-1);
}
main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<"[";
		for(int i=0;i<n-1;i++) cout<<a[i]<<" ";
		cout<<a[n-1]<<"]"<<endl;
		recursive(n);
	}
}


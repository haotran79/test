#include<bits/stdc++.h>
using namespace std;

char c;
int n, k, x[1000];

void result(){
	for(int i=1;i<=k;i++) cout<<(char)(x[i]+64);
	cout<<endl;
}
void Try(int i){
	for(int j=x[i-1];j<=n;j++){
		x[i]=j;
		if(i==k) result();
		else Try(i+1);
	}
}
main(){
	cin>>c>>k;
	n=c-64;
	x[0]=1;
	Try(1);
}

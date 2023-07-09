#include<bits/stdc++.h>
using namespace std;

char c;
int n, x[100];
bool used[100];

void init(){
	cin>>c;
	n=c-64;
	for(int i=1;i<=n;i++){
		used[i] = true;
	}
}
void result(){
	for(int i=1;i<=n;i++){
		cout<<(char)(x[i]+64);
	}
	cout<<endl;
}
bool check(){
	int y[n];
	for(int i=1;i<=n;i++){
		if(x[i]==1 || x[i]==5) y[i]=1;
		else y[i]=0;
	}
	for(int i=2;i<n;i++){
		if(y[i]==1 && y[i-1]==0 && y[i+1]==0)
			return false;
	}
	return true;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(used[j]){
			x[i]=j;
			used[j] = false;
			if(i==n){
				if(check()) result();
			} else Try(i+1);
			used[j] = true;
		}
	}
}
main(){
	init();
	Try(1);
}

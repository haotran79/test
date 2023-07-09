#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[105], tmp_arr[105];
int res = 0;

void Try(int pos1, int pos2){
	if(pos2 == k-1){
		res++;
		return;
	}
	for(int i=pos1+1;i<n;i++){
		if(a[i] > a[pos1]){
			tmp_arr[pos2+1] = a[i];
			Try(i, pos2+1);
		}
	}
}
main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		tmp_arr[0] = a[i];
		Try(i, 0);
	}
	cout<<res;
}

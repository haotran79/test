#include<bits/stdc++.h>
using namespace std;

int n, k, a[15], b[15];
bool ok;

void Try(int pos1, int pos2, int cursum){
	for(int i=pos1;i<n;i++){
		if(cursum+a[i] == k){
			ok = true;
			b[pos2] = a[i];
			cout<<"[";
			for(int j=0;j<pos2;j++) cout<<b[j]<<" ";
			cout<<b[pos2]<<"] ";
			return;
		} 
		if(cursum+a[i] < k){
			b[pos2] = a[i];
			Try(i+1, pos2+1, cursum+a[i]);
		}
	}
}
main(){
	int T;
	cin>>T;
	while(T--){
		ok = false;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		Try(0,0,0);
		if(ok == false) cout<<-1;
		cout<<endl;
	}
}

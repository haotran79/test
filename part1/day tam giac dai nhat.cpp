#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		int a1[n], a2[n];
		a1[0]=1;
		for(int i=1;i<n;i++){
			if(a[i] > a[i-1]) a1[i]=a1[i-1]+1;
			else a1[i]=1;
		}
		a2[n-1]=1;
		for(int i=n-2;i>=0;i--){
			if(a[i]>a[i+1]) a2[i]=a2[i+1]+1;
			else a2[i]=1;
		}
		int max_len=0;
		for(int i=0;i<n;i++){
			if(a1[i]+a2[i]-1 > max_len) max_len = a1[i]+a2[i]-1;
		}
		cout<<max_len<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

bool check(long long a[], int n){
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			long long x=a[i]+a[j];
			if(binary_search(a+j+1,a+n,x)) return true;
		}
	}
	return false;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++) a[i] = a[i]*a[i];
		if(check(a,n)) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int n, int x){
	int low = 0, high = n-1;
	while(low <= high){
		int mid = (low+high)/2;
		if(x < a[mid]) high = mid-1;
		else if(x > a[mid]) low = mid+1;
		else return mid;
	}
	return -1;
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		if(binary_search(a,n,k)>0){
			cout<<binary_search(a,n,k)+1;
		} else cout<<"NO";
		cout<<endl;
	}
}

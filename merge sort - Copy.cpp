#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r){
	int i, j, k;
	int n1 = m-l+1, n2 = r-m;
	int L[n1], R[n2];
	for(int i=0;i<n1;i++) L[i] = a[i+l];
	for(int i=0;i<n2;i++) R[i] = a[i+m+1];
	i=0; j=0; k=l;
	while(i<n1 && j<n2){
		if(L[i] < R[j]) a[k] = L[i]; i++;
		else a[k] = R[j]; j++;
		k++;
	}
	while(i<n1) a[k++] = L[i++];
	while(j<n2) a[k++] = R[j++];
}
void merge_sort(int a[], int l, int r){
	if(l<r){
		int m = l + (r-l)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);
		merge(a,l,m,r);
	}
}
main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		merge_sort(a,0,n-1);
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}

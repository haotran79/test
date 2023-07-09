#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(ll a[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	for(int i=0;i<n1;i++)
		L[i] = a[l+i];
	for(int i=0;i<n2;i++)
		R[i] = a[m+1+i];
	int i=0, j=0, k=l;
	ll res = 0;
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		} else {
			a[k] = R[j];
			j++;
			res += n1-i;
		}
		k++;
	}
	while(i<n1) a[k++] = L[i++];
	while(j<n2) a[k++] = R[j++];
	return res;
}
ll mergeSort(ll a[], int l, int r){
	ll res = 0;
	if(l < r){
		int m = (l+r)/2;
		res += mergeSort(a, l, m);
		res += mergeSort(a, m+1, r);
		res += merge(a, l, m, r);
	}
	return res;
}
main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		ll a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<mergeSort(a, 0, n-1)<<endl;
	}
}

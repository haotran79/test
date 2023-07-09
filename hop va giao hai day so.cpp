#include<bits/stdc++.h>
#include<set>
#include<vector>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int a[n], b[m];
		set <int> hop;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<m;i++){
			cin>>b[i];
		}
		sort(a,a+n); sort(b,b+m);
		for(int i=0;i<n;i++) hop.insert(a[i]);
		for(int i=0;i<m;i++) hop.insert(b[i]);
		vector <int> giao;
		int i=0, j=0;
		while(i<n && j<m){
			if(a[i]<b[j]) i++;
			else if(a[i]>b[j]) j++;
			else {
				giao.push_back(a[i]);
				i++; j++;
			}
		}
		for(auto i:hop) cout<<i<<" ";
		cout<<endl;
		for(auto i:giao) cout<<i<<" ";
		cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

int x[1000], n;
bool ok;

void init(){
	cin>>n;
	ok = true;
	for(int i=0;i<n;i++) x[i]=i+1;
}
string result(){
	string s="";
	for(int i=0;i<n;i++) s += (char)(x[i]+48);
	return s;
}
void gen_next(){
	int i=n-2;
	while(i>=0 && x[i]>x[i+1]) i--;
	if(i>=0){
		int k=n-1;
		while(k>=0 && x[i]>x[k]) k--;
		swap(x[i], x[k]);
		int l=i+1, r=n-1;
		while(l<=r){
			swap(x[l], x[r]);
			l++; r--;
		}
	} else ok = false;
}
main(){
	int t;
	cin>>t;
	while(t--){
		init();
		vector <string> v;
		while(ok){
			v.push_back(result());
			gen_next();
		}
		reverse(v.begin(), v.end());
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	}
}


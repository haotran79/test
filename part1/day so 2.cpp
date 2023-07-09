#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int a[N];
vector <string> v;

void recursive(int n){
	if(n==1) return;
	for(int i=0;i<n-1;i++){
		a[i] = a[i]+a[i+1];
	}
	string s = "";
	s += '[';
	for(int i=0;i<n-2;i++){
		s += to_string(a[i]);
		s += ' ';
	}
	s += to_string(a[n-2]);
	s += ']';
	v.push_back(s);
	recursive(n-1);
}
main(){
	int T;
	cin>>T;
	while(T--){
	    v.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		string s = "";
		s += '[';
		for(int i=0;i<n-1;i++){
			s += to_string(a[i]);
			s += ' ';
		}
		s += to_string(a[n-1]);
		s += ']';
		v.push_back(s);
		recursive(n);
		reverse(v.begin(), v.end());
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	}
}

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int n, a[100];
vector <string> v;

string assign(int n){
	string s="";
	s += "(";
	for(int i=1;i<n;i++){
		s += to_string(a[i]);
		s += " ";
	}
	s += to_string(a[n]);
	s += ")";
	return s;
}
void Try(int i, int k, int cursum){
	for(int j=k;j>=1;j--){
		if(cursum+j <= n){
			a[i]=j;
			cursum += j;
			if(cursum == n){
				v.push_back(assign(i));
			} else Try(i+1, j, cursum);
			cursum -= j;
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		Try(1, n, 0);
		cout<<v.size()<<endl;
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	}
}

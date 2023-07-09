#include<bits/stdc++.h>
using namespace std;

int n, a[11], cnt;
vector <string> v;

void result(int n){
	cout<<"(";
	for(int i=1;i<n;i++) cout<<a[i]<<" ";
	cout<<a[n]<<") ";
}
void Try(int i, int k, int cursum){
	for(int j=k;j>=1;j--){
		if(cursum+j <= n){
			a[i]=j;
			cursum += j;
			if(cursum==n){
				cnt++;
				string s="";
				s += "(";
				for(int l=1;l<i;l++){
					s += to_string(a[l]);
					s += " ";
				} 
				s += to_string(a[i]);
				s += ")";
				v.push_back(s);
			} 
			else Try(i+1, j, cursum);
			cursum -= j;
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		v.clear();
		Try(1, n, 0);
		cout<<cnt<<endl;
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	}
}

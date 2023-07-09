#include<bits/stdc++.h>
#include<vector>
using namespace std;

int n, a[100][100];
bool check = false;
vector <string> res;

void init(){
	cin>>n;
	check = false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	res.clear();
}
void Try(int i, int j, string s){
	if(i==1 && j==1 && a[i][j]==0){
		check = false;
		return;
	}
	if(i==n && j==n && a[n][n]){
		res.push_back(s);
		check = true;
		return;
	}
	if(i<n && a[i+1][j]) 
		Try(i+1,j,s+"D");
	if(j<n && a[i][j+1]) 
		Try(i,j+1,s+"R");
}
main(){
	int T;
	cin>>T;
	while(T--){
		init();
		Try(1,1,"");
		if(!check) cout<<-1;
		else {
			sort(res.begin(),res.end());
			for(auto i:res) cout<<i<<" ";
		}
		cout<<endl;
	}
}

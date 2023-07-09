#include<bits/stdc++.h>
#include<vector>
using namespace std;

int n, m, a[100][100];
vector <string> res;
bool check = false;

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			a[i][j]=1;
		}
	}
	res.clear();
	check = false;
}

void Try(int i, int j, string s){
	if(i==1 && j==1 && a[i][j]==0){
		check = false;
		return;
	}
	if(i==n && j==m && a[n][m]){
		res.push_back(s);
		check = true;
		return;
	}
	if(i<n && a[i+1][j]) Try(i+1,j,s+"D");
	if(j<m && a[i][j+1]) Try(i,j+1,s+"R");
	if(i<n && j<m && !a[i+1][j] && a[i][j+1] || i>n || j>m) return;
}

main(){
	int T;
	cin>>T;
	while(T--){
		init();
		Try(1,1,"");
		if(!check) cout<<-1;
		else {
			cout<<res.size();
		}
		cout<<endl;
	}
}

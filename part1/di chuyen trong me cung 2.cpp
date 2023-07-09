#include<bits/stdc++.h>
using namespace std;

int n, a[100][100];
bool ok[100][100];
vector <string> res;

void init(){
	cin>>n;
	res.clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			ok[i][j] = true;
		}
	}
}
void Try(int i, int j, string s){
	if(a[1][1] == 0) return;
	if(i==n && j==n) res.push_back(s);
	if(i<n && a[i+1][j] && ok[i+1][j]){
		ok[i][j] = false;
		Try(i+1, j, s+"D");
		ok[i][j] = true;
	}
	if(j<n && a[i][j+1] && ok[i][j+1]){
		ok[i][j] = false;
		Try(i, j+1, s+"R");
		ok[i][j] = true;
	}
	if(j>1 && a[i][j-1] && ok[i][j-1]){
		ok[i][j] = false;
		Try(i, j-1, s+"L");
		ok[i][j] = true;
	}
	if(i>1 && a[i-1][j] && ok[i-1][j]){
		ok[i][j] = false;
		Try(i-1, j, s+"U");
		ok[i][j] = true;
	}
}
main(){
	int T;
	cin>>T;
	while(T--){
		init();
		Try(1, 1, "");
		if(res.size() == 0) cout<<-1;
		else {
			sort(res.begin(), res.end());
			for(auto i:res) cout<<i<<" ";
		}
		cout<<endl;
	}
}


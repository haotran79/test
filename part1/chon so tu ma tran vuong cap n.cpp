#include<bits/stdc++.h>
using namespace std;

int n, k;
int res;
int a[30][30];
int x[30];
bool ok[30];
vector <vector<int>> Res;

void Try(int i){
	for(int j=1;j<=n;j++){
		if(!ok[j]){
			x[i]=j;
			ok[j] = true;
			if(i==n){
				res = 0;
				for(int l=1;l<=n;l++){
					res += a[l][x[l]];
				}
				if(res == k){
					vector <int> tmp;
					for(int l=1;l<=n;l++){
						tmp.push_back(x[l]);
					}
					Res.push_back(tmp);
				}
			} else Try(i+1);
			ok[j] = false;
		}
	}
}
main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	Try(1);
	cout<<Res.size()<<endl;
	for(int i=0;i<Res.size();i++){
		for(auto j:Res[i]) cout<<j<<" ";
		cout<<endl;
	}
}

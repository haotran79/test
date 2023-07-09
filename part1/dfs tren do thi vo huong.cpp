#include<bits/stdc++.h>
using namespace std;

vector <int> ke[1005];
bool ok[1005];
int e[1005];

void DFS(int u){
	ok[u] = true;
	for(int i=0;i<ke[u].size();i++){
		if(!ok[ke[u][i]]){
			e[ke[u][i]] = u;
			DFS(ke[u][i]);
		}
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<1001;i++) ke[i].clear();
		memset(ok, false, sizeof(ok));
		int a, b, s, t;
		cin>>a>>b>>s>>t;
		for(int i=0;i<b;i++){
			int u, v;
			cin>>u>>v;
			ke[u].push_back(v);
		}
		DFS(s);
		vector <int> way;
		if(ok[t]){
			int tmp = t;
			while(tmp>0){
				way.push_back(tmp);
				tmp = e[tmp];
			}
		} else cout<<-1;
		reverse(way.begin(), way.end());
		for(auto i:way) cout<<i<<" ";
		cout<<endl;
	}
}

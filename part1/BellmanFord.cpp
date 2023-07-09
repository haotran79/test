#include<bits/stdc++.h>
using namespace std;

int n, s;
int a[100][100], d[100], e[100];

int BellmanFord(int s){
	int dem, u, v;
	for(v=1;v<=n;v++){
		d[v] = a[s][v]; e[v] = s;
	}
	d[s] = 0; e[s] = 0; int ok = 0;
	for(dem=1;dem<=n-1;dem++){
		ok = 1;
		for(v=1;v<=n;v++){
			for(u=1;u<=n;u++){
				if(d[v] > d[u]+a[u][v]){
					d[v] = d[u]+a[u][v]; e[v] = u; ok = 0;
				}
			}
		}
		if(ok == 1) return 1;
	}
	return 0;
}
main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	BellmanFord(s);
	for(int i=1;i<=n;i++) cout<<d[i]<<"|"<<e[i]<<" ";
}

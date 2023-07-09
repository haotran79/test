#include<bits/stdc++.h>
using namespace std;

int n, s; // so dinh va dinh bat dau
int a[100][100]; // ma tran bieu dien do thi
int d[100]; // mang luu khoang cach
int e[100]; // mang luu canh ke
int vs[100]; // mang danh dau

void Dijkstra(int s){
	int u, v;
	for (v=1; v<= n; v++){
		d[v]= a[s][v]; e[v]=s;
	}
	d[s]= 0; e[s] = 0; vs[s]= 1;
	while(1){
		int u= 0, min= 32767;
		for (v=1; v<= n; v++){
			if (vs[v]==0 && d[v]< min){
				u= v; min= d[v];
			}
		}
		if (u== 0) return; 
		vs[u]= 1; cout<<u<<" ";
		for (v=1; v<=n; v++){
			if (vs[v]== 0 && d[v]> d[u]+a[u][v]) {
				d[v]= d[u] + a[u][v]; e[v] = u; 
			}
		}
	}
}
main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<s<<" ";
	Dijkstra(s);
	
}

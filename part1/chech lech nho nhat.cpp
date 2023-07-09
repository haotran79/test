#include<bits/stdc++.h>
using namespace std;

int xuli(string v[], int k){
	int res = 0;
	int tmp[k];
	for(int i=0;i<k;i++){
		tmp[i] = stoi(v[i]);
	}
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			res = max(res, abs(tmp[i]-tmp[j]));
		}
	}
	return res;
}

main(){
	int n, k;
	int ans = 32000;
	cin>>n>>k;
	int x[k], dem[k+1];
	dem[0]=1;
	for(int i=0;i<k;i++){
		dem[i+1] = dem[i]*(i+1);
	}
	for(int i=0;i<k;i++) x[i]=i;
	
	vector <string> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	while(dem[k]--){
		string tmp[n];
		for(int i=0;i<n;i++){
			string s = "";
			for(int j=0;j<k;j++){
				s += v[i][x[j]];
			}
			tmp[i] = s;
		}
		ans = min(ans, xuli(tmp, n));
		next_permutation(x,x+k);
	}
	cout<<ans;
}

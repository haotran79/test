#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin>>n>>s;
		int a[n+1];
		int C[s+5] = {0};
		C[0] = 1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=s;j>=a[i];j--){
				if(C[j]==0 && C[j-a[i]]==1) C[j] = 1;
			}
		}
		if(C[s]==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

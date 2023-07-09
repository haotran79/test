#include<bits/stdc++.h>
using namespace std;

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int F[n];
	int ans = 0;
	for(int i=0;i<n;i++){
		F[i] = 1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j] && F[i] <= F[j]){
				F[i] = F[j]+1;
			}
		}
		ans = max(ans, F[i]);
	}
	cout<<ans<<endl;
}

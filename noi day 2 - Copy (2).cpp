#include<bits/stdc++.h>
#include<queue>
using namespace std;

const long long mod = 1e9+7;

main(){
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		long long val;	
		priority_queue <long long, vector<long long>, greater<long long>> a;
		for(int i=0;i<n;i++){
			cin>>val;
			a.push(val);
		}
		long long x, y, sum=0;
		while(a.size()>1){
			x = a.top(); a.pop();
			y = a.top(); a.pop();
			long long tmp = (x+y)%mod;
			a.push(tmp);
			sum += tmp;
			sum %= mod;
		}
		cout<<sum<<endl;
	}
}

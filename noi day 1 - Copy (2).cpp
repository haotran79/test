#include<bits/stdc++.h>
#include<queue>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n;
		priority_queue <int, vector<int>, greater <int>> pq;
		for(int i=0;i<n;i++){
			cin>>x;
			pq.push(x);
		}
		long long res=0;
		long long a, b, sum;
		while(true){
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			sum = a+b;
			res += sum;
			if(pq.empty()) break;
			pq.push(sum);
		}
		cout<<res<<endl;
	}
}

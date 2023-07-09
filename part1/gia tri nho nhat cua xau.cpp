#include<bits/stdc++.h>
#include<queue>
#include<set>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		int k;
		string s;
		cin>>k>>s;
		int c[300] = {0};
		for(int i=0;i<s.size();i++){
			c[s[i]]++;
		}
		priority_queue <int, vector<int>> x;
		for(int i=0;i<s.size();i++){
			if(c[s[i]] > 0){
				x.push(c[s[i]]);
				c[s[i]] = 0;
			}
		}
		while(k-- && x.size()>0){
			int tmp = x.top(); x.pop();
			tmp--;
			x.push(tmp);
		}
		long long res=0;
		while(x.size()>0){
			res += x.top()*x.top();
			x.pop();
		}
		cout<<res<<endl;
	}
}

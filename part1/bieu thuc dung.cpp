#include<bits/stdc++.h>
#include<stack>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int res = 0;
		stack <int> st;
		for(int i=0;i<s.size();i++){
			if(st.size()==0) st.push(s[i]);
			else if(st.top()=='[' && s[i]==']'){
				st.pop();
			} 
			else if(st.top()==']' && s[i]=='['){
				res += st.size();
				st.pop();
			}
			else if(st.top()=='['){
				st.push(s[i]);
			}
			else if(st.top()==']' && st.top()==']'){
				st.push(s[i]);
			}
		}
		cout<<res<<endl;
	}
}

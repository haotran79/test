#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <char> st;
		for(int i=0;i<s.size();i++){
			if(st.empty()) st.push(s[i]);
			else if(st.top()==')' && s[i]==')') st.push(s[i]);
			else if(st.top()=='(' && s[i]=='(') st.push(s[i]);
			else if(st.top()==')' && s[i]=='(') st.push(s[i]);
			else if(st.top()=='(' && s[i]==')') st.pop();
		}
		int k = st.size(), tmp = 0;
		while(st.size()>0 && st.top()=='('){
			st.pop();
			tmp++;
		}
		cout<<(k/2+tmp%2)<<endl;
	}
}

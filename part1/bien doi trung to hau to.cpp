#include<bits/stdc++.h>
#include<stack>
using namespace std;

int sign(char c){
	if(c=='^') return 3;
	if(c=='*'||c=='/') return 2;
	if(c=='+'||c=='-') return 1;
	return -1;
}
main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <char> st;
		string res = "";
		for(int i=0;i<s.size();i++){
			if(s[i]==')'){
				while(st.top()!='('){
					res += st.top(); st.pop();
				}
				st.pop();
			} else if(s[i]=='('){
				st.push(s[i]);
			} else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
				while(st.size()>0 && sign(s[i]) <= sign(st.top())){
					res += st.top(); st.pop();
				}
				st.push(s[i]);
			} else res += s[i];
		}
		while(st.size()>0){
			if(st.top()!='(') res += st.top();
			st.pop();
		}
		cout<<res<<endl;
	}
}

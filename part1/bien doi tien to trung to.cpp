#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool isOperator(char c){
	if(c=='+'||c=='-'||c=='*'||c=='/')
		return true;
	return false;
}
string convert(string s){
	stack <string> st;
	int len = s.size();
	for(int i=len-1;i>=0;i--){
		if(isOperator(s[i])){
			string op1 = st.top(); st.pop();
			string op2 = st.top(); st.pop();
			string tmp = "(" + op1 + s[i] + op2 + ")";
			st.push(tmp);
		} else st.push(string(1,s[i]));
	}
	return st.top();
}

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		cin>>s;
		cout<<convert(s)<<endl;
	}
}
//2
//*+AB-CD
//*-A/BC-/AKL

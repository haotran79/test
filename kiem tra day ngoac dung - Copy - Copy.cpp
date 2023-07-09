#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool check(string s){
	stack <char> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='{' || s[i]=='[' || s[i]=='(') 
			st.push(s[i]);
		else {
			if(st.empty()) return false;
			else if(st.top()=='{' && s[i]=='}') st.pop();
			else if(st.top()=='[' && s[i]==']') st.pop();
			else if(st.top()=='(' && s[i]==')') st.pop();
			else return false;
		}
	}
	if(st.size()==0) return true;
	return false;
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(check(s)) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

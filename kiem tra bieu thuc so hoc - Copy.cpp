#include<bits/stdc++.h>
using namespace std;

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		stack <char> st;
		bool ok = false;
		for(int i=0;i<s.size();i++){
			if(s[i]==')'){
				ok = true;
				while(st.top()!='('){
					char top = st.top(); st.pop();
					if(top=='+' || top=='-' || top=='*' || top=='/') ok = false;
				}
				if(ok==false) break;
			} else st.push(s[i]);
		}
		if(ok) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}

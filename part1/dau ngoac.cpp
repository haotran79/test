#include<bits/stdc++.h>
#include<stack>
using namespace std;

main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		string tmp = "";
		for(int i=0;i<s.size();i++){
			if(s[i]=='(' || s[i]==')'){
				tmp += s[i];
			}
		}
		s = tmp;
		stack <char> st;
		vector <int> v;
		int max = 1;
		for(int i=0; i<s.size();i++){
			if(s[i]=='('){
				st.push(s[i]);
				v.push_back(max);
				max++;
			} else if(st.top()=='(' && s[i]==')'){
				v.push_back(st.top());
				st.pop();
			}
		}
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	}
}
//2
//(a + (b *c) ) + (d/e)
//( ( () ) ( () ) )

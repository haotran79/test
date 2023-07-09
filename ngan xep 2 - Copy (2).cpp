#include<bits/stdc++.h>
#include<stack>
using namespace std;

main(){
	string s;
	int n;
	stack <int> st;
	while(cin>>s){
		if(s == "PUSH"){
			cin>>n;
			st.push(n);
		} 
		else if(s == "POP") st.pop();
		else if(s == "PRINT"){
			if(st.size()>0) cout<<st.top()<<endl;
			else cout<<"NONE"<<endl;
		}
	}
}

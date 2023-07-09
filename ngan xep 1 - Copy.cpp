#include<bits/stdc++.h>
#include<stack>
using namespace std;

main(){
	string s;
	int n;
	stack <int> st;
	while(cin>>s){
		if(s == "push"){
			cin>>n;
			st.push(n);
		} 
		else if(s == "pop") st.pop();
		else if(s == "show"){
			vector <int> a;
			if(st.size()==0){
				cout<<"empty"<<endl;
				continue;
			}
			while(st.size()>0){
				a.push_back(st.top());
				st.pop();
			}
			reverse(a.begin(), a.end());
			for(int i=0;i<a.size();i++){
				cout<<a[i]<<" ";
				st.push(a[i]);
			}
			cout<<endl;
		}
	}
}

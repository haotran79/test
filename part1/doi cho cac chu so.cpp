#include<bits/stdc++.h>
#include<string>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		int k;
		string s;
		cin>>k>>s;
		for(int i=0;i<s.size();i++){
			if(k==0) break;
			int tmp=i;
			for(int j=i+1;j<s.size();j++){
				if(s[j] >= s[tmp]) tmp = j;
			}
			if(tmp!=i && s[tmp]>s[i]){
				swap(s[tmp], s[i]);
				k--;
			}
		}
		cout<<s<<endl;
	}
}

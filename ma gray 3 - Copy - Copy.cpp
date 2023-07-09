#include<bits/stdc++.h>
using namespace std;

int convert(string s){
	reverse(s.begin(),s.end());
	int tmp=0;
	for(int i=0;i<s.size();i++){
		tmp += (s[i]-48)*pow(2,i);
	}
	return tmp;
}
main(){
	int T;
	cin>>T;
	while(T--){
		string s[10000];
		int n;
		string tmp;
		cin>>tmp;
		n=tmp.size();
		s[1]="0"; s[2]="1";
		if(n>1){
			int vt=2;
			for(int i=2;i<=n;i++){
				int k=pow(2,i);
				for(int j=1;j<=vt;j++){
					s[k-j+1]="1"+s[j];
					s[j]="0"+s[j];
				}
				vt=k;
			}
		}
		cout<<s[convert(tmp)+1]<<endl;
	}
}

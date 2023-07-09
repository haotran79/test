#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		int k;
		string a, b;
		cin>>k>>a>>b;
		while(a.size() < b.size()) a = "0" + a;
		while(a.size() > b.size()) b = "0" + b;
		string res = "";
		int du = 0;
		int len = a.size();
		for(int i=len-1;i>=0;i--){
			int tmp = int(a[i]-'0') + int(b[i]-'0') + du;
			res = char(tmp % k + '0') + res;
			du /= k;
		}
		if(du > 0) res = char(du+'0')+res;
		cout<<res<<endl;
	}
}

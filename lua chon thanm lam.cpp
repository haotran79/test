#include<bits/stdc++.h>
using namespace std;

string min_number(int n, int s){
	if(n==0 || s==0) return "-1";
	string res = "";
	while(n>1){
		if(s>9){
			res += "9";
			s -= 9;
			n--;
		} else {
			res += (char)(s-1+'0');
			s=1;
			n--;
			break;
		}
	}
	if(n>1){
		for(int i=n;i>1;i--){
			res += "0";
		}
	}
	if(s>9) return "-1";
	res += (char)(s+'0');
	reverse(res.begin(), res.end());
	return res;
}
string max_number(int n, int s){
	if(n==0 || s==0) return "-1";
	string res = "";
	while(n>0){
		if(s>9){
			res += "9";
			s-=9;
			n--;
		} else {
			res += (char)(s+'0');
			s=0;
			n--;
			break;
		}
	}
	if(s>0) return "-1";
	else {
		while(n--) res += "0";
		return res;
	}
}
main(){
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin>>n>>s;
		cout<<min_number(n, s)<<" "<<max_number(n, s)<<endl;
	}
}

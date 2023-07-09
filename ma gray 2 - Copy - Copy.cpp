#include<bits/stdc++.h>
using namespace std;

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
		int dec;
		for(int i=1;i<=pow(2,n);i++){
			if(s[i]==tmp) dec = i-1;
		}
		string kq="";
		while(dec){
			kq += (dec%2+48);
			dec/=2;
		}
		for(int i=kq.size();i<n;i++) kq += "0";
		reverse(kq.begin(),kq.end());
		cout<<kq<<endl;
	}
}

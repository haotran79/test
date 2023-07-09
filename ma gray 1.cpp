#include<bits/stdc++.h>
using namespace std;

string s[10000];
int n;

main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int l = pow(2,n);
		s[1]="0"; s[2]="1";
		if(n>1){
			int vt=2; // lay vi tri doi xung
			// lan luot tinh cac ma gray
			for(int i=2;i<=n;i++){
				int k = pow(2,i); // so luong cac ma gray thu i
				for(int j=1;j<=vt;j++){
					s[k-j+1] = "1"+s[j];
					s[j] = "0"+s[j];
				}
				vt = k;
			}
		}
		for(int j=1;j<=l;j++) cout<<s[j]<<" ";
		cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;

int n;
int x[100], y[100];
bool unused[100];
vector <string> v1, v2;

void Try1(int i){
	for(int j=1;j<=n;j++){
		if(unused[j]){
			x[i] = j;
			unused[j] = false;
			if(i==n){
				string s = "";
				for(int l=1;l<=n;l++){
					s += char(x[l]+64);
				}
				v1.push_back(s);
			} else Try1(i+1);
			unused[j] = true;
		}
	}
}
void Try2(int i){
	for(int j=1;j<=n;j++){
		y[i] = j;
		unused[j] = false;
		if(i==n){
			string s = "";
			for(int l=1;l<=n;l++){
				s += char(y[l]+48);
			}
			v2.push_back(s);
		} else Try2(i+1);
	}
}
main(){
	cin>>n;
	memset(unused, true, sizeof(unused));
	Try1(1); Try2(1);
	for(auto i:v1){
		for(auto j:v2) cout<<i+j<<endl;
	}
}

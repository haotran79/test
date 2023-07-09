#include<bits/stdc++.h>
using namespace std;
#define N 1000000

bool ok = false;
int n, x[N], a[N], sum;
vector <vector<int>> res;

bool check(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(x[i]==1) tmp += a[i];
	}
	return tmp==sum;
}
void Try(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n){
			if(check()){
				vector <int> v;
				for(int l=1;l<=n;l++){
					if(x[l]) v.push_back(a[l]);
				}
				res.push_back(v);
				ok = true;
			}
		} else Try(i+1);
	}
}
main(){
	int T;
	cin>>T;
	while(T--){
		res.clear();
		cin>>n>>sum;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=n;i>0;i--) a[i]=a[i-1];
		Try(1);
		if(ok){
			sort(res.begin(), res.end());
			
			for(int i=0;i<res.size();i++){
				cout<<"[";
				for(int j=0;j<res[i].size()-1;j++){
					cout<<res[i][j]<<" ";
				}
				cout<<res[i][res[i].size()-1]<<"] ";
			}
		} else cout<<-1;
		ok = false;
		cout<<endl;
	}
}
//5 50       
//5 10 15 20 25   

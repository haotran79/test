#include<bits/stdc++.h>
using namespace std;

vector <long long> a;
// cac vi tri le thi chac chan la 1, vi tri chan thi co the 1 hoac 0
// mang sinh ra cuoi cung se co dang doi xung => use chia de tri
// ham tim vi tri trung tam
void Poscenter(long long n){
	long long i=1;
	while(1){
		long long tmp = pow(2, i);
		if(tmp <= n){
			a.push_back(tmp);
			i++;
		} else break;
	}
}
// ham chia de tri
long long val(long long k, long long n, long long pos){
	if(k%2 == 1) return 1;
	if(k < a[pos]) val(k, n/2, pos-1); // de quy sang trai neu k nho hon vi tri trung tam
	else if(k == a[pos]) return n%2; // neu k la trung tam thi tra ve
	else if(k > a[pos]) val(a[pos]-(k-a[pos]), n/2, pos-1); // de quy sang trai neu k lon hon vi tri trung tam
}
main(){
	ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		a.clear();
		long long n, l, r;
		cin>>n>>l>>r;
		long long res = 0;
		Poscenter(n);
		for(long long i=l;i<=r;i++){
			res += val(i, n, a.size()-1);
		}
		cout<<res<<endl;
	}
}

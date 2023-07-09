#include<bits/stdc++.h>
using namespace std;

main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n];
		bool ktd = false;
		int Max = INT_MIN;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>0) ktd = true;
			Max = max(Max, a[i]);
		}
		if(ktd == false) cout<<Max<<endl;
		else {
			int sum = 0, res = a[0];
			for(int i=0;i<n;i++){
				sum += a[i];
				if(sum < 0) sum = 0;
				if(res < sum) res = sum;
			}
			cout<<res<<endl;
		}
	}
}

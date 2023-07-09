#include<bits/stdc++.h>
#include<vector>
using namespace std;

int min_refills(int tank, vector <int> stops){
	int currR, lastR, numR = 0, n = stops.size();
	n -= 2;
	while(currR <= n){
		lastR = currR;
		while(currR <= n && stops[currR+1] - stops[lastR] <= tank)
			currR++;
		if(lastR == currR) return -1;
		if(currR <= n) numR++;
	}
	return numR;
}
main(){
	vector <int> stops;
	int a[] = {0, 200, 375, 550, 750, 950};
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		stops.push_back(a[i]);
	}
	int tank = 400;
	cout<<min_refills(tank, stops);
}

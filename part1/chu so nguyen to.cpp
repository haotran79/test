#include<bits/stdc++.h>

using namespace std;

bool check(string x){
	if(x[x.length() - 1] == '2'){
		return false;
	}
	int a[10] = {0};
	for(int i = 0; i < x.length(); i++){
		if(x[i] == '2'){
			a[2]++;
		}
		else if(x[i] == '3'){
			a[3]++;
		}
		else if(x[i] == '5'){
			a[5]++;
		}
		else if(x[i] == '7'){
			a[7]++;
		}
	}
	if(a[2] == 0 || a[3] == 0 || a[5] == 0 || a[7] == 0) return false;
	return true;
}

int main(){
	int n;
	cin >> n;
	queue<string> q;
	q.push("2"); q.push("3"); q.push("5"); q.push("7");
	while(1){
		string num = q.front();
		q.pop();
		if(num.size() > n){
			break;
		}
		if(num.size() == n && check(num)){
			cout << num << endl;
		}
		q.push(num + "2");
		q.push(num + "3");
		q.push(num + "5");
		q.push(num + "7");
	}
}

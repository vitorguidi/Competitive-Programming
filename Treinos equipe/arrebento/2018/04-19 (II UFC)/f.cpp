#include <bits/stdc++.h>
#include <iostream>
using namespace std;	

int main(){
	long int n,m,k;
	long int min,faltam,pct;
	float test;

	cin >> n >> m >> k;

	min=(7*n+9)/10;
	faltam=min-k;
	if(faltam>n-m && faltam>0)	cout << -1 << endl;
	else if(faltam<=0)			cout <<0 << endl;			
	else			cout << faltam << endl;

	pct=k+n-m;
	pct=100*pct;
	pct=pct/n;

	cout << pct << endl;

	return 0;
}
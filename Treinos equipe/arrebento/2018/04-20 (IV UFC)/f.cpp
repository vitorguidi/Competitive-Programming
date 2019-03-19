#include <bits/stdc++.h>
using namespace std;

int trem[100000];

int main(){

	int n,flag;

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> trem[i];
	}

	sort(trem,trem+n);

	for(int i=0;i<n;i++){
		flag=1;
		//cout << "checando " << trem[i] << endl;
		if(trem[i]==1)	continue;	//1 n eh primo
		if(trem[i]==2){
			cout << 2 << endl;
			return 0;
		}
		for(long int j=2;(j-1)*(j-1)<=trem[i];j++){
			if(trem[i]%j==0){
				flag=0;
				//cout << "eh divisivel por " << j << endl;
				break;
			}
		}
		if(flag!=0){
			//cout << "eh primo" << endl;
			cout << trem[i] << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}
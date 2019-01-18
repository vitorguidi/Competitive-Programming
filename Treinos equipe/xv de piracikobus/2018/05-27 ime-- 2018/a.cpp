#include<bits/stdc++.h>
using namespace std;

int main(){
	int soma=0,n,i,min,a;
	cin >> n;
	if (n!=0){
		cin >> min;
		soma=min;
	}
	for (i=1;i<n;i++){
		cin >> a;
		soma +=a;
		if (soma<min)
			min=soma;
	}

	if (min>=0)
		cout << '0'<<endl;
	else
		cout <<-min<<endl;
	return(0);
} 
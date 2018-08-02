#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000000;

int main(){

	int x1r=-2*MAXN;
	int y1r=2*MAXN;
	int x2r=2*MAXN;
	int y2r=-2*MAXN;
	int n;
	int x1,y1,x2,y2;

	cin >> n;
	int flag=1;

	for(int i=0;i<n;i++){				//gera o quadradao de resposta
		cin >> x1 >> y1 >> x2 >> y2;

		if(x2r<=x1 || x2<=x1r || y1 <=y2r || y2>=y1r){
			cout << -1 << endl;
			return 0;
		}

		x1r=max(x1,x1r);		
		y1r=min(y1,y1r);
		x2r=min(x2,x2r);
		y2r=max(y2,y2r);
	}


	cout << x1r << ' ' << y1r << ' ' << x2r << ' ' << y2r;

	return 0;
}
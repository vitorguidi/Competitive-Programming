#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 1000000000000001018
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define MAX 

  
int main()
{	
	fastcin;

	vector<int> aux;

	int n; cin >> n;

	for(int i=0;i<n;i++){
		int x; cin >> x;
		aux.pb(x);
	}

	int best = 10010000;
	int cara = -1;
	int h; cin >> h;

	for(int i=0;i<n;i++){
		int x = aux[i];
		int temp = h%x;
		if(temp<best){
			best=temp;
			cara=x;
		}
	}

	cout << cara << endl;
	
}
close
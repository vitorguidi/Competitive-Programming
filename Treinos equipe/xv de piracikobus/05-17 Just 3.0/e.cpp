#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl

typedef pair<int,int> pii;
typedef vector<int,int> vi;

int main(){

	string s;
	int t,n,k,l,b;
	cin >> t;

	for(int i=0;i<t;i++){
		cin >> n;
		k=l=b=0;
		getchar();

		for(int j=0;j<n;j++){
			getline(cin,s);
			if(s[0]=='k' || s[0]=='K')	k++;
			if(s[0]=='l' || s[0]=='L')	l++;
			if(s[0]=='b' || s[0]=='B')	b++;
		}

		int a=min(k,l);
		a=min(a,b/2);
		cout << a << endl;
	}	
	
}
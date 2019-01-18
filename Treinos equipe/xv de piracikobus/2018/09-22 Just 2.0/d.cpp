#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  

	int n;
	cin >> n;
	string t;
	getline(cin,t);
	fr(i,n){
		string s;
		getline(cin,s);
		//cout << s <<endl;
		int let,num,car;
		let=num=car=0;
		fr(j,s.size()){
			if(s[j]>= 'a' && s[j] <= 'z')
				let++;
			if (s[j] >= 'A' && s[j] <='Z')
				let++;
			if(s[j] >= '0' && s[j] <= '9')
				num++;
			if(s[j] == '@' || s[j] == '?' ||s[j] == '!')
				car++;
		}
		//cout << let << num << car;
		if(let<4) cout <<"The last character must be a letter.";
		else if(num < 4) cout <<"The last character must be a digit.";
		else if (car < 2) cout <<"The last character must be a symbol.";
		else cout << "The last character can be any type.";
		gnl;
	}

    

}
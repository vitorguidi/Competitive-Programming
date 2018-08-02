#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define pira cout << "XV de piracikobus" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int T,mod = pow(10,9) + 7;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		string s,t,aux;
		getline(cin,aux);
		getline (cin,s);
		getline(cin,t);
		//cout << s << endl;
		//cout<< t << endl;
		int tot=1;
		fr (i,n){
			if(s[i]=='1' && t[i]=='1'){
				tot*=2;
				tot = tot%mod;
			}

			if (s[i]=='0') continue;

			if (s[i] == '1' && t[i] =='0'){
				tot = -1;
				break;
			}
		}

		if (tot == -1)
			cout << "IMPOSSIBLE" <<  endl;
		else
			cout << tot << endl;
	}

	return (0);
}
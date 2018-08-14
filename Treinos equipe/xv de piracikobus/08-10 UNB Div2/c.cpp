#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;

int x,aux[6];

int converte(string s){
	
	aux[0]=s[0]-'0';
	aux[1]=s[1]-'0';
	aux[2]=s[3]-'0';
	aux[3]=s[4]-'0';
	aux[4]=s[6]-'0';
	aux[5]=s[7]-'0';

	int sum = 0;

	sum+= (10*aux[0]+aux[1])*3600;
	sum+= (10*aux[2]+aux[3])*60;
	sum+= (10*aux[4]+aux[5]);

	return sum;

}

int main(){

	cin >> x;

	string ini, end;
	getline(cin,ini);

	getline(cin,ini);
	getline(cin,end);

	if(ini>=end){
		int h = (end[0]-'0')*10+(end[1]-'0');
		h+=24;
		end[0]=h/10 + '0';
		end[1]=h%10 + '0';
	}

	int tot = converte(end)-converte(ini);
	tot=abs(tot);

	cout << tot/x << endl;

}
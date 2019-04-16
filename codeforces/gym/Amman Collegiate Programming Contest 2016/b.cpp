#include <bits/stdc++.h>
using namespace std;

#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n)
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ms(x,val) memset(x,val,sizeof x)
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX
#define gnl cout << endl
#define dbg(x) cout << #x << " = " << x << endl
#define vll vector<long long int>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long int, long long int>

int top[10];
int t;
map <char,int> cost;
vector<pair< char,int > > ordem;
void precalc()
{
	cost['1']=2;
	cost['7']=3;
	cost['4']=4;
	cost['2']=5;
	cost['3']=5;
	cost['5']=5;
	cost['6']=6;
	cost['0']=6;
	cost['9']=6;
	cost['8']=7;
	ordem.pb(mp('9',6));
	ordem.pb(mp('8',7));
	ordem.pb(mp('7',3));
	ordem.pb(mp('5',5));
	ordem.pb(mp('4',4));
	ordem.pb(mp('1',2));
	top[0] = 7;
	top[1] = 7;
	top[2] = 5;
	top[3] = 5;
	top[4] = 4;
	top[5] = 2;
}
int main()
{	
	fastcin;
	cin >> t;
	precalc();
	while(t--)
	{
		int dig;
		cin >> dig;
		string numinicial;
		cin >> numinicial;
		int totcusto = 0;
		for(int i=0;i<numinicial.size();i++)
		{
			totcusto+=cost[numinicial[i]];
		}
		string resp;
		int custor = totcusto;
		int at = 0;
		while(custor!=0)
		{
			int lo = (dig-1)*2;
			int up = (dig-1)*top[at];
			//cout << " custor = " << custor << "lo = " << lo << " up = " << up << endl;
			//cout << "str = " << resp << endl;
			if((custor-ordem[at].se) >= lo and (custor-ordem[at].se)<=up)
			{
				resp.pb(ordem[at].fi);
				custor-=ordem[at].se;
				dig--;
			}
			else
				at++;
		}
		cout << resp << endl;
	}

}
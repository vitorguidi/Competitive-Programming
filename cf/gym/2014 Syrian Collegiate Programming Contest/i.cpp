#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fst first
#define snd second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"

char pred = 'A'-'a';

int main()
{	
	fastcin;
	int t;
	cin >> t;
	int caso=1;
	while(t>0)
	{
		vector<pair <int,char> > ord;
		vector<char> v;
		set<char> s;
		map<char,int> m;
		ll int soma =0;
		char a;
		
		while(1)
		{
			cin >> a;
			//cout << a << " ";
			
			if(a == '*')
				break;
			if(a>='A' and a < 'a')
				a-= pred;
			//cout << a << "   ";
			if(s.count(a) == false)
			{
				s.insert(a);
				v.pb(a);
			}
			m[a]++;
		}
		//cout << endl;
		for(int i=0;i<v.size();i++)
		{
			//cout << "Coloco no vetor " << v[i] << " e freq = " << m[v[i]] <<endl;
			ord.pb(mp(m[v[i]],v[i]));
		}
		
		sort(ord.rbegin(),ord.rend());
		
		for(int i=0;i<min(((int)ord.size()),5);i++)
		{

			//cout << "ord[i] = " <<// ord[i].se << " Estou acrescentando = " << (ord[i].se -'a') << endl;  
			soma+=(ord[i].se - (int)'a');
		}
		//cout << "Soma = " << soma << endl;
		if(soma>62)
			cout << "Case " << caso <<": Effective";
		else
			cout << "Case " << caso <<": Ineffective";
		cout << endl;
		caso++;
		t--;
	}
}
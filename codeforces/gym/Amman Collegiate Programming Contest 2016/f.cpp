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



int main()
{	
	fastcin;
	int n;
	cin >> n;
	while(n--)
	{
		string str;
		set<char> st;
		cin >> str;
		for(int i=0;i<str.size();i++)
		{
			st.insert(str[i]);
		}
		char prim,sec;
		bool fim = false;
		set<char> tirou;
		for(int i=0;i<str.size();i++)
		{
			auto e = st.begin();
			// cout << "e = " << (*e) << " str = " << str[i] << endl;
			if(str[i]!=(*e) and tirou.count(str[i]) == false)
			{
				prim = (*e);
				sec = str[i];
				fim = true;
				break;
			}
			else if(tirou.count(str[i]) == false)
			{
				// cout << "estou colocando " << str[i] << endl;
				st.erase(str[i]);
				tirou.insert(str[i]);
			}
			if(st.size() == 0)
				break;		
		}
		if(fim)
		{

			for(int i=0;i<str.size();i++)	
			{
				if(str[i] == prim )
					str[i] = sec;
				
				else if(str[i] == sec)
					str[i] = prim;
			}
		}
		cout << str << endl;

	}
}
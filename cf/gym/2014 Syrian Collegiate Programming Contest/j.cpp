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
#define MAX 

int main()
{	
	fastcin;
	int t;
	int caso=0;
	cin >> t;
	while(t>0)
	{
		caso++;
		int hc,mc,mw,hw;
		cin >> hc >> mc >> hw >> mw;
		int tenho = hc*60;
		tenho+=mc;

		int meta = hw*60;
		meta += mw;
		cout << "Case " << caso << ": " << meta-tenho << endl;
		t--;
	}	

}
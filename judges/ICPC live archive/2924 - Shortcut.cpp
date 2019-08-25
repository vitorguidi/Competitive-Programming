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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
#define endl "\n"
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

typedef tuple<int,int,int,int> event;
typedef tuple<int,int,int,char> answer;

vector<pii> px[500500],py[500500];
vii v;

bool better(answer a, answer b){
	if(get<0>(a)!=get<0>(b))
		return get<0>(a) < get<0>(b);
	if(get<1>(a)!=get<1>(b))
		return get<1>(a) < get<1>(b);
	if(get<2>(a)!=get<2>(b))
		return get<2>(a) > get<2>(b);
	return false;
}

void go(){

	int n; cin >> n;
	string s; cin >> s;

	int x=n;
	int y=n;

	v.clear();

	for(int i=0;i<=2*n;i++){
		px[i].clear();
		py[i].clear();
	}

	px[n].pb({n,0});
	py[n].pb({n,0});

	v.pb({n,n});
	int clk=1;


	for(auto c : s){
		int new_x=x;
		int new_y=y;
		if(c=='N')
			new_y++;
		if(c=='S')
			new_y--;
		if(c=='W')
			new_x--;
		if(c=='E')
			new_x++;
		px[new_x].pb({new_y,clk});
		py[new_y].pb({new_x,clk});
		x=new_x;
		y=new_y;
		v.pb({x,y});
		clk++;
	}



	for(int i=0;i<=2*n;i++){
		sort(all(px[i]));
		sort(all(py[i]));
	}

	answer out = make_tuple(INF,-1,-1,'N');


	// for(int i=0;i<=2*n;i++){
	// 	cout << i << endl;
	// 	for(auto x : py[i+n])
	// 		cout << x.fst-n <<" ";
	// 	gnl;gnl;
	// }

	fr(i,n){
		
		pii cara = v[i];
		
		int curx = cara.fst;
		int cury = cara.snd;
		//busca pra cima e baixo
		
		auto prox = lower_bound(all(px[curx]),mp(cury+1,0));

		if(prox!=px[curx].end()){		//mesmo x, y maior =>norte
			
			pii cima = *prox;

			int id = cima.snd;
			int new_y = cima.fst;

			int newdist = abs(cury-new_y);
			char newdir = 'N';
			int newfrom = i;
			int newto = id;

			if(newfrom>newto){
				swap(newfrom,newto);
				newdir='S';
			}

			answer aux = make_tuple(newdist, newfrom, newto, newdir);

			if(better(aux,out) && abs(newfrom-newto)>1)
				out = aux;

		}

		auto tras = lower_bound(all(px[curx]),mp(cury,0));
		if(tras!=px[curx].begin()){

			tras--;

			pii antes = *tras;

			int id = antes.snd;
			int new_y = antes.fst;


			int newdist = abs(cury-new_y);
			char newdir = 'S';
			int newfrom = i;
			int newto = id;

			if(newfrom>newto){
				swap(newfrom,newto);
				newdir='N';
			}

			answer aux = make_tuple(newdist, newfrom, newto, newdir);

			if(better(aux,out) && abs(newfrom-newto)>1)
				out = aux;

		}

		auto right = lower_bound(all(py[cury]),mp(curx+1,0));

		if(right!=py[cury].end()){		//mesmo x, y maior =>norte
			
			pii frente = *right;


			int id = frente.snd;
			int new_x = frente.fst;

			int newdist = abs(curx-new_x);
			char newdir = 'E';
			int newfrom = i;
			int newto = id;

			if(newfrom>newto){
				swap(newfrom,newto);
				newdir='W';
			}

			answer aux = make_tuple(newdist, newfrom, newto, newdir);

			if(better(aux,out) && abs(newfrom-newto)>1)
				out = aux;

		}

		auto left = lower_bound(all(py[cury]),mp(curx,0));
		if(left	!=py[cury].begin()){



			left--;

			pii antes = *left;

			int id = antes.snd;
			int new_x = antes.fst;

			int newdist = abs(curx-new_x);
			char newdir = 'W';
			int newfrom = i;
			int newto = id;

			if(newfrom>newto){
				swap(newfrom,newto);
				newdir='E';
			}

			answer aux = make_tuple(newdist, newfrom, newto, newdir);

			if(better(aux,out) && abs(newfrom-newto)>1)
				out = aux;

		}

	}	

	cout << get<0>(out) << " " << get<1>(out) << " " << get<2>(out) << " " << get<3>(out) << endl;

}

int main(){
	fastio;
	int q; cin >> q;
	while(q--){
		go();
		if(q!=0)	gnl;
	}
}
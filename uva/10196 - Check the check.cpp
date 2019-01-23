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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
string s[10];
int dx[8] = {2,1,2,1,-2,-1,-2,-1};
int dy[8] = {-1,2,1,-2,1,2,-1,-2};
int ctg = 1;

bool vazia(){
	fr(i,8){
		fr(j,8){
			if(s[i][j] != '.') return false;
		}
	}

	return true;
}

void show(){
	fr(i,8){
		fr(j,8){
			cout << s[i][j];
		}
		gnl;
	}

}

bool is(int x,int y){
	if(x < 0 || x > 7) return false;
	swap(x,y);
	if(x < 0 || x > 7) return false;
	return true;

}

bool w_rqb(int x,int y){

	int i = x;
	int j = y;
	i--;
	while(is(i,j)){
		if(s[i][j] == 'r' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		i--;
	}

	i = x;
	j = y;
	i++;
	while(is(i,j)){
		if(s[i][j] == 'r' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		i++;
	}

	i = x;
	j = y;
	j--;
	while(is(i,j)){
		if(s[i][j] == 'r' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		j--;
	}

	i = x;
	j = y;
	j++;
	while(is(i,j)){
		if(s[i][j] == 'r' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		j++;
	}

	///////////////////////// TRANSIÇÃO ////////////////////////////

	i = x;
	j = y;
	i++;
	j++;
	while(is(i,j)){
		if(s[i][j] == 'b' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		i++;
		j++;
	}

	i = x;
	j = y;
	i++;
	j--;
	while(is(i,j)){
		if(s[i][j] == 'b' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		i++;
		j--;
	}

	i = x;
	j = y;
	i--;
	j--;
	while(is(i,j)){
		if(s[i][j] == 'b' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		i--;
		j--;
	}

	i = x;
	j = y;
	i--;
	j++;
	while(is(i,j)){
		if(s[i][j] == 'b' || s[i][j] == 'q')
			return true;
		if (s[i][j] != '.') break;
		i--;
		j++;
	}

	return false;

}

bool wpawn(int x,int y){
	if(is(x-1,y-1)){
		if(s[x-1][y-1] == 'p') return true;
	}
	if(is(x-1,y+1)){
		if(s[x-1][y+1] == 'p') return true;
	}
	return false;
}

bool wpawwn(int x,int y){
	if(is(x+1,y-1)){
		if(s[x+1][y-1] == 'p') return true;
	}
	if(is(x+1,y+1)){
		if(s[x+1][y+1] == 'p') return true;
	}
	return false;
}

bool wknight(int x,int y){
	fr(i,8){
		if(is(x + dx[i],y + dy[i])){
			if(s[x + dx[i]][y + dy[i]] == 'n'){
				return true;
			}
		}
	}

	return false;
}

bool solve(){
	fr(i,8){
		getline(cin,s[i]);
	}
	//show();
	if(vazia()) return false;
	pii wk,bk;
	fr(i,8){
		fr(j,8){
			if(s[i][j] == 'K'){
				wk.fst = i;
				wk.snd = j;
			}
			if(s[i][j] == 'k'){
				bk.fst = i;
				bk.snd = j;
			}
		}
	}

	bool ok = false;
	ok = w_rqb(wk.fst,wk.snd);
	ok = ok|wpawn(wk.fst,wk.snd);
	ok = ok|wknight(wk.fst,wk.snd);

	if(ok){cout <<"Game #" << ctg++<< ": "<< "white king is in check."<< endl;return true;}

	fr(i,8){
		fr(j,8){
			if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
				s[i][j] = s[i][j] - 'A' + 'a';
				//olar;
			}
			else if(s[i][j] >= 'a' && s[i][j] <= 'z'){
				s[i][j] = s[i][j] - 'a' + 'A';
			}
		}
	}

	//show();

	ok = false;
	ok = w_rqb(bk.fst,bk.snd);
	ok = ok|wpawwn(bk.fst,bk.snd);
	ok = ok|wknight(bk.fst,bk.snd);

	//dbg(ok);

	
	if(ok){cout <<"Game #" << ctg++<< ": "<< "black king is in check."<< endl;return true;}


	cout <<"Game #" << ctg++<< ": "<< "no king is in check."<< endl;


	

	return true;
}

int main(){

	fastio;
	string t;
	while(solve()){
		getline(cin,t);
	}

}
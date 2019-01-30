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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

bool nmb(char x){
	string aux = "0123456789";
	for(auto y : aux)
		if(x==y)	return true;
	return false;
}

bool is_number(string x){

	if(x=="")	return false;

	if(x[0]=='0' && x.size()==1)
		return true;

	if(x[0]=='0' && x.size()!=1)
		return false;
	
	for(auto y : x)
		if(!nmb(y))	return false;
	
	return true;

}

int main(){

	fastio;

	string s;
	cin >> s;

	vector<string> numbers;
	vector<string> others;

	int ini=0;
	while(ini<s.size()){
		string aux;
		while(ini<s.size() && s[ini]!=';' && s[ini]!=','){
			aux.pb(s[ini++]);
		} 
		if(is_number(aux))
			numbers.pb(aux);
		else
			others.pb(aux);
		ini++;
	}

	int len = s.size();
	if(s[len-1]==',' || s[len-1]==';')
		others.pb("");
	
	if(numbers.size()==0)
		cout << "-" << endl;
	else{
		int len = numbers.size();
		char x = '"';
		cout << x;
		fr(i,len){
			cout << numbers[i];
			if(i!=len-1)
				cout <<",";
		}
		cout << x << endl;
	}

	if(others.size()==0)
		cout << "-" << endl;
	else{
		int len = others.size();
		char x = '"';
		cout << x;
		fr(i,len){
			cout << others[i];
			if(i!=len-1)
				cout <<",";
		}
		cout << x << endl;		
	}


}
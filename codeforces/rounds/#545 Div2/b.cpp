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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int tag[5050];
int n;
int ambos,palha,acro,vaga;
stack<int> both,clown,acrobat,dull;

bool check(int x, int y){	//x=capaz de ambos no p1, y = capaz de ambos no p2

	int p1=x;
	int p2=ambos-x;

	int cur_palha=palha;
	int cur_acro=acro;
	int cur_vaga=vaga;

	if(p1>y || p2>y)	return false;

	int faltap1 = y-p1;
	int faltap2 = y-p2;

	if(faltap1 > cur_palha)	return false;
	if(faltap2 > cur_acro)	return false;

	p1+=faltap1;
	cur_palha-=faltap1;
	p2+=faltap2;
	cur_acro-=faltap2;

	p2+=cur_palha;
	p1+=cur_acro;

	cur_palha=cur_acro=0;

	int restante = abs(p1-p2);

	if(cur_vaga<restante)	return false;
	
	cur_vaga-=restante;
	if(p1<p2)	p1+=restante;
	else		p2+=restante;


	if(cur_vaga%2)	return false;

	p1+=cur_vaga/2;
	p2+=cur_vaga/2;

	if(p1!=p2)	return false;

	return true;

}

void go(int x, int y){

	int p1=x;
	int p2=ambos-x;

	fr(i,x){
		tag[both.top()]=1;
		both.pop();
	}

	fr(i,ambos-x){
		tag[both.top()]=0;
		both.pop();
	}

	int cur_palha=palha;
	int cur_acro=acro;
	int cur_vaga=vaga;

	int faltap1 = y-p1;
	int faltap2 = y-p2;

	p1+=faltap1;
	p2+=faltap2;
	cur_palha-=faltap1;
	cur_acro-=faltap2;

	p2+=cur_palha;
	p1+=cur_acro;

	fr(i,faltap1){
		tag[clown.top()]=1;
		clown.pop();
	}

	fr(i,faltap2){
		tag[acrobat.top()]=0;
		acrobat.pop();
	}


	while(!acrobat.empty()){
		tag[acrobat.top()]=1;
		acrobat.pop();
	}

	while(!clown.empty()){
		tag[clown.top()]=0;
		clown.pop();
	}

	int restante = abs(p1-p2);
	cur_vaga-=restante;

	if(p1<p2){
		p1+=restante;
		fr(i,restante){
			tag[dull.top()]=1;
			dull.pop();
		}
	}
	else{
		p2+=restante;
		fr(i,restante){
			tag[dull.top()]=0;
			dull.pop();
		}
	}

	while(cur_vaga>0){
		cur_vaga-=2;
		tag[dull.top()]=1;
		dull.pop();
		tag[dull.top()]=0;
		dull.pop();
	}

	frr(i,n)
		if(tag[i])	cout << i << " ";
	gnl;
}

int main(){
    
	fastio;

	string a,b;
	
	cin >> n >> a >> b;

	fr(i,n){
		if(a[i]=='1' && b[i]=='1'){
			ambos++;
			both.push(i+1);
		}
		if(a[i]=='1' && b[i]=='0'){
			palha++;
			clown.push(i+1);
		}
		if(a[i]=='0' && b[i]=='1'){
			acro++;
			acrobat.push(i+1);
		}
		if(a[i]=='0' && b[i]=='0'){
			vaga++;
			dull.push(i+1);
		}
	}	

	int x=-1;
	int y=-1;

	for(int i=0;i<=ambos;i++)
		for(int j=0;j<=n/2;j++){
			if(i>ambos)	continue;
			if(check(i,j)){
				x=i;
				y=j;	
			}
		}

	if(x==-1){
		cout << x<< endl;
		return 0;
	}

	go(x,y);

}
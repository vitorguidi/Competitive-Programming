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

int n,k,b1,b2;
char op;
int peso[MAXN], pai[MAXN];


int find(int x){	//x eh o elemento do qual eu quero achar o pai

	if(pai[x]==x)	return x;

	return pai[x]=find(pai[x]);

}

void join(int x, int y){	//quero dar join nos conjuntos aos quais x pertence e y pertence

	int pai_x,pai_y;

	pai_x=find(x);
	pai_y=find(y);

	if(pai_x==pai_y)	return;

	if(peso[pai_y]>=peso[pai_x]){
		pai[pai_x]=pai_y;
		peso[pai_y]+=peso[pai_x];
	}

	else{	
		pai[pai_y]=pai_x;
		peso[pai_x]+=peso[pai_y];
	}

	return;


}

int main(){

	cin >> n >> k;

	for(int i=0;i<n;i++){
		pai[i]=i;
		peso[i]=1;
	}

	for (int i=0;i<k;i++){
		cin >> op >> b1 >> b2;

		if(op=='F'){
			join(b1,b2);
		}
		
		else{
			if(find(b1)==find(b2))	cout << 'S' << endl;
			else					cout << 'N' << endl;
		}
	}

	return 0;

}
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


struct intv{
		int l,r,sum;
};

struct node{

	intv prefix,suffix,best,whole;

};

int contas[100100];
int n,q;
node segtree[400400];


bool better(intv a, intv b){

	if(a.sum>b.sum)			//se a soma do intervalo eh maior de a, retorno a
		return true;

	if(a.sum==b.sum){		//soma igual retorna o cara com mais elementos

		if(a.r-a.l>=b.r-b.l)
			return true;

		return false;
	}

	return false;			
}

intv merge_intv(intv a, intv b){

	intv ans;
	ans.sum=a.sum+b.sum;
	ans.l=a.l;
	ans.r=b.r;

	return ans;

}


node merge(node a, node b){

	node ans;				//node que vai ser gerado como resposta
	ans.best.sum=-INF;		//inicializo como -INF pra facilitar as atribuicoes futuras
		
	intv joint;				//intervalo que eh a concatenacao do melhor prefixo de b com o melhor sufixo de a

	joint.l = a.suffix.l;
	joint.r = b.prefix.r;
	joint.sum = a.suffix.sum+b.prefix.sum;

	intv new_whole;

	new_whole.l = a.whole.l;
	new_whole.r = b.whole.r;
	new_whole.sum = a.whole.sum + b.whole.sum;

	intv aux=ans.best;

	if( better(a.best,aux) )
		aux=a.best;

	if( better(b.best,aux) )
		aux=b.best;

	if( better(joint,aux) )
		aux=joint;

	if( better(a.whole,aux) )
		aux=a.whole;

	if( better(b.whole,aux) )
		aux=b.whole;

	if( better(new_whole,aux) )
		aux = new_whole;

	ans.best=aux;

	intv suf_candidate=merge_intv(a.suffix,b.whole);
	
	if( better(suf_candidate,b.suffix) )
		ans.suffix=suf_candidate;
	else
		ans.suffix=b.suffix;

	intv pref_candidate=merge_intv(a.whole,b.prefix);

	if( better(pref_candidate,a.prefix) )
		ans.prefix=pref_candidate;
	else
		ans.prefix=a.prefix;

	ans.whole=new_whole;

	return ans;

}

void build(int no, int i, int j){

	if(j==i){
		
		node aux;
		intv lol;

		lol.sum=contas[i];
		lol.l=lol.r=i;
		
		aux.best=aux.prefix=aux.suffix=aux.whole=lol;
		segtree[no]=aux;
		
		return;
	}

	int mid=(i+j)/2;

	build(2*no,i,mid);
	build(2*no+1,mid+1,j);
	
	segtree[no]=merge(segtree[2*no],segtree[2*no+1]);

}

node query(int no, int i, int j, int a, int b){

	if(i>b || j<a){

		node dummy;

		intv aux;

		aux.sum=-INF;
		
		dummy.best=dummy.prefix=dummy.suffix=aux=dummy.whole=aux;
		return dummy;
	}

	if(i>=a && j<=b)
		return segtree[no];
	

	int mid=(i+j)/2;

	node left=query(2*no,i,mid,a,b);
	node right=query(2*no+1,mid+1,j,a,b);

	if(left.best.sum==-INF)
		return right;
	if(right.best.sum==-INF)
		return left;

	return merge(left,right);

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
    	 cin >> n;

		frr(i,n)
		    cin >> contas[i];

		build(1,1,n);

		cin >> q;

		fr(i,q){
		    int a,b;
		    cin >> a >> b;
		    node ans = query(1,1,n,a,b);
		    cout << ans.best.sum << " " << ans.best.r-ans.best.l+1 << endl;
		}

    }

}

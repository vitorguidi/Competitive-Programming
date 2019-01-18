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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

ll a[200200];

int main(){

    ll t;
    scanf("%I64d",&t);

    while(t--){

        ll n,m,k,x,s;
        
        map<ll,ll> mana;
        set< pll > tal;  

        scanf("%I64d %I64d %I64d %I64d %I64d",&n,&m,&k,&x,&s);

        ll ans = n*x;		//pior resposta possivel eh eu nao usar nada

        for(ll i=0;i<m;i++)
            scanf("%I64d",&a[i]);
        
        for(ll i=0;i<m;i++){
            ll aux;
            scanf("%I64d",&aux);
            if(aux>s)
                continue;

            ans=min( ans, n*a[i] );

            auto it = mana.find(aux);       //tenta adicionar o custo de mana associado ao valor do talento
            if(it==mana.end())              //se ainda nao tenho nada com esse usto de mana, so adiciono
                mana[aux]=a[i];         
            else                                //senao, pego o minimo entre oq ta registrado e oq tenho agora
                mana[aux]=min(a[i],mana[aux]);
        }


        ll best = llINF;

        for(auto a : mana){     //itera em todos os elementos do mapa de mana
                                //note que a ordem do mapa eh do menor custo de mana para o maior, e nao tenho custo de mana repetido
            if(a.snd<best){     //soh adiciono algo com custo de mana maior se eh melhor do que eu ja tenho ate agora
                best=a.snd;
                tal.insert( {a.fst,a.snd} );
            }
        
        }

        tal.insert( {0,x} );    //insiro a possibilidade de nao usar nenhum talento por custo de mana 0

        for(ll i=0;i<k;i++)
            scanf("%I64d",&a[i]);

        for(ll i=0;i<k;i++){        //vou pra todas as pots testar no bruto

            ll aux;
            scanf("%I64d",&aux);
                
            if(aux>s)               //se o custo da pot eh maior do q a mana q posso gastar, vou embora
                continue;
            
            ans=min(ans, (n-a[i])*x );      //levo em conta a possibilidade da pot sozinha ser a melhor resposta

            auto it = tal.lower_bound({s-aux,0ll});     //procuro o talento com o maior custo de mana possivel (o melhor disponivel)
                     
            if(it->fst > s-aux )        //se estourou o custo de mana q eu to procurando, pego o elemento anterior do set
                it--;

            if(aux+it->fst > s)         //se continua estourando, vou embora
                continue;

            ans = min( (n-a[i])*it->snd, ans );     //testo a possibilidade e atualizo a resposta
            
        }

     
        printf("%I64d\n",ans);

    }

}

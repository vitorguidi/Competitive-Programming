#include <bits/stdc++.h>
using namespace std;

bool grid[10100][10100];

bool valid(int x, int y){
    return x>=0 && x<=10000 && y>=0 && y<=10000;
}

void pinta(int x, int y, int r){

    for(int i=-100;i<=100;i++)
        for(int j=-100;j<=100;j++)
            if(valid(x+i,y+j) && i*i+j*j<=r*r )
                grid[x+i][y+j]=true;

}



int main(){
    
    int g; cin >> g;
    vector<pair<int,int>> goblins;

    for(int i=0;i<g;i++){
        int x,y;
        cin >> x >> y;
        goblins.push_back({x,y});
    }

    int s;
    cin >> s;
    vector<pair<int,int>> sprinklers;

    for(int i=0;i<s;i++){
        int x,y,r; cin >> x >> y >> r;
        pinta(x,y,r);
    }

    int cnt = 0;

    for(auto x : goblins)
        if(!grid[x.first][x.second])
            cnt++;

    cout << cnt << endl;

}
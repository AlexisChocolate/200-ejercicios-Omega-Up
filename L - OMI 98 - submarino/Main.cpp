#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >nodo(102);
queue<int>cola;
int n,aristas,tiempo;
bool visitado[102];
int dis[102];

void lectura(void){
    int a,b;
    cin>>n>>aristas>>tiempo;
    tiempo-=2;
    for(int i=1;i<=aristas;i++){
        cin>>a>>b;
        nodo[a].push_back(b);
        nodo[b].push_back(a);
    }
}

int calculo(){
    int cont=0;
    int actual;
    cola.push(n);
    visitado[n]=true;
    dis[n]=0;
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        if(dis[actual]>tiempo) break;
        for(int i=0;i<nodo[actual].size();i++){
            if(!visitado[nodo[actual][i]]){
                visitado[nodo[actual][i]]=true;
                cola.push(nodo[actual][i]);
                dis[nodo[actual][i]]=dis[actual]+1;
                cont++;
            }
        }
    }
    return cont;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    lectura();
    cout<<calculo()<<'\n';

    return 0;
}

#include <bits/stdtr1c++.h>

using namespace std;
struct Arista{
    int u,v;
    int peso;
    const bool operator <(const Arista &otro)const{
        return peso<otro.peso;
    }
};
struct unionFind{
    vector<int>padres;
    vector<int>nivel;
    void init(int n){
        padres.resize(n+2);
        nivel.resize(n+2);
        for(int i=1;i<=n;i++){
            padres[i] = i;
            nivel[i] = 1;
        }
    }
    int padre(int u){
        if(padres[u]==u){
           return u;
        }else{
            return padres[u]=padre(padres[u]);
        }
    }
    bool unir(int u, int v){
        int x = padre(u);
        int y = padre(v);
        if(x!=y){
            if(nivel[x]>nivel[y]){
                padres[y] = x;
            }else if(nivel[y]>nivel[x]){
                padres[x] = y;
            }else{
                padres[x] =y;
                nivel[y]++;
            }
            return true;
        }else{
            return false;
        }
    }
    bool encontrar(int u,int v){
        int x = padre(u);
        int y = padre(v);
        if(x!=y){
            return false;
        }else{
            return true;
        }
    }
};
typedef string String;
int distancia(string str1,string str2){
    int x = 0;
    for (int i = 0; i<4;i++){
        x+=min((max(str1[i], str2[i]) - min(str1[i], str2[i])), ((min(str1[i], str2[i]) + 10)-max(str1[i], str2[i])));
    }
    return x;
}
int main(){
    int n,m;
    cin>>n;
    unionFind uf;
    uf.init(n);
    vector<String>combinaciones;
    combinaciones.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>combinaciones[i];
    }
    vector<Arista>aristas;
    int dist = INT_MAX;
    for(int i=1;i<=n;i++){
        String str1 = combinaciones[i];
        String str2 = "0000";
        int peso = distancia(str1,str2);
        dist = min(dist,peso);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            String str1 = combinaciones[i];
            String str2 = combinaciones[j];
            int peso = distancia(str1,str2);
            Arista a;
            a.u = i;
            a.v = j;
            a.peso = peso;
            aristas.push_back(a);
        }
    }
    sort(aristas.begin(),aristas.end());
    long long int sumaTotal = dist;
    for(Arista a: aristas){
        if(uf.unir(a.u,a.v)){
            sumaTotal+=a.peso;
        }
    }
    cout<<sumaTotal;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,com,i,rango,suma,may;
int precios[1002];

void lectura(){
    cin>>n>>rango;
    for(i=1;i<=n;i++){
        cin>>precios[i];
    }
}

void calculo(){
    suma=0;
    for(i=1;i<=rango;i++){
        suma+=precios[i];
    }
    may=suma;
    i=1;
    while(rango<=n){
        rango++;
        suma-=precios[i];
        suma+=precios[rango];
        if(suma>may){
            may=suma;
        }
        i++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    calculo();
    cout<<may<<'\n';

    return 0;
}

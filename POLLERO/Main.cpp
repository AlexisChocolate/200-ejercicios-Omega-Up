#include <bits/stdc++.h>
using namespace std;
int n,i,bolsa,contador;
int pollo[1000002];

void lectura(int n,int i){
    if(i<=n){
        cin>>pollo[i];
        lectura(n,i+1);
    }
}
int calculo(int i,int b){
    if(b<i){
        return contador;
    }
    if(pollo[i]+pollo[b]<=bolsa){
        contador=contador+(b-i);
        calculo(i+1,b);
    }else{
        calculo(i,b-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>bolsa;
    contador=0;
    i=1;
    lectura(n,i);
    sort(pollo+1,pollo+n+1);
    cout<<calculo(1,n);


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int ini,ini2,r,cont;

int calculo(int a,int b){
    if(a==ini and b==ini2){
        cout<<'\n';
        cont++;
        return cont;
    }else{
        cont++;
        r=a+b;
        if(r>=10){
            r=r-10;
        }
        cout<<r<<" ";
        calculo(b,r);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>ini>>ini2;
    cout<<ini<<" "<<ini2<<" ";
    cont=0;
    r=ini+ini2;
    if(r>=10){
        r=r-10;
    }
    cout<<r<<" ";
    cout<<calculo(ini2,r);


    return 0;
}

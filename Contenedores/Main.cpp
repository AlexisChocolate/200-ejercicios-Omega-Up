#include <bits/stdc++.h>
using namespace std;
long long int i,n,s,r,b,cont,a,k,j;
long long int p[100002],orden[100002],almacen[1000002];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>p[i];
        orden[i]=p[i];
        s+=p[i];
    }
    sort(p+1,p+n+1);
    if(s%2==0){
        s=s/2;
    }else{
        s=s/2-1;
    }
    i=1; r=0; cont=0; b=0; a=1; k=1;
    while(i<=n){
        if(r>=2){
            break;
        }
        b+=p[i];
        if(b<=s){
            cont++;
            j=1;
            while(j<=n){
                if(orden[j]==p[i]){
                    almacen[k]=j;
                    orden[j]=-1;
                    k++;
                    i++;
                    break;
                }
                j++;
            }
        }else{
            cout<<cont<<" ";
            r++;
            while(k>1){
                k--;
                cout<<almacen[k]<<" ";
            }
            cout<<'\n';
            cont=0;
            b=0;
            k=1;
        }
    }
    if(r<2 and b<=s){
        cout<<cont<<" ";
        while(k>1){
            k--;
            cout<<almacen[k]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct PUNTO{
  int height,rA,rB;
};
PUNTO point[1000002];
vector<vector<int> >node(1000002);
bool visited[1000002];
int n,q,height=1;

void Read(){
  int u,v;
  cin>>n>>q;
  for(int i=1;i<n;i++){
    cin>>u>>v;
    node[u].push_back(v);
    node[v].push_back(u);
  }
}

int Travel(int pos,int route){
  visited[pos]=true;
  point[pos].height=height;
  point[pos].rA=route;
  for(int i=0;i<node[pos].size();i++){
    if(!visited[node[pos][i]]){
      height++;
      route=Travel(node[pos][i],route)+1;
      height--;
    }
  }
  point[pos].rB=route;
  return route;
}

void Answers(){
  int a,b;
  for(int i=1;i<=q;i++){
    cin>>a>>b;
    if(point[a].height<=point[b].height and point[a].rA<=point[b].rA and
    point[a].rB>=point[b].rB) cout<<0<<'\n';
    else cout<<1<<'\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  Read();
  Travel(1,1);
  Answers();

}

#include<bits/stdc++.h>
using namespace std;
#define LL long long
vector<int>edge[1000];
int bfs(int t){
    int d[1000];
    int i,ck;
    for(i=0;i<t;i++) d[i]=-1;
    queue<int>q;
    q.push(0);
    d[0]=0;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        ck=1;
        for(i=0;i<edge[v].size();i++){
            int u=edge[v][i];
            if(d[u]==-1){
                if(d[v]==0) d[u]=1;
                else d[u]=0;
                q.push(u);
            }
            else if(d[v]==d[u]){
                ck=0;
                return 0;
            }
        }
    }
    if(ck) return 1;

}

int main(){
    int N,E,i,x,y;
    while(scanf("%lld",&N)==1){
        if(N==0) break;
        cin>>E;
        for(i=0;i<N;i++){
            edge[i].clear();
        }
        for(i=0;i<E;i++){
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        if(bfs(N)) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;

    }

    return 0;
}

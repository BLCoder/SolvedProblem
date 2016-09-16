#include<bits/stdc++.h>
using namespace std;
#define MAX 102
vector<int>edge[MAX],cost[MAX];
int dis[MAX];
void bfs(int n,int N){
    queue<int>q;
    q.push(n);
    for(int i=0;i<=N;i++) dis[i]=1e9;
    dis[n]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            if(dis[edge[u][i]]>dis[u]+cost[u][i]){
                dis[edge[u][i]]=dis[u]+cost[u][i];
                q.push(edge[u][i]);
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int j=0;j<m;j++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        bfs(1,n);
        printf("Case %d: ",i);
        if(dis[n]==1e9) printf("Impossible\n");
        else printf("%d\n",dis[n]);
        for(int j=0;j<=n;j++){
            edge[j].clear();
            cost[j].clear();
        }
    }
}

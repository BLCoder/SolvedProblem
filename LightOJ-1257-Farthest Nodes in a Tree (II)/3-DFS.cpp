#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
#define f first
#define s second
struct node{
    int u,v;
}ver;
vector<node>edge[MAX];
int dis[MAX],visit[MAX];
int check[MAX];
int mx=-1,tt;
void dfs(int n){
    visit[n]=1;
    for(int i=0;i<edge[n].size();i++){
        if(visit[edge[n][i].u]==0){
            dis[edge[n][i].u]=dis[n]+edge[n][i].v;
            visit[edge[n][i].u]=1;
            if(dis[edge[n][i].u]>check[edge[n][i].u]){
                check[edge[n][i].u]=dis[edge[n][i].u];
            }
            if(dis[edge[n][i].u]>mx){
                mx=dis[edge[n][i].u];
                tt=edge[n][i].u;
            }
            dfs(edge[n][i].u);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        for(int j=1;j<n;j++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ver.u=v,ver.v=w;
            edge[u].push_back(ver);
            ver.u=u,ver.v=w;
            edge[v].push_back(ver);
        }
        printf("Case %d:\n",i);
        tt=0;
        int color[MAX];
        while(color[tt]!=1){
            color[tt]=1;
            mx=-1;
            dis[tt]=0;
            memset(visit,0,sizeof(visit));
            dfs(tt);
        }
        for(int j=0;j<n;j++){
            printf("%d\n",check[j]);
        }
        for(int i=0;i<=n;i++){
            edge[i].clear();
            color[i]=0;
            check[i]=0;
        }
    }
}

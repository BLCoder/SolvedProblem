#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
vector<int>edge[MAX],cost[MAX];
int dis[MAX],visit[MAX];
int color[MAX];
int check[MAX];
int mx=-1,tt;
void dfs(int n){
    visit[n]=1;
    for(int i=0;i<edge[n].size();i++){
        if(visit[edge[n][i]]==0){
            dis[edge[n][i]]=dis[n]+cost[n][i];
            visit[edge[n][i]]=1;
            if(dis[edge[n][i]]>check[edge[n][i]]){
                check[edge[n][i]]=dis[edge[n][i]];
            }
            if(dis[edge[n][i]]>mx){
                mx=dis[edge[n][i]];
                tt=edge[n][i];
            }
            dfs(edge[n][i]);
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
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        printf("Case %d:\n",i);
        tt=0;
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
            cost[i].clear();
        }
        memset(check,0,sizeof(check));
        memset(color,0,sizeof(color));
    }
}

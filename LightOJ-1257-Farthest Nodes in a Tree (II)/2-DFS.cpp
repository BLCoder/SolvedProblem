#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
#define f first
#define s second
vector<pair<int,int> >edge[MAX];
int dis[MAX],visit[MAX];
int check[MAX];
int mx=-1,tt;
void dfs(int n){
    visit[n]=1;
    for(int i=0;i<edge[n].size();i++){
        if(visit[edge[n][i].f]==0){
            dis[edge[n][i].f]=dis[n]+edge[n][i].s;
            visit[edge[n][i].f]=1;
            if(dis[edge[n][i].f]>check[edge[n][i].f]){
                check[edge[n][i].f]=dis[edge[n][i].f];
            }
            if(dis[edge[n][i].f]>mx){
                mx=dis[edge[n][i].f];
                tt=edge[n][i].f;
            }
            dfs(edge[n][i].f);
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
            edge[u].push_back({v,w});
            edge[v].push_back({u,w});
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

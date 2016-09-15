#include<bits/stdc++.h>
using namespace std;
#define MAX 150
vector<int>edge[MAX];
int visit[MAX];
int dis1[MAX],dis2[MAX];
int mx=0;
void bfs(int n){
    visit[n]=1;
    queue<int>q;
    dis1[n]=0;
    q.push(n);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            if(visit[edge[u][i]]==0){
                visit[edge[u][i]]=1;
                dis1[edge[u][i]]=dis1[u]+1;
                dis2[edge[u][i]]+=dis1[edge[u][i]];
                if(dis2[edge[u][i]]>mx) mx=dis2[edge[u][i]];
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
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int s,d;
        scanf("%d%d",&s,&d);
        mx=0;
        bfs(s);
        memset(visit,0,sizeof(visit));
        mx=0;
        bfs(d);
        printf("Case %d: %d\n",i,mx);
        for(int j=0;j<=n;j++){
            edge[j].clear();
            dis2[j]=0;
        }
        memset(visit,0,sizeof(visit));
        //memset(dis1,0,sizeof(dis1));
        //memset(dis2,0,sizeof(dis2));
    }
}

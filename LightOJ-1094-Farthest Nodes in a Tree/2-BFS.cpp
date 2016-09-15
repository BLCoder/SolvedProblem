#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX 30005
#define f first
#define s second
vector<pair<int,int> >edge[MAX];
vector<int>cost[MAX];
int visit[MAX],dis[MAX];
int bfs(int n,int N){
    memset(visit,0,sizeof(visit));
    queue<int>q;
    int mx=-1,m1;
    for(int i=0;i<N;i++) dis[i]=1e9;
    q.push(n);
    dis[n]=0;
    visit[n]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            if(dis[edge[u][i].f]>dis[u]+edge[u][i].s&&visit[edge[u][i].f]==0){
                dis[edge[u][i].f]=dis[u]+edge[u][i].s;
                visit[edge[u][i].f]==1;
                q.push(edge[u][i].f);
                if(mx<dis[edge[u][i].f]){
                    mx=dis[edge[u][i].f];
                    m1=edge[u][i].f;
                }
            }
        }
    }

   return m1;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge[u].push_back({v,w});
            edge[v].push_back({u,w});
        }
        printf("Case %d: %d\n",k,dis[bfs(bfs(0,n),n)]);
        for(int i=0;i<n;i++) edge[i].clear();
    }
}

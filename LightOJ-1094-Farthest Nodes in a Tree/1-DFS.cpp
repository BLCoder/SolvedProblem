#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX 30005
#define f first
#define s second
vector<pair<int,int> >edge[MAX];
vector<int>cost[MAX];
int visit[MAX],dis[MAX];
int mxx=-1,m1;
void dfs(int n){
    visit[n]=1;
    for(int i=0;i<edge[n].size();i++){
        if(visit[edge[n][i].f]==0){
            dis[edge[n][i].f]=dis[n]+edge[n][i].s;
            if(dis[edge[n][i].f]>mxx){
                mxx=dis[edge[n][i].f];
                m1=edge[n][i].f;
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
    for(int k=1;k<=t;k++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            edge[u].push_back({v,w});
            edge[v].push_back({u,w});
        }
        mxx=-1;
        dfs(0);
        mxx=-1;
        memset(visit,0,sizeof(visit));
        dis[m1]=0;
        dfs(m1);
        printf("Case %d: %d\n",k,dis[m1]);
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++) edge[i].clear();
    }
}

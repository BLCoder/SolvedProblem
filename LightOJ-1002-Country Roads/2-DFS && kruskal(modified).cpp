#include<bits/stdc++.h>
using namespace std;
#define MAX 502
//#define f first
//#define s second
struct edge{
    int u,v,w;
    bool operator<(const edge&p) const{
        return w<p.w;
    }
}ver;
struct edge1{
    int U,V;
}ver1;
vector<edge>e;
vector<edge1>eg[MAX];
int visit[MAX];
int pr[MAX];
int parent[MAX];
int maxx[MAX];
int mx=-1;
int find(int r){
   return (parent[r]==r)?r:parent[r]=find(parent[r]);
}
void mst(int n){
    sort(e.begin(),e.end());
    for(int i=0;i<=n;i++) parent[i]=i;
    int cnt=0;
    for(int i=0;i<e.size();i++){
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v){
            ver1.U=e[i].v,ver1.V=e[i].w;
            eg[e[i].u].push_back(ver1);
            ver1.U=e[i].u,ver1.V=e[i].w;
            eg[e[i].v].push_back(ver1);
            parent[u]=v;
            cnt++;
            if(cnt==n-1) break;
        }
    }
}
void dfs(int n){
    visit[n]=1;
    for(int i=0;i<eg[n].size();i++){
        if(visit[eg[n][i].U]==0){
            visit[eg[n][i].U]=1;
            mx=max(mx,eg[n][i].V);
            maxx[eg[n][i].U]=mx;
            //cout<<eg[n][i]<<" "<<mx<<endl;
            pr[eg[n][i].U]=n;
            dfs(eg[n][i].U);
        }
    }
    mx=maxx[n];
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,m;
        scanf("\n%d%d",&n,&m);
        for(int j=0;j<m;j++){
            int u,v,w;
            scanf("%d%d%d",&ver.u,&ver.v,&ver.w);
            e.push_back(ver);
        }
        int sr;
        scanf("%d",&sr);
        mst(n);
        mx=-1;
        memset(pr,-1,sizeof(pr));
        dfs(sr);
        printf("Case %d:\n",i);
        for(int j=0;j<n;j++){
            if(pr[j]==-1&&j!=sr) printf("Impossible\n");
            else printf("%d\n",maxx[j]);
        }
        for(int j=0;j<=n;j++){
            eg[j].clear();
        }
        e.clear();
        memset(visit,0,sizeof(visit));
        memset(maxx,0,sizeof(maxx));
    }
}

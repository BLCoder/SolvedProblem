#include<bits/stdc++.h>
using namespace std;
#define MAX 1002
#define LL long long
int edge[MAX][MAX];
vector<LL int>edj[MAX*MAX];
LL int adj[MAX][MAX];
int dis[MAX*MAX];
int par[MAX];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void bfs(int n,int N){
    for(int i=0;i<=N;i++) dis[i]=1e9;
    queue<int>q;
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edj[u].size();i++){
            if(dis[edj[u][i]]>dis[u]+1){
                dis[edj[u][i]]=dis[u]+1;
                q.push(edj[u][i]);
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x,y;
    while(~scanf("%d%d",&x,&y)){
        if(x==0||y==0) break;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int r,e;
            scanf("%d%d",&r,&e);
            for(int j=0;j<e;j++){
                int a;
                scanf("%d",&a);
                edge[r][a]=1;
            }
        }
        LL int k=1;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                adj[i][j]=k++;
            }
        }
        LL int rr=k;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<4;k++){
                    int xx,yy;
                    xx=i+fx[k];
                    yy=j+fy[k];
                    if(xx>=0 &&yy>=0 && xx<x && yy<y&&edge[xx][yy]==0){
                        edj[adj[i][j]].push_back(adj[xx][yy]);
                    }
                }
            }
        }
        int sx,sy,dx,dy;
        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
        bfs(adj[sx][sy],k);
        if(dis[adj[dx][dy]]==1e9) printf("-2\n");
        else printf("%d\n",dis[adj[dx][dy]]);
        for(int i=0;i<=rr;i++) edj[i].clear();
        memset(edge,0,sizeof(edge));
        memset(adj,0,sizeof(adj));
    }
}

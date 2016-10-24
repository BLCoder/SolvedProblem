#include<bits/stdc++.h>
using namespace std;
#define MAX 1002
#define LL long long
int edge[MAX][MAX];
int dis[MAX][MAX];
struct eg{
    int u,v;
};
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int bfs(int x1,int y1,int x2,int y2,int xx,int yy){
    queue<eg>q;
    for(int i=0;i<xx;i++)
        for(int j=0;j<yy;j++)
            dis[i][j]=1e9;
    eg uu,vv;
    uu.u=x1,uu.v=y1;
    dis[x1][y1]=0;
    q.push(uu);
    while(!q.empty()){
        uu=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=fx[i]+uu.u;
            int y=fy[i]+uu.v;
            if(x>=0 and y>=0 and x<xx and y<yy and edge[x][y]==0){
                if(dis[x][y]>dis[uu.u][uu.v]+1){
                    dis[x][y]=dis[uu.u][uu.v]+1;
                    vv.u=x,vv.v=y;
                    q.push(vv);
                }
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0 or m==0) break;
        int x;
        scanf("%d",&x);
        for(int i=0;i<x;i++){
            int r,e;
            scanf("%d%d",&r,&e);
            for(int j=0;j<e;j++){
                int u;
                scanf("%d",&u);
                edge[r][u]=1;
            }
        }
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        bfs(x1,y1,x2,y2,n,m);
        if(x1==x2 and y1==y2) printf("1\n");
        else if(dis[x2][y2]==1e9) printf("-2\n");
        else printf("%d\n",dis[x2][y2]);
        memset(edge,0,sizeof(edge));
    }
}

#include<bits/stdc++.h>
using namespace std;
#define MAX 102
vector<int>edge[MAX],cost[MAX];
int d[MAX];
struct data{
    int city,dist;
    bool operator<(const data&p)const{
        return dist>p.dist;
    }
};
void dijsktra(int n,int N){
    priority_queue<data>q;
    for(int i=0;i<=N;i++) d[i]=1e9;
    d[n]=0;
    data u,v;
    u.city=n,u.dist=0;
    q.push(u);
    d[n]=0;
    while(!q.empty()){
        u=q.top();
        int ucost=d[u.city];
        q.pop();
        for(int i=0;i<edge[u.city].size();i++) {
            v.city=edge[u.city][i],v.dist=cost[u.city][i]+ucost;
            if(d[v.city]>cost[u.city][i]+ucost){
                d[v.city]=cost[u.city][i]+ucost;
                q.push(v);
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
        dijsktra(1,n);
        printf("Case %d: ",i);
        if(d[n]==1e9) printf("Impossible\n");
        else printf("%d\n",d[n]);
        for(int j=0;j<=n;j++){
            edge[j].clear();
            cost[j].clear();
        }
    }
}

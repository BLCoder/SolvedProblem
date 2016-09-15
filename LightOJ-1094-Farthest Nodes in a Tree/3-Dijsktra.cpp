#include<bits/stdc++.h>
using namespace std;
#define MAX  30003
#define LL long long
vector<int>edge[MAX];
vector <int>cost[MAX];
vector<LL int>d;
struct data{
    int city,dist;
    bool operator<(const data&p)const{
        return dist>p.dist;
    }
};
LL int dijsktra(int n,int N){
    priority_queue<data>q;
    int mx=-1;
    for(int i=0;i<N;i++) d.push_back(1000000000);
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
                if(d[v.city]>mx) mx=d[v.city];
                q.push(v);
            }
        }
    }
    return mx;
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
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        LL int t1=dijsktra(0,n);
        LL int t3,mx=-1,ar[MAX],r=0;
        for(int i=0;i<n;i++){
            if(d[i]==t1){
                ar[r]=i;
                r++;
            }
        }
        for(int i=0;i<r;i++){
            d.clear();
            t3=dijsktra(ar[i],n);
            mx=max(mx,t3);
        }
        for(int i=0;i<n;i++) edge[i].clear();
        for(int i=0;i<n;i++) cost[i].clear();
        d.clear();
        printf("Case %d: %d\n",k,mx);
    }
}

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
vector<int>edge[MAX];
int visit[MAX];
int color[MAX];
int dis[MAX];
int bfs(int n){
    queue<int>q;
    q.push(n);
    visit[n]=1;
    color[n]=1;
    int cnt1=1,cnt2=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            if(visit[edge[u][i]]==0){
                visit[edge[u][i]]=1;
                q.push(edge[u][i]);
                if(color[u]==1) color[edge[u][i]]=2,cnt2++;
                else color[edge[u][i]]=1,cnt1++;
            }
        }
    }
    return max(cnt1,cnt2);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        map<int,int>mp;
        for(int j=0;j<n;j++){
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
            mp[u]++;
            mp[v]++;
        }
        int mx=0;
        map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            if(visit[it->first]==0){
                mx+=bfs(it->first);
            }
        }
        printf("Case %d: %d\n",i,mx);
        for(it=mp.begin();it!=mp.end();it++){
            edge[it->first].clear();
        }
        mp.clear();
        memset(color,0,sizeof(color));
        memset(visit,0,sizeof(visit));
    }
}

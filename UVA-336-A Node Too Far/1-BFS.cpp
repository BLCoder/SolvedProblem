#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100000];
int visit[100000];
map<int,int>mp;
set<int>ss;
void bfs(int n1,int n2){
    queue<int>q;
    q.push(n1);
    visit[n1]=1;
    mp[n1]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(mp[cur]!=n2){
            for(int i=0;i<edge[cur].size();i++){
                if(visit[edge[cur][i]]==0){
                    int t=mp[cur]+1;
                    visit[edge[cur][i]]=1;
                    mp[edge[cur][i]]=t;
                    if(mp[edge[cur][i]]!=n2) q.push(edge[cur][i]);
                }
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,T=1;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
            //p[a]++;
            //p[b]++;
            ss.insert(a);
            ss.insert(b);
        }
        int aa,bb;
        while(scanf("%d%d",&aa,&bb)!=EOF){
            memset(visit,0,sizeof(visit));
            if(aa==0&&bb==0) break;
            int ck=1;
            if(edge[aa].size()!=0){
                    bfs(aa,bb);
                    ck=0;
            }
            if(ck==0) printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",T++,ss.size()-mp.size(),aa,bb);
            else printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",T++,ss.size(),aa,bb);
            mp.clear();
        }
        for(auto it:ss){
            edge[it].clear();
        }
        ss.clear();
    }
}


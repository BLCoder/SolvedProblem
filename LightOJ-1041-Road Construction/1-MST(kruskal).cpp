#include<bits/stdc++.h>
using namespace std;
#define MAX 250
int parent[MAX];
map<string,int>mp;
struct edge{
    int u,v,w;
    bool operator<(const edge&p) const{
        return w<p.w;
    }
}ver;
vector<edge>e;
int find(int r){
   return (parent[r]==r)?r:parent[r]=find(parent[r]);
}
int mst(int n){
    sort(e.begin(),e.end());
    for(int i=0;i<=n;i++) parent[i]=i;
    int cnt=0,s=0;
    for(int i=0;i<e.size();i++){
        int u=find(e[i].u);
        int v=find(e[i].v);
        if(u!=v){
            parent[u]=v;
            cnt++;
            if(cnt!=n) s+=e[i].w;
           // s+=e[i].w;
            //if(cnt==n-1) break;
        }
    }
    return s;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("\n%d",&n);
        int st=1;
        for(int ii=0;ii<n;ii++){
            string u,v;
            int w;
            cin>>u>>v;
            scanf("%d",&w);
            if(mp[u]==0) mp[u]=st++;
            if(mp[v]==0) mp[v]=st++;
            ver.u=mp[u];
            ver.v=mp[v];
            ver.w=w;
            e.push_back(ver);
        }
        int sz=mp.size();
        int mn=mst(sz);
        set<int>s;
        for(int j=1;j<=sz;j++){
            s.insert(find(j));
        }
        if(s.size()==1) printf("Case %d: %d\n",i,mn);
        else printf("Case %d: Impossible\n",i);
        s.clear();
        mp.clear();
        for(int j=0;j<=sz;j++){
            e.clear();
        }
    }
}

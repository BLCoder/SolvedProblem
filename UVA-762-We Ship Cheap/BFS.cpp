#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
map<string,int>mp;
map<int,string>mp1;
vector<int>edge[MAX];
int par[MAX];
int visit[MAX];
int d[MAX];
int ar[MAX];
int t=0;
void bfs(int n,int N){
    for(int i=0;i<=N;i++) d[i]=1e9;
    queue<int>q;
    q.push(n);
    d[n]=0;
    par[n]=n;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            if(d[edge[u][i]]>d[u]+1){
                d[edge[u][i]]=d[u]+1;
                par[edge[u][i]]=u;
                q.push(edge[u][i]);
            }
        }
    }
}
void find(int src,int dis){
    ar[t++]=dis,ar[t++]=par[dis];
    if(par[dis]==src) return;
    find(src,par[dis]);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int e,c=0;
    while(~scanf("%d",&e)){
        int n=1;
        for(int i=0;i<e;i++){
            string s1,s2;
            cin>>s1>>s2;
            if(mp[s1]==0) mp[s1]=n,mp1[n]=s1,n++;
            if(mp[s2]==0) mp[s2]=n,mp1[n]=s2,n++;
            edge[mp[s1]].push_back(mp[s2]);
            edge[mp[s2]].push_back(mp[s1]);
        }
        string s1,s2;
        cin>>s1>>s2;
        if(c==1) printf("\n");
        if(mp[s1]==0||mp[s2]==0) printf("No route\n");
        else{
            t=0;
            int src,dis;
            src=mp[s1],dis=mp[s2];
            bfs(src,n-1);
            if(d[dis]==1e9) printf("No route\n");
            else{
                find(src,dis);
                for(int j=t-1;j>=0;j-=2){
                    cout<<mp1[ar[j]]<<" "<<mp1[ar[j-1]]<<endl;
                }
            }
        }
        mp.clear();
        mp1.clear();
        for(int i=0;i<=n;i++){
            edge[i].clear();
        }
        c=1;
    }
}

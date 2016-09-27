#include<bits/stdc++.h>
using namespace std;
#define MAX 202
vector<int>edge[MAX];
int visit[MAX];
int ck;
void dfs(int n){
    for(int i=0;i<edge[n].size();i++){
        if(visit[edge[n][i]]==-1){
            if(visit[n]==1) visit[edge[n][i]]=2;
            else visit[edge[n][i]]=1;
            dfs(edge[n][i]);
        }
        if(visit[n]==visit[edge[n][i]]){
            ck=1;
            return;
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        int e;
        scanf("%d",&e);
        for(int i=0;i<e;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        memset(visit,-1,sizeof(visit));
        visit[0]=1;
        ck=0;
        dfs(0);
        if(ck==0) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
        for(int i=0;i<=n;i++){
            edge[i].clear();
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1005];
void bfs(int n,int av,int ar[]){
    queue<int>q;
    q.push(n);
    int ck=0;
    int visit[1005];
    memset(visit,0,sizeof(visit));
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<edge[cur].size();i++){
            if(ar[edge[cur][i]]>av){
                int t1=av-ar[n];
                int t2=ar[edge[cur][i]]-av;
                if(t1<=t2){
                    ar[n]+=t1;
                    ar[edge[cur][i]]-=t1;
                }
                else{
                    ar[n]+=t2;
                    ar[edge[cur][i]]-=t2;
                }
            }
            if(visit[edge[cur][i]]==0){
                q.push(edge[cur][i]);
                visit[edge[cur][i]]=1;
            }
            if(ar[n]==av){
                return;
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
        int n,m,mn[1005],sum=0;
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++){
            scanf("%d",&mn[j]);
            sum+=mn[j];
        }
        for(int j=0;j<m;j++){
            int v1,v2;
            scanf("%d%d",&v1,&v2);
            edge[v1].push_back(v2);
            edge[v2].push_back(v1);
        }
        if(sum%n!=0) printf("Case %d: No\n",i);
        else{
            int t1=sum/n;
            for(int j=1;j<=n;j++){
                if(mn[j]<t1){
                    bfs(j,t1,mn);
                }
            }
            int ck=0;
            for(int j=1;j<=n;j++){
                if(mn[j]<t1 ||mn[j]>t1){
                    ck=1;
                    break;
                }
            }
            if(ck==1) printf("Case %d: No\n",i);
            else printf("Case %d: Yes\n",i);
        }
        for(int j=1;j<=n;j++) edge[j].clear();
    }
}

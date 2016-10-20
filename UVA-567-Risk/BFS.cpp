#include<bits/stdc++.h>
using namespace std;
#define MAX 22
vector<int>edge[MAX];
int dis[MAX];
void bfs(int n,int N){
    for(int i=0;i<=N;i++) dis[i]=1e9;
    queue<int>q;
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<edge[u].size();i++){
            if(dis[edge[u][i]]>dis[u]+1){
                dis[edge[u][i]]=dis[u]+1;
                q.push(edge[u][i]);
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,a,e=1,T=1;
    while(~scanf("%d",&n)){
        e=1;
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            edge[e].push_back(m);
            edge[m].push_back(e);
        }
        for(int i=2;i<=19;i++){
            scanf("%d",&n);
            for(int j=0;j<n;j++){
                scanf("%d",&a);
                edge[i].push_back(a);
                edge[a].push_back(i);
            }
        }
        printf("Test Set #%d\n",T++);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int n1,n2;
            scanf("%d%d",&n1,&n2);
            bfs(n1,20);
            if(n1<10) printf(" %d to ",n1);
            else printf("%d to ",n1);
            if(n2<10) printf(" %d",n2);
            else printf("%d",n2);
            printf(": %d\n",dis[n2]);
        }
        printf("\n");
        for(int i=0;i<=21;i++) edge[i].clear();
    }
}

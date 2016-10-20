#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
map<string,int>mp;
vector<int>edge[MAX];
int visit[MAX];
int ck=0;
char s1[100];
char s2[100];
void dfs(int n){
    visit[n]=1;
    int i;
    for(i=0;i<edge[n].size();i++){
        if(visit[edge[n][i]]==1){
            ck=1;
            return;
        }
        if(visit[edge[n][i]]==0){
            dfs(edge[n][i]);
        }
    }
    visit[n]=2;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    //GETINT(t);
    for(int i=1;i<=t;i++){
        printf("Case %d: ",i);
        int n;
        scanf("%d",&n);
        int cnt=1;
        for(int j=0;j<n;j++){
            scanf("%s",s1);
            scanf("%s",s2);
            if(mp[s1]==0) mp[s1]=cnt++;
            if(mp[s2]==0) mp[s2]=cnt++;
            edge[mp[s1]].push_back(mp[s2]);
        }
        ck=0;
        for(int j=1;j<cnt;j++){
            if(visit[j]==0){
                dfs(j);
                if(ck==1){
                    printf("No\n");
                    break;
                }
            }
        }
        if(ck==0) printf("Yes\n");
        mp.clear();
        for(int j=0;j<=cnt;j++){
            edge[j].clear();
        }
        memset(visit,0,sizeof(visit));
    }
}

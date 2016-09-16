#include<bits/stdc++.h>
using namespace std;
#define MAX 22
char edge[MAX][MAX];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int cnt=0;
void dfs(int i,int j){
    for(int k=0;k<4;k++){
        int x=i+fx[k];
        int y=j+fy[k];
        if(edge[x][y]=='.'){
            edge[x][y]='#';
            cnt++;
            dfs(x,y);
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
        scanf("%d%d\n",&n,&m);
        for(int j=0;j<m;j++){
            gets(edge[j]);
        }
        cnt=0;
        for(int j=0;j<m;j++){
            for(int k=0;k<strlen(edge[j]);k++){
                if(edge[j][k]=='@'){
                    dfs(j,k);
                    break;
                }
            }
        }
        memset(edge,0,sizeof(edge));
        printf("Case %d: %d\n",i,++cnt);
    }
}

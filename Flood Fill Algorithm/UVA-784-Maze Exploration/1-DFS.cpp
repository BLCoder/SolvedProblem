#include<bits/stdc++.h>
using namespace std;
char edge[100][100];
int visit[100][100];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void dfs(int i,int j){
    for(int k=0;k<4;k++){
        int x=i+fx[k];
        int y=j+fy[k];
        if(edge[x][y]==' '){
            visit[x][y]=1;
            edge[x][y]='#';
            dfs(x,y);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d\n",&n);
    int ck=0;
    while(n--){
        int t=0;
        while(gets(edge[t])){
            if(edge[t][0]=='_') break;
                t++;
        }
        for(int ii=0;ii<=t;ii++){
            for(int j=0;j<strlen(edge[ii]);j++){
                if(edge[ii][j]=='*'&&visit[ii][j]==0){
                    visit[ii][j]=1;
                    edge[ii][j]='#';
                    dfs(ii,j);
                }
            }
        }
        memset(visit,0,sizeof(visit));
        for(int ii=0;ii<=t;ii++) puts(edge[ii]);
    }
}


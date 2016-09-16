#include<bits/stdc++.h>
using namespace std;
char edge[100][100];
int visit[100][100];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void dfs1(int i,int j,char s1){
    for(int k=0;k<4;k++){
        int x=i+fx[k];
        int y=j+fy[k];
        if(edge[x][y]==' '){
            visit[x][y]=1;
            edge[x][y]=s1;
            dfs1(x,y,s1);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    while(gets(edge[0])){
        t=1;
        while(gets(edge[t])){
            if(edge[t][0]=='_') break;
            t++;
        }
        memset(visit,0,sizeof(visit));
        for(int i=0;i<t;i++){
            for(int j=0;j<strlen(edge[i]);j++){
                //int len=strlen(edge[i]);
                if(edge[i][j]!='X'&&edge[i][j]!=' '&&visit[i][j]==0){
                    visit[i][j]=1;
                    dfs1(i,j,edge[i][j]);
                }
            }
        }
        for(int i=0;i<=t;i++){
            puts(edge[i]);
        }
    }
}

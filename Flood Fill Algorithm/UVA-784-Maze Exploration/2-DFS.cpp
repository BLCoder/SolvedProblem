#include<bits/stdc++.h>
using namespace std;
char edge[100][100];
int visit[100][100];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void dfs(int i,int j,int lo,int hi){
    if(i<0||j<0||i>=lo||j>=hi) return;
    if(edge[i][j]!='X'&&visit[i][j]==0){
        edge[i][j]='#';
        visit[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+fx[k];
            int y=j+fy[k];
            dfs(x,y,lo,(strlen(edge[x])));
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int ck=0;
    for(int i=0;i<n;i++){
        int t=0;
        while(gets(edge[t])){
            if(edge[t][0]=='_') break;
            t++;
        }
        for(int ii=0;ii<t;ii++){
            for(int j=0;j<strlen(edge[ii]);j++){
                if(edge[ii][j]=='*'&&visit[ii][j]==0){
                    dfs(ii,j,t,strlen(edge[ii]));
                }
            }
           // cout<<endl;
        }
        memset(visit,0,sizeof(visit));
        int ii;
        if(ck==0) ii=1;
        else ii=0;
        for(;ii<=t;ii++){
            cout<<edge[ii]<<endl;
        }
        ck=1;
    }
}


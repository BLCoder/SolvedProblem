#include<bits/stdc++.h>
using namespace std;
#define MAX 205
int edge[MAX][MAX];
int visit[MAX][MAX];
int dx[]={-1,-1,0,0,+1,+1};
int dy[]={-1,0,-1,+1,0,+1};
int rr=0;
void dfs1(int i,int j,int sn,int n){
    if(i==n-1) rr=1;
    visit[i][j]=1;
    for(int k=0;k<6;k++){
        int x=dx[k]+i;
        int y=dy[k]+j;
        if(i>=0 and j>=0 and i<n and j<n and edge[x][y]==sn&&visit[x][y]==0){
            dfs1(x,y,sn,n);
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t=1;
    while(~scanf("%d",&n)){
        if(n==0) break;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++){
                if(s[j]=='b') edge[i][j]=1;
            }
        }
        int ck1=0,ck2=0,r1,r2;
        rr=0;
        for(int j=0;j<n;j++){
                rr=0;
                if(edge[0][j]==1 and visit[0][j]==0){
                        dfs1(0,j,1,n);
                        if(rr==1){
                            ck2=1;
                            ck1=1;
                            break;
                        }
                    }
        }
        if(ck1==1) printf("%d B\n",t++);
        else printf("%d W\n",t++);
        memset( edge,0,sizeof(edge));
        memset( visit,0,sizeof(visit));
    }
}

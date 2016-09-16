#include<bits/stdc++.h>
using namespace std;
int edge[100+5][100+5];
int visit[100+5][100+5];
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
string s;
void dfs(int i,int j,int n,int m){
    if(i<0 ||j<0 || i>=n || j>=m) return ;
    if(edge[i][j]==1&&visit[i][j]==0){
        visit[i][j]=1;
        for(int k=0;k<8;k++){
            int x=i+fx[k];
            int y=j+fy[k];
            dfs(x,y,n,m);
        }
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0||m==0) break;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='*') edge[i][j]=0;
                else edge[i][j]=1;
            }
        }
        int cnt=0;memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(edge[i][j]==1&&visit[i][j]==0){
                    cnt++;
                    dfs(i,j,n,m);
                }
            }
        }
        cout<<cnt<<endl;
    }
}

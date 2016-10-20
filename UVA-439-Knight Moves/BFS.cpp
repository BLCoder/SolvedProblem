#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int edge[MAX][MAX];
int visit[MAX][MAX];
int dx[]={-2,-2,-1,+1,+2,+2,+1,-1};
int dy[]={-1,+1,+2,+2,+1,-1,-2,-2};
struct eg{
    int u,v;
};
int bfs(int xx,int yy,int d1,int d2){
    queue<eg>q;
    eg uu,vv;
    uu.u=xx,uu.v=yy;
    q.push(uu);
    visit[xx][yy]=1;
    while(!q.empty()){
        uu=q.front();
        q.pop();
        for(int k=0;k<8;k++){
            int x=dx[k]+uu.u;
            int y=dy[k]+uu.v;
            if(x>=0 and y>=0 and x<8 and y<8 and visit[x][y]==0){
                //cout<<uu.u<<" "<<uu.v<<" "<<x<<" "<<y<<" ";
                visit[x][y]+=visit[uu.u][uu.v]+1;
                if(x==d1 and y==d2){
                    //cout<<visit[x][y]-1<<endl;
                    return visit[x][y]-1;
                }
                vv.u=x;
                vv.v=y;
                q.push(vv);
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char s1,s2;
    int n1,n2,n3,n4;
    while(cin>>s1){
        scanf("%d",&n2);
        cin>>s2;
        scanf("%d",&n4);
        n1=int(s1)-96,n3=int(s2)-96;
        n1--,n2--,n3--,n4--;
        //cout<<n1<<n2<<" "<<n3<<n4<<endl;
        //printf("%c",s1);
        if(n1==n3 and n2==n4) printf("To get from %c%d to %c%d takes 0 knight moves.\n",s1,n2+1,s2,n4+1);
        else{
            int res=bfs(n1,n2,n3,n4);
            printf("To get from %c%d to %c%d takes %d knight moves.\n",s1,n2+1,s2,n4+1,res);
        }
        memset(visit,0,sizeof(visit));
    }
}

#include<bits/stdc++.h>
using namespace std;
#define MAX 25
#define LL long long
#define gc getchar unlocked
#define gc getchar
#define pc putchar_unlocked
#define pc putchar
char edge[MAX][MAX];
int dis[MAX][MAX];
vector<pair<int,int > >v1;
struct eg{
    int u,v;
};
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
void scan(int &n){
    n=0;
    bool negative=false;
    char c=gc();
    while(c<'0'||c>'9'){
        if(c=='-') negative=true;
        c=gc();
    }
    while(c>='0'&&c<='9'){
        n=n*10+c-48;
        c=gc();
    }
    if(negative) n=~(n-1);
}
void print(int n){
    if(n<0){
        pc('-');
        n=-n;
    }
    if(!n){
        pc('0');
        pc('\n');
        return;
    }
    char buff[12];
    int len=0;
    while(n) buff[len++]=n%10+48,n/=10;
    for(int i=len-1;i>=0;i--) pc(buff[i]);
    pc('\n');
}
int bfs(int x1,int y1,int xx,int yy){
    queue<eg>q;
    for(int i=0;i<xx;i++)
        for(int j=0;j<yy;j++)
            dis[i][j]=1e9;
    eg uu,vv;
    uu.u=x1,uu.v=y1;
    dis[x1][y1]=0;
    q.push(uu);
    while(!q.empty()){
        uu=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=fx[i]+uu.u;
            int y=fy[i]+uu.v;
            if(x>=0 and y>=0 and x<xx and y<yy and edge[x][y]!='m' and edge[x][y]!='#'){
                if(dis[x][y]>dis[uu.u][uu.v]+1){
                    dis[x][y]=dis[uu.u][uu.v]+1;
                    vv.u=x,vv.v=y;
                    q.push(vv);
                }
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scan(t);
    for(int i=1;i<=t;i++){
        int n,m,x,y;
        scan(n);
        scan(m);
        for(int j=0;j<n;j++){
            gets(edge[j]);
            for(int k=0;k<m;k++)
                if(edge[j][k]=='h'){
                    x=j,y=k;
                }
                else if(edge[j][k]=='a' or edge[j][k]=='b' or edge[j][k]=='c'){
                    v1.push_back({j,k});
                }
        }
        bfs(x,y,n,m);
        int mx=-1;
        printf("Case %d: ",i);
        for(int j=0;j<v1.size();j++){
            mx=max(mx,dis[v1[j].first][v1[j].second]);
        }
        print(mx);
        v1.clear();
    }
}

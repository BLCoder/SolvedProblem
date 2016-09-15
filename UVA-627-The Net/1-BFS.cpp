#include<bits/stdc++.h>
using namespace std;
#define SS stringstream
int toInt(string x){ SS s;s<<x;int  r;s>>r;return r;}
vector<int>edge[100000];
int pr[100000];
vector<int>v;
int dis[100000];
void bfs(int n,int m,int node){
    queue<int>q;
    for(int i=0;i<=node;i++) dis[i]=1e9;
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<edge[cur].size();i++){
            if(dis[edge[cur][i]]>dis[cur]+1){
                dis[edge[cur][i]]=dis[cur]+1;
                q.push(edge[cur][i]);
                pr[edge[cur][i]]=cur;
            }
        }
    }
}
void get_parent(int n){
    if(pr[n]!=n){
        v.push_back(n);
        get_parent(pr[n]);
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d\n",&n)!=EOF){
        char st[1000][1000];
        for(int i=0;i<=n;i++) st[i][0]='\0';
        for(int i=0;i<=n;i++) edge[i].clear();
        for(int i=0;i<n;i++) gets(st[i]);
        int c=0;
        string s1="",s2="";
        for(int i=0;i<n;i++){
            c=0;
            s1="";
            s2="";
                for(int j=0;j<strlen(st[i]);j++){
                    if(st[i][j]!='-'&&c==0){
                        s1+=st[i][j];
                    }
                    else if(st[i][j]=='-'){
                        c=1;
                        continue;
                    }
                    else{
                        int t1=toInt(s1);
                        if(st[i][j]!=','&&st[i][j]!='\0'){
                                s2+=st[i][j];
                                if(st[i][j+1]==','||st[i][j+1]=='\0'){
                                    int t2=toInt(s2);
                                    edge[t1].push_back(t2);
                                    s2="";
                                }
                        }
                    }
                }
        }
        for(int i=1;i<=n;i++){
            sort(edge[i].begin(),edge[i].end());
        }
        printf("-----\n");
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            memset(pr,0,sizeof(pr));
            memset(dis,0,sizeof(dis));
            bfs(a,b,n);
            get_parent(b);
            if(dis[b]==1e9) printf("connection impossible\n");
            else{
                printf("%d",v[v.size()-1]);
                for(int j=v.size()-2;j>=0;j--){
                    printf(" %d",v[j]);
                }
                printf("\n");
            }
            v.clear();
        }
    }
}

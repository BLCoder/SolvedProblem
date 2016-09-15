#include<bits/stdc++.h>
using namespace std;
#define SS stringstream
int toInt(string x){ SS s;s<<x;int  r;s>>r;return r;}
vector<int>edge[100000];
int dis[100000];
map<string,int>mp;
void bfs(int n,int node){
    queue<int>q;
    for(int i=0;i<=node;i++) dis[i]=1e9;
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<edge[cur].size();i++){
            if(dis[edge[cur][i]]>dis[cur]+100){
                dis[edge[cur][i]]=dis[cur]+100;
                q.push(edge[cur][i]);
            }
        }
    }
}
int main(){
   // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,t1,t2;
    string s1,s2;
    scanf("%d",&T);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(int i=1;i<=T;i++){
        int nd,eg,qry;
        scanf("%d%d%d",&nd,&eg,&qry);
        for(int j=1;j<=nd;j++){
            cin>>s1;
            mp[s1]=j;
        }
        for(int j=0;j<eg;j++){
            cin>>s1>>s2;
            //cout<<s1<<" "<<s2<<endl;
            t1=mp[s1];
            t2=mp[s2];
            //cout<<t1<<" "<<t2<<endl;
            edge[t1].push_back(t2);
            edge[t2].push_back(t1);
        }
        printf("DATA SET  %d\n\n",i);
        for(int j=0;j<qry;j++){
            int a;
            scanf("%d",&a);
            cin>>s1>>s2;
            t1=mp[s1];
            t2=mp[s2];
            bfs(t1,nd);
            if(dis[t2]==1e9) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n",dis[t2]*a);
        }
        printf("\n");
        mp.clear();
        for(int j=1;j<=nd;j++) edge[j].clear();
    }
    printf("END OF OUTPUT\n");
}

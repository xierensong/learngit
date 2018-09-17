#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 41003

struct E{
  int v,ne,d;
  E(){}
  E(int _v,int _n,int _d):v(_v),ne(_n),d(_d){}
}e[N*2];

int size, head[N], dis[N], dep[N*2],pos[N],t[N*2];
int dp[N*2][25],tot;
bool vis[N];
void init(){
  size=tot=0;
  memset(vis,false,sizeof(vis));
  memset(dis,0,sizeof(dis));
  memset(head,-1,sizeof(head));
}

void add(int u, int v, int d) {
  e[size]=E(v,head[u],d);
  head[u]=size++;
}

void dfs(int u, int de) {
  int i,v,d;
  if (!vis[u]) {
    vis[u]=true;
    pos[u]=tot;
  }
  dep[tot]=de,t[tot++]=u;
  for(i=head[u];i != -1;i=e[i].ne){
    v=e[i].v,d=e[i].d;
    if(vis[v]) continue;
    dis[v]=dis[u]+d;
    dfs(v,de+1);
    dep[tot]=de,t[tot++]=u;
  }
}

int RMQ(int u, int v) {
  int len=v-u+1,k=0;
  k=log(len*1.0)/log(2.0);
  if (dep[dp[u][k]]<dep[dp[v-(1<<k)+1][k]]) return t[dp[u][k]];
  else return t[dp[v-(1<<k)+1][k]];
  }

int lca(int u, int v) {
    if (pos[u]>pos[v]) swap(v,u);
    return RMQ(pos[u],pos[v]);
    }

int main()
{
    int T,n,i,j,m,u,v,d;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        for(i=1;i<n;i++){
            scanf("%d%d%d", &u,&v,&d);
            add(u,v,d),add(v,u,d);
            }
        dfs(1,0);
        for(j=0;(1<<j)<tot;j++)
        {
          for (i = 1;i+(1<<j)<tot;i++)
          {
            if (j==0) dp[i][j] = i;
            else
            {
              if (dep[dp[i][j-1]]<dep[dp[i+(1<<j-1)][j-1]])
                dp[i][j]=dp[i][j-1];
              else
                dp[i][j]=dp[i+(1<<j-1)][j-1];
            }
          }
        }
        while(m--) {
          scanf("%d%d",&u,&v);
          int fa=lca(u,v);
          printf("%d\n", dis[u]+dis[v]-2*dis[fa]);
        }
    }
}

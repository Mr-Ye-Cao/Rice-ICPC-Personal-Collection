#include <bits/stdc++.h>
using namespace std;

int T,N,M;
const int maxN=1000;
int V=INT_MIN;

bool bfs(int rgraph[maxN][maxN], int s, int t, int parent[]){
    bool vis[V];
    memset(vis, 0, sizeof(vis));
    
    queue<int> pa;
    pa.push(s);
    vis[s]=true;
    parent[s]=-1;
    
    while(!pa.empty()){
        int par=pa.front();
        pa.pop();
        for(int i=0;i<V;i++){
            if(vis[i]==false&&rgraph[par][i]>0)
            {
                pa.push(i);
                parent[i]=par;
                vis[i]=true;
            }
        }    
    }
    return vis[t]==true;
}

int foldenson(int graph[maxN][maxN], int s, int t){
    int mf=0;
    int parent[V];
    while(bfs(graph,s,t,parent)){
        // for(int i=0;i<V;i++){
        //     for(int j=0;j<V;j++){
        //         cout<<graph[i][j]<<" ";
        //     }
        //         cout<<endl;
        // }
        // cout<<endl;
        // cout<<mf<<endl;
        // for(int tr:parent){
        //     cout<<tr<<" ";
        // }
        // cout<<mf<<endl;
        int minc=INT_MAX;
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            minc=min(minc,graph[u][v]);
        }
        mf+=minc;
        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            graph[u][v]-=minc;
            graph[v][u]+=minc;
        }
    }
    // for(int i=0;i<V;i++){
    //         for(int j=0;j<V;j++){
    //             cout<<graph[i][j]<<" ";
    //         }
    //             cout<<endl;
    //     }
    return mf;
}

int main() {
    cin>>T;
    while(T--){
        cin>>N>>M;
        int am[maxN][maxN];
        for(int i=0;i<M;i++){
            int na,nb,ca;
            cin>>na>>nb>>ca;
            V=max(V,na);
            V=max(V,nb);
            am[na-1][nb-1]=ca;
            am[nb-1][na-1]=ca;
            // cout<<V<<endl;
        }
        // for(int i=0;i<V;i++){
        //     for(int j=0;j<V;j++){
        //         cout<<am[i][j]<<" ";
        //     }
        //         cout<<endl;
        // }
        // cout<<endl;
        cout<<foldenson(am,0,N-1)<<endl;
        V=INT_MIN;
    }
    return 0;
}

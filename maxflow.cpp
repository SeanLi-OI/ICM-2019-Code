#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=500;
const int MAXM=10000;
const int inf=2147483647;
int n;
struct Dinic{
    struct Edge{
        int from, to;
        long long cap, flow;
        Edge(int f = -1, int t = -1, long long c = 0)
        :from(f), to(t), cap(c), flow(0)
        {}
    }edges[MAXM];
    int next[MAXM], cnt;
    int pre[MAXN], dis[MAXN];
    int cur[MAXN];
    Dinic()
    {
        memset(pre, -1, sizeof(pre));
        cnt = 0;
    }
    void addedge(int f, int t, long long c)
    {
        edges[cnt] = Edge(f, t, c);
        next[cnt] = pre[f];
        pre[f] = cnt++;
        edges[cnt] = Edge(t, f, 0);
        next[cnt] = pre[t];
        pre[t] = cnt++;
    } 
    queue<int> Q;
    bool BFS(int s, int t)
    {
        while(!Q.empty()) Q.pop();
        memset(dis, -1, sizeof(dis));
        dis[s] = 0;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for(int i = pre[u]; i >= 0; i = next[i]) if(edges[i].cap > edges[i].flow)
            {
                int v = edges[i].to;
                if(dis[v] >= 0) continue;
                dis[v] = dis[u] + 1;
                if(v == t) return true;
                Q.push(v);
            }
        }
        return false;
    }
    long long DFS(int now, int t, long long maxflow)
    {
        if(now == t) return maxflow;
        int ret = 0;
        for(int i = cur[now] != -1 ? cur[now] : pre[now]; i >= 0; i = next[i]) if(edges[i].cap > edges[i].flow) 
        {
            int v = edges[i].to;
            if(dis[v] != dis[now] + 1) continue;
            int l = DFS(v, t, min(edges[i].cap - edges[i].flow, maxflow - ret));
            ret += l;
            edges[i].flow += l;
            edges[i^1].flow -= l;
            cur[now] = i;
            if(ret == maxflow) return ret;
        }
        cur[now] = -2;
        return ret;
    }
    long long solve(int s, int t)
    {
        int res = 0;
        while(BFS(s,t)) 
        {
            memset(cur, -1, n * sizeof(int));
            res += DFS(s, t, inf);
        }
        return res;
    }
};
int main(){

}
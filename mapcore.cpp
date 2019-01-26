#include "mapcore.h"
int Mapcore::sap(int start, int end, int N)
{
    memset(gap, 0, sizeof(gap));
    memset(dep, 0, sizeof(dep));
    memcpy(cur, head, sizeof(head));
    int u = start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while (dep[start] < N)
    {
        if (u == end)
        {
            int Min = C0;
            for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to])
                if (Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for (int i = pre[u]; i != -1; i = pre[edge[i ^ 1].to])
            {
                edge[i].flow += Min;
                edge[i ^ 1].flow -= Min;
            }
            u = start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = cur[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
            {
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if (flag)
        {
            u = v;
            continue;
        }
        int Min = N;
        for (int i = head[u]; i != -1; i = edge[i].next)
            if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        gap[dep[u]]--;
        if (!gap[dep[u]])
            return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if (u != start)
            u = edge[pre[u] ^ 1].to;
    }
    return ans;
}
void Mapcore::init()
{
    start_node = 0;
    end_node = 1;
    node_num = 1;
    tol = 0;
    memset(head, -1, sizeof(head));
}
int Mapcore::add_node(string _name)
{
    name[++node_num]=_name;
    return node_num;
}
void Mapcore::add_edge(int u, int v, int w, double length)
{
    edge[tol].to = v;
    edge[tol].cap = w;
    edge[tol].next = head[u];
    edge[tol].flow = 0;
    edge[tol].length = length;
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = w;
    edge[tol].next = head[v];
    edge[tol].flow = 0;
    edge[tol].length = length;
    head[v] = tol++;
}
void Mapcore::clean(){
    for(int i=0;i<tol;i++)
        edge[i].flow=0;
}
void Mapcore::maxflow()
{
    int time_cnt=0,now;
    while(true){
        clean();
        now=sap(start_node, end_node, node_num);
        printf("%d\n",now);
        if(now==0)break;
        for (int j = head[start_node]; j != -1; j = edge[j].next)
        {
            if (edge[j].flow > 0 && edge[j].to >= 0 && edge[j].to < node_num){
                edge[edge[j].to*2-2].cap-=edge[j].flow;
                edge[edge[j].to*2-1].cap-=edge[j].flow;
            }
        }
        time_cnt++;
    }
    printf("%d\n",time_cnt);
}
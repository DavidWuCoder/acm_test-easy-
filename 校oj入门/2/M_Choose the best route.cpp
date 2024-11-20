#include <bits/stdc++.h>
using ll = long long;
const int inf = 0x3f3f3f3f;

int n, m, s;

const int N = 1e3 + 10, M = 2e5 + 10;
int head[N], cnt, dis[N], vis[N];

struct node{
    int id, w;
    bool operator<(const node &A)const{
		return A.w < w;}
};

struct {
    int from, to, next;
    int w;
}edge[M];

void init()
{
    for (int i = 0; i < N; i++)
        head[i] = -1, vis[i] = 0, dis[i] = inf;
    for (int i = 0; i < M; i++)
    {
        edge[i].next = -1;
    }
    cnt = 0;
}

void addage(int u, int v, int w)
{
    edge[cnt].from = u;
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}


void dijkstra()
{
    std::priority_queue<node> q;
    q.push({0, 0});
    dis[0] = 0;
    while (!q.empty())
    {
        node u = q.top();
        q.pop();
        if (u.id == s)
        {
            break;
        }
        if (vis[u.id])
            continue;
        vis[u.id] = 1;
        for (int i = head[u.id]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if (vis[v])
            {
                continue;
            }
            if (dis[v] > u.w + w)
            {
                dis[v] = u.w + w;
                q.push({v, dis[v]});
            }
        }
    }
    if (dis[s] == inf)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << dis[s] << '\n';
    }
}
void solve(int& T)
{
    while(std::cin >> n >> m >> s)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            std::cin >> u >> v>>  w;
            addage(u, v, w);
        }
        int tw;
        std::cin >> tw;
        for (int i = 0; i < tw; i++)
        {
            int x;
            std::cin >> x;
            addage(0, x, 0);
        }
        dijkstra();
    }
}

 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}
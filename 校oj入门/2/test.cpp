// #include <stdio.h>
// #include <queue>
// #include <stdlib.h>
// #include <string.h>
// 
// int mar[59][59][59];
// int vis[59][59][59];
// int a, b, c, t;
// 
// struct node
// {
//     int x, y, z, _val;
//     node(int a, int b, int c, int z) : x(a), y(b), z(c), _val(z) {}
// };
// 
// const int dx[] = {0, 1, 0, -1, 0, 0};
// const int dy[] = {0, 0, 1, 0, -1, 0};
// const int dz[] = {1, 0, 0, 0, 0, -1};
// 
// void bfs()
// {
//     memset(vis, 0, sizeof(vis));
//     std::queue<node> q;
//     q.emplace(0, 0, 0, 0);
//     vis[0][0][0] = 1;
// 
//     // 如果起点和终点相同，直接输出 0
//     if (a == 1 && b == 1 && c == 1)
//     {
//         printf("0\n");
//         return;
//     }
// 
//     while (!q.empty())
//     {
//         auto [x, y, z, val] = q.front();
//         q.pop();
//         if (x == a - 1 && y == b - 1 && z == c - 1)
//         {
//             if (val <= t)
//             {
//                 printf("%d\n", val);
//             }
//             else
//             {
//                 printf("-1\n");
//             }
//             return;
//         }
//         for (int k = 0; k < 6; k++)
//         {
//             int nx = x + dx[k],
//                 ny = y + dy[k],
//                 nz = z + dz[k];
// 
//             if (nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c)
//             {
//                 continue;
//             }
//             if (vis[nx][ny][nz])
//             {
//                 continue;
//             }
//             if (mar[nx][ny][nz] == 1)
//             {
//                 continue;
//             }
//             vis[nx][ny][nz] = 1;
//             q.emplace(nx, ny, nz, val + 1);
//         }
//     }
//     printf("-1\n"); // 如果队列为空且未找到目标点，输出 -1
// }
// 
// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while (t--)
//     {
//         scanf("%d %d %d %d", &a, &b, &c, &t);
//         for (int i = 0; i < a; i++)
//         {
//             for (int j = 0; j < b; j++)
//             {
//                 for (int k = 0; k < c; k++)
//                 {
//                     scanf("%d", &mar[i][j][k]);
//                 }
//             }
//         }
//         bfs();
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int inf = 0x3f3f3f3f;
// const int N = 1e3 + 10;
// const int M = 2e4 + 10;
// int n, m, s, k;
// int dis[N];
// int vis[N];
// int cnt, head[M];

// struct node{
// 	int id, w;
// 	bool operator<(const node &A)const{
// 		return A.w < w;}
// };
// struct edge{	int to, w, next;} e[M];
// void add(int u, int v, int w) {	e[cnt].to = v, e[cnt].w = w, e[cnt].next = head[u], head[u] = cnt++;}
// void addedge(int u, int v, int w) {	add(u, v, w);	add(v, u, w);}
// void init() {
// 	cnt = 0;
// 	for(int i = 0; i < N; i++)	vis[i] = 0, dis[i] = inf;
// 	for(int i = 0; i < M; i++)	head[i] = -1;
// }

// void dijkstra() {
// 	priority_queue<node> Q;
// 	Q.push({0, 0});	dis[0] = 0;
// 	while(!Q.empty()) {
// 		node u = Q.top(); Q.pop();
// 		if(u.id == s)	break;
// 		if(vis[u.id])	continue;
// 		vis[u.id] = 1;
// 		for(int i = head[u.id]; ~i; i = e[i].next) {
// 			int v = e[i].to, w = e[i].w;
// 			if(vis[v])	continue;
// 			if(dis[v] > u.w + w) {
// 				dis[v] = u.w + w;
// 				Q.push({v, dis[v]});
// 			}
// 		}
// 	}
// 	if(dis[s] == inf)	printf("-1\n");
// 	else printf("%d\n", dis[s]);
// }

// int main() {
// 	while(~scanf("%d%d%d", &n, &m, &s)) {
// 		init();
// 		while(m--) {
// 			int u, v, w;
// 			scanf("%d%d%d", &u, &v, &w);
// 			add(u, v, w);
// 		}
// 		scanf("%d", &k);
// 		while(k--) {
// 			int x;
// 			scanf("%d", &x);
// 			add(0, x, 0);
// 		}
// 		dijkstra();
// 	}
// 	return 0;
// }

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 11000;
struct Node//定义一个结构体关于 
{
    int to,step;
};
int  v[MAX],f[MAX];//v用来标记楼层有没有走过 f存k[i] 
int main()
{
	Node  now,next;
    int cas,m,n,i;
    while(scanf("%d",&cas)&&cas)//cas表示几楼的数据 
    {
        scanf("%d%d",&m,&n);//m表示起点，n表示终点 
        memset(v,0,sizeof(v));//数组初始化 
        memset(f,0,sizeof(f));
        for(i=1; i<=cas; i++)
            scanf("%d",&f[i]);//输入每层的数据 
        queue<Node>q;//定义队列
        while(!q.empty())//清空队列 
        {
            q.pop();
        }
        int  t1,t2,flag=0;
        now.step=0;//起始点的步数 
        now.to=m;
        q.push(now);//把结点的情况输入 
        v[now.to]=1;//标记这个点已经走过了 
        while(!q.empty())//
        {
            now = q.front();//取出首元素
            q.pop();
            //下面是三种分类讨论：到达终点，向上走，向下走 
            if(now.to == n)//如果到达终点
            {
                printf("%d\n",now.step);
                flag=1;
                break;
            }
            t1=now.to+f[now.to];//向上走 当前所在楼层数+该楼层可以移的层数 
            if(t1<=cas&&!v[t1])//条件的控制 没有超出总层数以及到的楼层没有被标记过 
            {
 
                v[t1]=1;
                next.to=t1;
                next.step=now.step+1;
                q.push(next);
            }
            t1=now.to-f[now.to];//向下走
            if(t1>=1&&!v[t1])//下走最低为1 
            {
                v[t1]=1;
                next.to=t1;
                next.step=now.step+1;
                q.push(next);
            }
        }
        if(!flag)//如果走不到 flag==0
            printf("-1\n");
    }
    return 0;
}
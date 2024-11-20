#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <string.h>

int mar[59][59][59];
int vis[59][59][59];
int a, b, c, t;

struct node
{
    int x, y, z, _val;
    node(int a, int b, int c, int z) : x(a), y(b), z(c), _val(z) {}
};

const int dx[] = {0, 1, 0, -1, 0, 0};
const int dy[] = {0, 0, 1, 0, -1, 0};
const int dz[] = {1, 0, 0, 0, 0, -1};

void bfs()
{
    memset(vis, 0, sizeof(vis));
    std::queue<node> q;
    q.emplace(1, 1, 1, 0);
    vis[1][1][1] = 1;

    // 如果起点和终点相同，直接输出 0
    if (a == 1 && b == 1 && c == 1)
    {
        printf("0\n");
        return;
    }

    while (!q.empty())
    {
        auto [x, y, z, val] = q.front();
        q.pop();
        if (x == a  && y == b  && z == c )
        {
            if (val <= t)
            {
                printf("%d\n", val);
            }
            else
            {
                printf("-1\n");
            }
            return;
        }
        for (int k = 0; k < 6; k++)
        {
            int nx = x + dx[k],
                ny = y + dy[k],
                nz = z + dz[k];

            if (nx < 1 || nx > a || ny <  1|| ny > b || nz < 1 || nz > c)
            {
                continue;
            }
            if (vis[nx][ny][nz])
            {
                continue;
            }
            if (mar[nx][ny][nz] == 1)
            {
                continue;
            }
            vis[nx][ny][nz] = 1;
            q.emplace(nx, ny, nz, val + 1);
        }
    }
    printf("-1\n"); // 如果队列为空且未找到目标点，输出 -1
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &t);
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                for (int k = 1; k <= c; k++)
                {
                    scanf("%d", &mar[i][j][k]);
                }
            }
        }
        bfs();
    }
    return 0;
}


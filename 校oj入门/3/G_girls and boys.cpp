#include <bits/stdc++.h>
using ll = long long;

const int N = 510;
const int M = 510 * 510;

int n;

// 链式前向星
int e[M], h[N], idx, w[M], ne[M];
void add(int a, int b, int c = 0)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int match[N], st[N];
int dfs(int u)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (st[v])
            continue;
        st[v] = 1;
        if (match[v] == -1 || dfs(match[v]))
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve(int &T)
{
    while (scanf("%d", &n) != EOF)
    {
        memset(h, -1, sizeof h);
        memset(match, -1, sizeof(match));
        idx = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d: (%d)", &a, &b);
            while (b--)
            {
                int c;
                scanf("%d", &c);
                add(a, c);
            }
        }

        for (int i = 0; i < n; i++)
        {
            memset(st, 0, sizeof(st));
            if (dfs(i))
                sum++;
        }
        std::cout << n - sum / 2 << '\n';
    }
}

int main()
{
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}
// #include<iostream>
// #include<string.h>
// using namespace std;
// #define n 1500
// int e[n][n], match[n], book[n];
// int k;
// bool find(int x)
// {
// 	for (int i = 0; i < k; i++)//人的编号
// 	{
// 		if (!book[i]&&e[x][i])
// 		{
// 			book[i] = 1;
// 			if (!match[i] || find(match[i]))
// 			{
// 				match[i] = x;
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }
// int main(void)
// {
// 	int m, n, a;
// 	while (~scanf("%d", &k))
// 	{
// 		memset(e, 0, sizeof(e));
// 		memset(match, 0, sizeof(match));
// 		for (int i = 1; i <= k; i++)
// 		{
// 			scanf("%d: (%d)", &m, &n);//某人、有多少个关系好的
// 			while (n--)
// 			{
// 				scanf("%d", &a);//某人玩的好的人编号
// 				e[m][a] = 1;//不知道谁男谁女
// 				e[a][m] = 1;
// 			}
// 		}
// 		int ans = 0;
// 		for (int i = 0; i < k; i++)
// 		{
// 			memset(book, 0, sizeof(book));
// 			if (find(i))
// 				ans++;
// 		}
// 		printf("%d\n", k - ans / 2);//找几对没有好友的，即最大独立集（顶点-最大匹配/2）

// 	}

// 	return 0;
// }
// #include<iostream>
// #include<string.h>
// using namespace std;
// #define N 1500
// int e[N][N], match[N], book[N];
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
int main() {
#ifndef ONLINE_JUDGE
    freopen("POJ1466.in", "r", stdin);
#endif

    int n;
    while (~scanf("%d", &n)) {
        memset(h, -1, sizeof h);
        idx = 0;

        for (int i = 0; i < n; i++) {
            int m, a, b;
            scanf("%d: (%d)", &a, &m);
            while (m--) {
                scanf("%d", &b);
                add(a, b);
            }
        }

        int res = 0;
        memset(match, -1, sizeof match);
        for (int i = 0; i < n; i++) {
            memset(st, 0, sizeof st);
            if (dfs(i)) res++;
        }
        printf("%d\n", n - res / 2);
    }
    return 0;
}
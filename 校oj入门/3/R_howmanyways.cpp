#include <bits/stdc++.h>
using ll = long long;

int row, col;
int ans[110][110], map[110][110];

bool judge(int x, int y)
{
    if (x < 1 || x > row || y < 1 || y > col)
    {
        return false;
    }
    return true;
}

int dfs(int x, int y)
{
    if (ans[x][y] >= 0)
    {
        return ans[x][y];
    }
    ans[x][y] = 0;
    for (int i = 0; i <= map[x][y]; i++)
    {
        for (int j = 0; j <= map[x][y] - i; j++)
        {
            int nx = x + i;
            int ny = y + j;
            if (judge(nx, ny))
            {
                int answer = dfs(nx, ny);
                ans[x][y] = (answer + ans[x][y]) % 10000;
            }
        }
    }
    return ans[x][y];
}

void solve(int &T)
{
    std::cin >> row >> col;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for (int i = 0; i < 110; i++)
    {
        for (int j = 0; j < 110; j++)
        {
            ans[i][j] = -1;
        }
    }
    ans[row][col] = 1;
    std::cout << dfs(1, 1) << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}
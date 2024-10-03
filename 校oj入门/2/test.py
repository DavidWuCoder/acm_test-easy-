
def nthUglyNumber( n): 
    dp = [0] * n 
    dp[0] = 1 
    l2, l3, l5, l7 = 0, 0, 0, 0 
    for i in range(1, n): 
        # 生成第i+1小的丑数 
        dp[i] = min(2 * dp[l2], 3 * dp[l3], 5 * dp[l5], 7 * dp[l7]) 
        if dp[i] == 2 * dp[l2]: 
            l2 += 1 
        if dp[i] == 3 * dp[l3]: 
            l3 += 1 
        if dp[i] == 5 * dp[l5]: 
            l5 += 1 
        if dp[i] == 7 * dp[7]:
            l7 += 1
    return dp

print(nthUglyNumber(10))
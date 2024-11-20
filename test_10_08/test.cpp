#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        auto check = [&](int mid)
        {
            unordered_map<int, int> cnt;
            int l = 0;
            while (l < mid)
            {
                cnt[l]++;
            }
            while(l < n)
            {
                cnt[l]++;
                if (cnt.size() == mid)
                {
                    return true;
                }
                else {
                    cnt[l - mid + 1]--;
                    if (cnt[l - mid + 1] == 0)
                    {
                        cnt.erase(l - mid + 1);
                    }
                    l++;
                }
            }
            return false;
        };
        int l = 0, r = n;
        int ans = 0;  
        while(l <= r)
        {
            int mid = (l + r) / 2;

            if (check(mid))
            {
                l = mid + 1;
                ans  = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s1;
    vector<int> v1 = {2, 3, 4, 5};
    s1.maxLength(v1);
    return 0;
}
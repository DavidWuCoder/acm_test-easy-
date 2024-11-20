#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 计算 mex 值
int mex(const vector<int>& s) {
    set<int> st(s.begin(), s.end());
    int mex = 0;
    while (st.count(mex)) {
        mex++;
    }
    return mex;
}

// 计算 SG 值
vector<int> compute_sg(int max_val, const vector<int>& S) {
    vector<int> sg(max_val + 1, 0);
    for (int i = 1; i <= max_val; ++i) {
        vector<int> reachable;
        for (int j : S) {
            if (i >= j) {
                reachable.push_back(sg[i - j]);
            }
        }
        sg[i] = mex(reachable);
    }
    return sg;
}

void solve() {
    int k;
    while (cin >> k && k != 0) {
        vector<int> S(k);
        for (int i = 0; i < k; ++i) {
            cin >> S[i];
        }

        // 计算 SG 值
        int max_val = 10000;
        vector<int> sg = compute_sg(max_val, S);

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int l;
            cin >> l;
            vector<int> heaps(l);
            for (int j = 0; j < l; ++j) {
                cin >> heaps[j];
            }

            int xor_sum = 0;
            for (int h : heaps) {
                xor_sum ^= sg[h];
            }

            if (xor_sum == 0) {
                cout << "L";
            } else {
                cout << "W";
            }
        }
        cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    solve();
    return 0;
}
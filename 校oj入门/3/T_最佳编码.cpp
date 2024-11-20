#include<iostream>
#include<queue>
#define MAX 40
using namespace std;
 
int ch[40];
 
int bfs() {
	int a, b;
	int ans = 0;
	priority_queue<int,vector<int>,greater<int>>qu;
 
	for (int i = 0; i <= 37; i++)
		if (ch[i])qu.push(ch[i]);
 
	if (qu.size() == 1)
		ans = qu.top();
 
	while (qu.size() > 1) {
		a = qu.top();
		qu.pop();
		b = qu.top();
		qu.pop();
		ans += (a + b);
		qu.push(a + b);
	}
	return ans;
}
 
int main()
{
	string str;
	while (cin >> str) {
		if (str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str.size() == 3)
			break;
		for (int i = 0; i < MAX; i++)
			ch[i] = 0;
 
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '_')
				ch[26]++;
			else {
				if (str[i] >= 'A' && str[i] <= 'Z')
					ch[str[i] - 'A']++;
				else
					ch[str[i] - '0' + 28]++;
			}
		}
		int ans1 = str.size() * 8, ans2 = bfs();
		printf("%d %d %.1f\n", ans1, ans2, 1.0 * ans1 / ans2);
	}
	return 0;
}
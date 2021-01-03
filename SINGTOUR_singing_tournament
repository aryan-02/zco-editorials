#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T{};
	cin >> T;
	while (T--)
	{
		vector<pair<int, int>> upper{};
		vector<pair<int, int>> lower{};
		int N{};
		cin >> N;
		for(int i{}; i < N; i++)
		{
			int u{}, l{};
			cin >> l >> u;
			upper.push_back({u, i});
			lower.push_back({l, i});
		}
		sort(upper.begin(), upper.end());
		sort(lower.begin(), lower.end());
		vector<int> scores(N, 0);
		for(int i{}; i < N; i++)
		{
			scores[upper[i].second] += i;
			scores[lower[i].second] += (N - i - 1);
		}
		for(int i : scores)
		{
			cout << i << ' ';
		}
		cout << '\n';
	}
}

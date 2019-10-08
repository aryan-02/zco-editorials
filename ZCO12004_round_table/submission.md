#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> data;
	for(int i{}; i < N; i++)
	{
		int temp{};
		cin >> temp;
		data.push_back(temp);
	}
	int solve1[N];
	solve1[0] = data.at(0);
	solve1[1] = data.at(0) + data.at(1);
	solve1[2] = data.at(0) + data.at(2);
	for(int i{3}; i < N; i++)
	{
		solve1[i] = data.at(i) + min(solve1[i - 1], solve1[i - 2]);
	}
	int res_1 = min(solve1[N - 1], solve1[N - 2]);
	int solve2[N];
	solve2[0] = data.at(0);
	solve2[1] = data.at(1);
	for(int i{2}; i < N; i++)
	{
		solve2[i] = data.at(i) + min(solve2[i - 1], solve2[i - 2]);
	}
	int res_2 = solve2[N - 1];
	cout << min(res_1, res_2) << '\n';
}

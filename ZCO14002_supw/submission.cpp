// Author: Aryan Mediratta
// Problem: SUPW
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> data;
vector<vector<int>> memo(200010, vector<int>(4));

int solve(int idx, int days)
{
	// Returns the minimum number of minutes required to work for day _idx_ till the end,
	// given that he hasn't worked for _days_ days
	if(memo.at(idx).at(days) != -1)
	{
		return memo.at(idx).at(days);
	}
	int answer;
	if(idx == data.size())
	{
		answer = 0; // Base Case
	} else {
		if (days < 2)
		{
			// solve(idx + 1, days + 1): not working today
			// data[idx] + solve(idx + 1, 0): working today
			answer = min(solve(idx + 1, days + 1), data.at(idx) + solve(idx + 1, 0));
		} else {
			// If you haven't worked for the past two days, you have to work today
			answer = data.at(idx) + solve(idx + 1, 0);
		}
	}
	memo[idx][days] = answer; // Store answer in memo
	return answer; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 200010; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			memo[i][j] = -1;
		}
	}
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		data.pb(temp);
	}
	cout << solve(0,0) << endl; // Solve from index 0 with 0 days worked before.
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const vector<int>& s)
{
	vector<int> t {s};
	reverse(t.begin(), t.end());
	return s == t;
}

int minC(vector<int>& data, int i, int j, vector<vector<int>>& memo)
{
	if(memo[i][j] != 0)
	{
		return memo.at(i).at(j);
	}
	vector<int> data_curr = vector<int>(data.begin() + i, data.begin() + j + 1);
	if(i == j or isPalindrome(data_curr))
	{
		memo[i][j] = 1;
		return 1;
	}
	else {
		int ret = numeric_limits<int>::max();
		for(int sep = i; sep < j; sep++)
		{
			ret = min(ret, minC(data, i, sep, memo) + minC(data, sep + 1, j, memo));
		}
		memo[i][j] = ret;
		return ret;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> memo(N, vector<int>(N, 0));
	vector<int> data;
	for(int i{}; i < N; i++)
	{
		int temp;
		cin >> temp;
		data.push_back(temp);
	}
	cout << minC(data, 0, N - 1, memo) << '\n';

}

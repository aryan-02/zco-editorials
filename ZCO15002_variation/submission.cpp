#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N{}, K{};
	cin >> N >> K;
	vector<int> nums;
	for(int i{}; i < N; i++)
	{
		int temp{};
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());
	int var{};
	for(int i{}; i < N - 1; i++)
	{
		int pos{};
		for(int j{ i + 1 }; j < N; j++)
		{
			if(nums[j] - nums[i] >= K)
			{
				var += N - j;
				break;
			}
		}
	}
	cout << var  << '\n';
  

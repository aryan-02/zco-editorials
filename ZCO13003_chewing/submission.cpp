#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll N{}, K{};
	vector<ll> hardness;
	cin >> N >> K;
	for(ll i{}; i < N; i++)
	{
		ll temp{};
		cin >> temp;
		hardness.push_back(temp);
	}
	sort(hardness.begin(), hardness.end());
	ll num{};
	ll i {0};
	ll j {N - 1};
	while(i < j)
	{
		if(hardness.at(i) + hardness.at(j) >= K)
		{
			j--;
		}
		else
		{
			num += (j - i);
			i++;
		}
	}
	cout << num << '\n';
}

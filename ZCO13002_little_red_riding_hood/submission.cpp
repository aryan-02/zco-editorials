#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M;
vector<vector<bool>> safe{};
vector<vector<ll>> berries{};
vector<vector<ll>> memo{};
bool reached{};

// Manhattan distance
int mdist(int x1, int y1, int x2, int y2)
{
	return abs(x2 - x1) + abs(y2 - y1);
}

void applyCharm(int r, int c, int strength)
{
	for(int i = r - strength; i <= r + strength; i++)
	{
		for(int j = c - strength; j <= c + strength; j++)
		{
			if(mdist(r, c, i, j) <= strength and i >= 0 and i < N and j >= 0 and j < N)
			{
				safe[i][j] = true;
			}
		}
	}
}

ll maxBerries(int r, int c)
{
	if(memo[r][c] != numeric_limits<ll>::min())
	{
		return memo[r][c];
	}
	if (r == 0 and c == 0)
	{
		reached = true;
		memo[r][c] = berries[0][0];
		return berries[0][0];
	}
	ll ret = numeric_limits<int>::min();
	if (r != 0 and safe[r - 1][c])
	{
		ret = max(ret, berries[r][c] + maxBerries(r - 1, c));
	}
	if (c != 0 and safe[r][c - 1])
	{
		ret = max(ret, berries[r][c] + maxBerries(r, c - 1));
	}
	memo[r][c] = ret;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	reached = false;
	cin >> N >> M;
	for (int row{}; row < N; row++)
	{
		vector<ll> r;
		for (int cell{}; cell < N; cell++)
		{
			int temp{};
			cin >> temp;
			r.push_back(temp);
		}
		berries.push_back(r);
	}

	for (int i{}; i < N; i++)
	{
		vector<ll> m_row{};
		vector<bool> row{};
		for (int j{}; j < N; j++)
		{
			m_row.push_back(numeric_limits<ll>::min());
			row.push_back(0);
		}
		memo.push_back(m_row);
		safe.push_back(row);
	}
	for (int i{}; i < M; i++)
	{
		int r{}; int c{}; int strength{};
		cin >> r >> c >> strength;
		r--;
		c--;
		applyCharm(r, c, strength);
	}
	
	ll ans = maxBerries(N - 1, N - 1);
	if (reached)
	{
		cout << "YES" << '\n';
		cout << ans << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
} 

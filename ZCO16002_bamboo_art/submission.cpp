#include <bits/stdc++.h>
using namespace std;
vector<int> data;
int N;
int solve(int i, int j)
{
    static vector<vector<int>> memo(N, vector<int>(N, -1));
    if(memo[i][j] != -1)
    {
        return memo[i][j];
    }
    if(i == 0)
    {
        memo[i][j] = 2;
        return 2;
    }
    else {
        auto f = find(data.begin(), data.begin() + i, data[i] - (data[j] - data[i]));
        if(f != data.begin() + i) // found
        {
            int id = static_cast<int>(f - data.begin());
            memo[i][j] = 1 + solve(id, i);
            return memo[i][j];
        }
        else {
            memo[i][j] = 2;
            return 2;
        }
    }
}
int main()
{
    cin >> N;
    for(int i{}; i < N; i++)
    {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }
    sort(data.begin(), data.end());
    int m{};
    for(int i{}; i < N-1; i++)
    {
        for(int j{i+1}; j < N; j++)
        {
            m = max(m, solve(i, j));
        }
    }
    cout << m << '\n';
    return 0;
}

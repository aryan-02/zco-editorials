#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int n;
int main()
{
	cin >> n;
	long long int arr[n];
	for (long int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long m = -1;
	for (long long int i = 0; i < n; ++i)
	{
		m = max(arr[i] * (n-i), m);
	}
	cout << m;
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N{}, H{};
	cin >> N >> H;
	vector<int> boxes{};
	for(int i{}; i < N; i++)
	{
		int temp{};
		cin >> temp;
		boxes.push_back(temp);
	}
	int pos{};
	bool picked{};
	while (true)
	{
		int ins{}; // Instruction code
		cin >> ins;
		if(ins == 0)
		{
			break;
		}
		else {
			switch(ins)
			{
				case 1: // Move left
					if(pos != 0)
					{
						pos--;
					}
				break;
				case 2: // Move right
					if(pos != N - 1)
					{
						pos ++;
					}
				break;
				case 3: // Pick up box
					if(!picked and boxes.at(pos) != 0)
					{
						boxes.at(pos)--;
						picked = true;
					}
				break;
				case 4: // Drop box
					if(picked and boxes.at(pos) < H)
					{
						boxes.at(pos)++;
						picked = false;
					}
				break;
			}
		}
	}
	for(const int& i : boxes)
	{
		cout << i << ' ';
	}

}

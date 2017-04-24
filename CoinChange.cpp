//Coin Change
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int i;
vector <int> ans[5];
int coin[5] = { 1,5,10,25,50 };

inline void numChange(int amount)
{
	for (int  i = 1; i < 5; i++)
	{
		for (int x = 0; x < amount; x++)
		{
			if (x==0)
			{
				ans[i][x] = 1;
			}
			else if (x-coin[i] >= 0)
			{
				ans[i][x]= (ans[i - 1][x] + ans[i][x - coin[i]]);
			}
			else
			{
				ans[i][x] = ans[i - 1][x];
			}
		}
	}

}

int main() {


	int amount;
	ans[0].resize(7500, 1);
	ans[1].resize(7500);
	ans[2].resize(7500);
	ans[3].resize(7500);
	ans[4].resize(7500);

	numChange(7500);
	while (cin >> amount) {
		cout << ans[4][amount] << endl;
	}

	return 0;
}
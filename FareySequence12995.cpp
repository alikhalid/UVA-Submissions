//12995
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define endl '\n'
long long num[100000];

struct Pair
{
	double x, y;
}P;

vector <Pair> a;

int seq(int n)
{
	register int ans = 0;
	int temp;
	P.x = 0; P.y = 1;
	a.push_back(P);
	P.x = 1; P.y = n;
	a.push_back(P);
	P.y = -1;
	while (P.y != 1.0)
	{
		temp = a.size();
		P.x = floor((a[temp - 2].y + n) / a[temp - 1].y) * a[temp - 1].x - a[temp - 2].x;
		P.y = floor((a[temp - 2].y + n) / a[temp - 1].y) * a[temp - 1].y - a[temp - 2].y;
		a.push_back(P);
	}
	for (int i = 0; i < a.size(); i++)
	{
		for (int z = i + 2; z < a.size(); z++)
		{
			if ((a[i].x * a[z].y - a[z].x * a[i].y) == 1) ++ans;
		}
	}
	return ans;
}

int main()throw()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	register int n;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	for (size_t i = 0; i < 10000; i++)
	{
		num[i] = seq(i);
	}

	cin >> n;
	while (n)
	{
		cout << num[n-1] << endl;
		cin >> n;
	}

	return 0;
}
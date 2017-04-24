//10589
//#pragma warning(disable: 4996)
#include <iostream>
#define endl '\n'

using namespace std;

int main()throw()
{
	//freopen("in.txt", "r", stdin);
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	register int m, a;
	register double x, y, n, t;
	while (!cin.eof())
	{
		m = 0;
		cin >> n >> a;
		t = n;
		cin >> x >> y;
		while (t--)
		{
			auto const& func = [x, y, a](int h, int k)->bool {
				return ((x - h)*(x - h) + (y - k)*(y - k) <= a*a);
			};
			if (func(0, 0) && func(a, 0) && func(0, a) && func(a, a))
				++m;
			cin >> x >> y;
		}
		printf("%.5f\n", m*a*a / n);
	}

	return 0;
}
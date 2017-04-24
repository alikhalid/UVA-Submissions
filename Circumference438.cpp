//438
//Circumference
#pragma warning (disable:4996)
#include <iostream>
#include <math.h>
#include <utility>
#include <iomanip>

#define endl '\n'
using namespace std;
const double PI = 3.141592653589793;

pair <double, double> P, Q, R, midPQ, midQR, c;

inline
void center()throw()
{
	double gradPQ, gradQR, gradL1, gradL2;

	midPQ.first = (P.first + Q.first) / 2;
	midPQ.second = (P.second + Q.second) / 2;
	midQR.first = (Q.first + R.first) / 2;
	midQR.second = (Q.second + R.second) / 2;

	gradPQ = (Q.second - P.second) / (Q.first - P.first);
	gradQR = (R.second - Q.second) / (R.first - Q.first);

	gradL1 = -1 / gradPQ;
	gradL2 = -1 / gradQR;
	if (gradL1 == INFINITY || gradL1 == -INFINITY)
	{
		c.first = midPQ.first;
		c.second = gradL2*(c.first - midQR.first) + midQR.second;
		return;
	}
	else if (gradL2 == -INFINITY || gradL2 == INFINITY)
	{
		c.first = midQR.first;
		c.second = gradL1*(c.first - midPQ.first) + midPQ.second;
		return;
	}
	c.first = (midPQ.second - midQR.second - gradL1*midPQ.first + gradL2*midQR.first) / (gradL2 - gradL1);
	c.second = gradL1*(c.first - midPQ.first) + midPQ.second;
}

inline
double dist()
{
	double a = P.second - c.second,
		b = P.first - c.first;

	double ans = a*a + b*b;
	return sqrt(ans);

}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	//freopen("in.txt", "r", stdin);
	double r;

	while (cin >> P.first >> P.second)
	{
		cin >> Q.first >> Q.second;
		cin >> R.first >> R.second;
		center();
		r = dist();
		cout << fixed << setprecision(2) << 2 * PI*r << endl;
	}


	return 0;
}
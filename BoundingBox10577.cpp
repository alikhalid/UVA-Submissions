//10577
//BoundingBox
#pragma warning (disable:4996)
#include <iostream>
#include <utility>
#include <math.h>
#include <algorithm>
#include <iomanip>
#define endl '\n'
using namespace std;
const double PI = 3.141592653589793;

pair <double, double> P, Q, R, midPQ, midQR, c;
double maxX, maxY, minX, minY;

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
	c.first = (midPQ.second - midQR.second - gradL1*midPQ.first + gradL2*midQR.first) / (gradL2 - gradL1);
	c.second = gradL1*(c.first - midPQ.first) + midPQ.second;
}

inline
void findMax(int & sides)throw()
{
	double  angle, x = P.first, y = P.second, co, si, dx, dy;
	maxX = minX = P.first;
	maxY = minY = P.second;
	angle = 2 * PI / sides;
	si = sin(angle);
	co = cos(angle);
	for (int i = 0; i < sides; i++)
	{
		dx = x - c.first;
		dy = y - c.second;

		x = c.first + dx * co - dy * si;
		y = c.second + dx * si + dy * co;
		maxX = max(maxX, x); maxY = max(maxY, y);
		minX = min(minX, x); minY = min(minY, y);
	}

}

int main()throw()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	freopen("in.txt", "r", stdin);
	int sides, i=1;

	cin >> sides;
	while (sides)
	{
		cin >> R.first >> R.second;
		cin >> Q.first >> Q.second;
		cin >> P.first >> P.second;
		center();
		findMax(sides);
		cout << "Polygon " << i << ": ";
		cout << fixed << setprecision(3) << (maxX - minX) * (maxY - minY) << endl;
		cin >> sides;
		++i;
	}

	return 0;
}
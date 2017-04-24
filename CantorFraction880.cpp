//Cantor Fractions 
//UVA problem num 800
#include<iostream>
#include <math.h>

void inline calc(register long & num) throw()
{
	register long d, temp, n;
	temp = 2 * sqrt(1 + ((num - 1) << 1));
	temp = (temp - 1) >> 1;
	n = (((temp + 2) *(temp + 1)) >> 1) + 1 - num;
	d = num - (((temp* temp) + temp) >> 1);
	std::cout << n << '/' << d << '\n';
}

int main() throw()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	register long num;
	while (std::cin >> num)
	{
		calc(num);
	}
	return 0;
}
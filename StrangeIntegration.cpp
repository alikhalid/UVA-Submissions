//10906
#include <iostream>
#include <string>
#include <unordered_map>
#define endl '\n'

using namespace std;

unordered_map <string, char> ans;
unordered_map <string, string> expres;

void evaluate(string & exp, string &a, char & op, string & b) throw()
{
	char aOp, bOp;
	string temp;
	if (!ans.count(a))
		aOp = '#';
	else
		aOp = ans[a];
	if (!ans.count(b))
		bOp = '#';
	else
		bOp = ans[b];
	if (aOp == '#' && bOp == '#')
	{
		expres.emplace(exp, string(a + op + b));
		return;
	}
	if ((aOp == '-' || aOp == '+') && op == '*')
	{
		temp = "(" + expres[a] + ")";
	}
	else if (aOp == '#')
	{
		temp = a;
	}
	else
	{
		temp = expres[a];
	}
	temp += op;
	if ((bOp == '+' || bOp == '-') || (op == '*' && bOp == '*'))
	{
		temp += "(" + expres[b] + ")";
	}
	else if (bOp == '#')
	{
		temp += b;
	}
	else
	{
		temp += expres[b];
	}

	expres.emplace(exp, temp);
}

int main()throw()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, n, i=0;
	string exp, e, a, b, temp;
	char op;

	cin >> t;
	while (t--)
	{
		cin >> n;
		while (n--)
		{
			cin >> exp >> e >> a >> op >> b;
			ans.emplace(exp, op);
			evaluate(exp,a,op,b);
		}
		cout << "Expression #" << ++i << ": " << expres[exp] << endl;
		ans.clear();
		expres.clear();
	}
	return 0;
}
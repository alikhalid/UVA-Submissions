//10044
#pragma warning(disable:4996)
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>
#define endl '\n'
using namespace std;

struct Node
{
	int weight;
	string n;
	set <string> s;
	bool visited;
};

vector <string> v;
unordered_map <string, Node> ans;

inline void bfs() throw();

int main()throw()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	int t, p, n, i = 1;
	string in, temp = " ";
	Node node;
	vector <string> z;
	cin >> t;

	while (t--)
	{
		cout << "Scenario " << i++ << endl;
		cin >> p >> n;
		while (p--)
		{
			while (temp[temp.size() - 1] != ':') {
				cin >> in;
				cin >> temp;
				in.append(" ");
				in.append(temp.begin(), temp.end() - 1);
				v.push_back(in);
			}

			for (int f = 0; f< v.size(); f++)
			{
				node.weight = 0;
				node.n = in;
				node.visited = false;
				ans.emplace(v[f], node);
				for (int y = 0; y< v.size();y++)
				{
					if(v[f] != v[y])
						ans[v[f]].s.insert(v[y]);
				}
			}
			v.clear();
			getline(cin, temp);
		}
		bfs();
		while (n--)
		{
			getline(cin, in);
			cout << in << " ";
			if (ans[in].weight)
			{
				cout << ans[in].weight << endl;
			}
			else
			{
				cout << "infinity\n";
			}

		}
		ans.clear();
	}
	return 0;
}

inline void bfs()throw()
{
	Node n;
	string temp;
	queue <string> q;
	q.push("Erdos, P.");
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		ans[temp].visited = true;
		for (auto const &a : ans[temp].s)
		{
			if (!ans[a].visited)
			{
				ans[a].visited = true;
				ans[a].weight = ans[temp].weight + 1;
				q.push(a);
			}
		}
	}

}
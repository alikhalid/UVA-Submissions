//459
//#pragma warning(disable:4996)
#include <iostream>
#include <bitset>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define endl '\n'

using namespace std;

int MAX;
bitset <27> visited;
vector <int> adjMat[27];
vector <int> nVisit;

void bfs()
{
	int i = 0;
	int temp;
	queue <int> q;
	while (nVisit.size())
	{
		i++;
		q.push(nVisit[0]);
		while (!q.empty())
		{
			temp = q.front();
			visited[nVisit[0]] = 1;
			q.pop();
			for (auto const & val : adjMat[temp])
			{
				if (!visited[val])
				{
					visited[val] = 1;
					q.push(val);
				}
			}
		}
		nVisit.clear();
		for (int i = 1; i <= MAX; i++)
		{
			if (!visited[i])
				nVisit.push_back(i);
		}
	}
	for (int i = 0; i <= MAX; i++)
		adjMat[i].clear();

	visited.reset();
	cout << i << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int t, row, col;
	char val;
	string in;

	cin >> t;
	while (t--)
	{
		cin >> val;
		MAX = val - 65;
		nVisit.push_back(0);
		cin.ignore();
		getline(cin, in);
		while (in != "") {
			row = in[0] - 65;
			col = in[1] - 65;
			adjMat[row].push_back(col);
			adjMat[col].push_back(row);
			getline(cin, in);
		}
		bfs();
		cout << endl;
	}

	return 0;
}
//929
#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define N 100
using namespace std;

int maze[N][N];
const int dir[4][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
struct Node
{
	int x, y, w;
	Node(int a, int b, int c) :x(a), y(b), w(c) {}
	bool operator<(const Node& a) const { return w > a.w; }
};

int dijkstra(int &n, int &m)
{
	bool visit[N][N];
	int dist[N][N];

	priority_queue<Node> Q;

	int i, j;

	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < m + 1; j++)
		{
			dist[i][j] = 1e9;
			visit[i][j] = false;
		}
	}

	dist[1][1] = maze[1][1];
	Q.push(Node(1, 1, dist[1][1]));

	int all = n*m;
	for (i = 0; i < all; i++)
	{
		int next_x = -1, next_y = -1;

		while (!Q.empty())
		{
			Node node = Q.top();
			Q.pop();

			if (!visit[node.x][node.y])
			{
				next_x = node.x;
				next_y = node.y;
				break;
			}
		}

		if (next_x == n && next_y == m)
			return dist[n][m];

		visit[next_x][next_y] = true;
		for (j = 0; j < 4; j++)
		{
			int x = next_x + dir[j][0], y = next_y + dir[j][1];
			if ((x!=0 && x <= n && y != 0 && y <= m))
				if ((dist[next_x][next_y] + maze[x][y]) < dist[x][y])
				{
					dist[x][y] = dist[next_x][next_y] + maze[x][y];
					Q.push(Node(x, y, dist[x][y]));
				}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int test, n, m, val;

	cin >> test;
	while (test--)
	{
		cin >> n >> m;
		for (int z = 1; z <= n; z++)
		{
			for (int v = 1; v <= m; v++)
			{
				cin >> val;
				maze[z][v] = val;
			}
		}
		cout << dijkstra(n, m) << endl;

	}
	return 0;
}
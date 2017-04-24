#include <string>
#include <iostream>

using namespace std;

#define endl '\n'

string direction, *a;
int matrixRow, matLength;

int check(string word) throw()
{
	string n, ne, e, se, s, sw, w, nw;
	bool found = false;
	int index = 0, col = 32, length;
	length = word.length();
	while (index <= matLength)
	{
		for (int i = 32; i < matrixRow + 32; i++)
		{
			if (a[i][col] == word[0])
			{
				n = ne = e = se = s = sw = w = nw = word[0];
				for (int x = 1; x < length; x++)
				{
					n += a[i - x][col];
					ne += a[i - x][col + x];
					nw += a[i - x][col - x];
					s += a[i + x][col];
					se += a[i + x][col + x];
					sw += a[i + x][col - x];
					w += a[i][col - x];
					e += a[i][col + x];
				}
				if (n == word)
				{
					direction = "N";
					found = true;
				}
				else if (ne == word)
				{
					direction = "NE";
					found = true;
				}
				else if (e == word)
				{
					direction = "E";
					found = true;
				}
				else if (se == word)
				{
					direction = "SE";
					found = true;
				}
				else if (s == word)
				{
					direction = "S";
					found = true;
				}
				else if (sw == word)
				{
					direction = "SW";
					found = true;
				}
				else if (w == word)
				{
					direction = "W";
					found = true;
				}
				else if (nw == word)
				{
					direction = "NW";
					found = true;
				}
				if (found == true)return index;
			}
			index++;
		}
		col++;
	}
return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string input, *searchWords;
	int l, x, i, k(0), n, inLines, numWords, index;

	cin >> n;//number of data sets
	while (k < n)
	{
		if (k != 0)
			cout << endl;
		matLength =0;
		input = "";
		x = 0;
		i = 0;
		inLines = 0;

		cin >> matrixRow;
		cin >> numWords;

		searchWords = new string[numWords];
		for (int i = 0; i < numWords; i++)
		{
			cin >> searchWords[i];
		}
		cin >> inLines;
		cin.ignore();

		i = 32;
		a = new string[matrixRow + 64];
		if (matrixRow != 0)
		{
			for (int z = 32; z < matrixRow + 32; z++)
			{
				a[z] += "++++++++++++++++++++++++++++++++";
			}
			for (int d = 0; d < inLines; d++)
			{
				getline(cin, input);
				l = input.length();
				for (int x = 0; x < l; x++)
				{
					if (isalpha(input[x]))
					{
						if (i == (matrixRow + 32))
							i = 32;

						a[i] += input[x];
						i++;
						matLength++;
					}
				}
			}
			for (int z = 32; z < matrixRow + 32; z++)
			{
				a[z] += "++++++++++++++++++++++++++++++++++";

			}
			for (int g = 0; g < 32; g++)
			{
				a[g].resize((matLength / matrixRow) + 65, '+');
				a[g + 32 + matrixRow].resize((matLength / matrixRow) + 65, '+');
			}
			for (int i = 0; i < numWords; i++)
			{
				index = check(searchWords[i]);
				cout << searchWords[i];
				if (index != -1)
					cout << " " << index << " " << direction << endl;
				else
					cout << " NOT FOUND" << endl;
			}

		}
		else
		{
			for (int i = 0; i < inLines; i++)
			{
				getline(cin, input);
			}
			for (int i = 0; i < numWords; i++)
			{
				cout << searchWords[i] << " NOT FOUND" << endl;

			}
		}
		if (numWords > 0)
			delete[]searchWords;
		delete[]a;
		k++;
	}
	return 0;
}


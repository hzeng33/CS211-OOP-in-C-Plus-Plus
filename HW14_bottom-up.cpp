
#include <iostream>
#include<string>

using namespace std;

const int rows= 5, cols = 6;
int cost[rows][cols];
string path[rows][cols];

int main()
{
	static int weight[rows][cols] = { {3,4,1,2,8,6},
									  {6,1,8,2,7,4},
									  {5,9,3,9,9,5},
									  {8,4,1,3,2,6},
									  {3,7,2,8,6,4} };

	for (int i = 0; i < rows; i++) {
		cost[i][0] = weight[i][0];
		path[i][0] = to_string(i);
	}

	for (int j = 1; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			int left = weight[i][j] + cost[i][j - 1];
			int up = weight[i][j] + cost[(i + 4) % rows][j - 1];
			int down = weight[i][j] + cost[(i + 1) % rows][j - 1];

			int min = left;
			path[i][j] = path[i][j - 1] + to_string(i);

			if (up < min) {
				min = up;
				path[i][j] = path[(i + 4) % rows][j - 1] + to_string(i);
			}

			if (down < min) {
				min = down;
				path[i][j] = path[(i + 1) % rows][j - 1] + to_string(i);
			}

			cost[i][j] = min;
		}
	}

	int ex[rows];
	int minrow = 0;

	for (int i = 0; i < rows; i++) {
		ex[i] = cost[i][cols - 1];
	}

	int min = ex[0];
	for (int i = 1; i < rows; i++)
		if (min > ex[i]) {
			min = ex[i];
			minrow = i;
		}

	cout << "The shortest path is of length " << min << endl;
	cout << "The rows of the path from left to right are" << path[minrow][cols - 1];
	cout << endl;

	return 0;
}

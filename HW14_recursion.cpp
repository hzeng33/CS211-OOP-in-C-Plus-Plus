
#include <iostream>
#include <string>

using namespace std;

const int rows = 5;
const int cols = 6;
string path[rows][cols];

int cost(int i, int j) { // i is the row, j is the column
	int weight[rows][cols] = {
	{3,4,1,2,8,6},
	{6,1,8,2,7,4},
	{5,9,3,9,9,5},
	{8,4,1,3,2,6},
	{3,7,2,8,6,4} };
	static int memo[rows][cols] = { 0 };
	//base case
	if (j == 0) {
		path[i][j] = to_string(i);
		return weight[i][0];
	}
	if (memo[i][j] != 0) {
		return memo[i][j];
	}
	
	// recursive call
	int left = weight[i][j] + cost(i, j - 1);
	int up = weight[i][j] + cost((i - 1 + rows) % rows, j - 1);
	int down = weight[i][j] + cost((i + 1) % rows, j - 1);

	// find the value of the shortest path through cell (i,j)
	int min = left;
	path[i][j] = path[i][j-1] + to_string(i);
	if (up < min) {
		min = up;
		path[i][j] = path[(i - 1 + rows) % rows][j - 1] + to_string(i);
	}
	if (down < min) {
		min = down;
		path[i][j] = path[(i + 1) % rows][j - 1] + to_string(i);
	}

		return memo[i][j]= min;
}

int main() {
	int ex[rows];
	int minrow = 0;
	// get the shortest path out of each cell on the right
	for (int i = 0; i < rows; i++)
		ex[i] = cost(i, cols - 1);

	// now find the smallest of them
	int min = ex[0] ;
	for (int i = 1; i < rows; i++) 
		if (min > ex[i]) {
			min = ex[i];
			minrow = i;
		}
	
	cout << "The shortest path is of length " << min << endl;
	cout << "The rows of the path from left to right are"<<path[minrow][cols-1];
	cout << endl;
	
	return 0;

}

	
// C++ implementation of 
// the above approach 

#include <bits/stdc++.h> 
using namespace std; 

class GameOfLife { 
public: 
	// Function to display the grid 
	void print(vector<vector<int> > grid); 

	// Function to check if 
	// index are not out of grid 
	bool save(vector<vector<int> > grid, 
			int row, int col); 

	// Function to get New Generation 
	void solve(vector<vector<int> >& grid); 
}; 

void GameOfLife::print( 
	vector<vector<int> > grid) 
{ 
	int p = grid.size(), 
		q = grid[0].size(); 

	for (int i = 0; i < p; i++) { 
		for (int j = 0; j < q; j++) { 

			cout << grid[i][j]; 
		} 
		cout << endl; 
	} 
} 

bool GameOfLife::save( 
	vector<vector<int> > grid, 
	int row, int col) 
{ 
	return (grid.size() > row 
			&& grid[0].size() > col 
			&& row >= 0 
			&& col >= 0); 
} 

// Possible neighboring indexes 
int u[] = { 1, -1, 0, 1, -1, 0, 1, -1 }; 
int v[] = { 0, 0, -1, -1, -1, 1, 1, 1 }; 

void GameOfLife::solve( 
	vector<vector<int> >& grid) 
{ 
	int p = grid.size(), 
		q = grid[0].size(); 

	for (int i = 0; i < p; i++) { 
		for (int j = 0; j < q; j++) { 

			// IF the initial value 
			// of the grid(i, j) is 1 
			if (grid[i][j] > 0) { 
				for (int k = 0; k < 8; k++) { 

					if (save(grid, i + u[k], 
							j + v[k]) 
						&& grid[i + u[k]] 
							[j + v[k]] 
							> 0) { 

						// If initial value > 0, 
						// just increment it by 1 
						grid[i][j]++; 
					} 
				} 
			} 

			// IF the initial value 
			// of the grid(i, j) is 0 
			else { 
				for (int k = 0; k < 8; k++) { 

					if (save(grid, i + u[k], 
							j + v[k]) 
						&& grid[i + u[k]] 
							[j + v[k]] 
							> 0) { 

						// If initial value <= 0 
						// just decrement it by 1 
						grid[i][j]--; 
					} 
				} 
			} 
		} 
	} 

	// Generating new Generation. 
	// Now the magnitude of the grid 
	// will represent number of neighbours 
	for (int i = 0; i < p; i++) { 
		for (int j = 0; j < q; j++) { 

			// If initial value was 1. 
			if (grid[i][j] > 0) { 

				// Since Any live cell with 
				// < 2 live neighbors dies 
				if (grid[i][j] < 3) 
					grid[i][j] = 0; 

				// Since Any live cell with 
				// 2 or 3 live neighbors live 
				else if (grid[i][j] <= 4) 
					grid[i][j] = 1; 

				// Since Any live cell with 
				// > 3 live neighbors dies 
				else if (grid[i][j] > 4) 
					grid[i][j] = 0; 
			} 
			else { 

				// Since Any dead cell with 
				// exactly 3 live neighbors 
				// becomes a live cell 
				if (grid[i][j] == -3) 
					grid[i][j] = 1; 

				else
					grid[i][j] = 0; 
			} 
		} 
	} 
} 

// Driver code 
int main() 
{ 

	vector<vector<int> > grid 
		= {{ 0, 0, 0, 0, 0, 
			0, 0, 0, 0, 0 }, 
			{ 0, 0, 0, 1, 1, 0, 
			0, 0, 0, 0 }, 
			{ 0, 0, 0, 0, 1, 0, 
			0, 0, 0, 0 }, 
			{ 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0 }, 
			{ 0, 0, 0, 0, 0, 0, 
			0, 0, 0, 0 }}; 

	GameOfLife obj; 

	// Function to generate 
	// New Generation inplace 
	obj.solve(grid); 

	// Displaying the grid 
	obj.print(grid); 

	return 0; 
} 


#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <functional>
#include <algorithm>
#include <random> 

#include "solution.hpp"

// using namespace std; 

int main(int argc, char **argv) {
	std::cout << "Welcome to LeetCode! " << std::endl; 

	vector<vector<int>> vec2d = {{0,0,0},{0,1,0},{1,1,1}};
	Solution slt; 
	vector<vector<int>> result = slt.updateMatrix(vec2d); 

	// Matrix matrix(vec2d); 
	Matrix matrix = result;
	cout << matrix;

	system("pause"); 
	return 0; 
}
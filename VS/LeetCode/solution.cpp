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

#include "solution.hpp"

using namespace std;


void Solution::private_method() {
	cout << "Welcome to Solution! " << endl;

	return;
}

void Solution::public_method() {
	private_method();

	return;
}

/*
int Solution::maximalRectangle(vector<vector<char>>& matrix) {

}
*/

vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& matrix) {
	vector<vector<int>> result(matrix.size(), vector<int>(matrix.back().size()));
	
	// forward pass
	for (int i = 0; i < matrix.size(); ++i)
		for (int j = 0; j < matrix.back().size(); ++j)
		{
			if (matrix[i][j] == 0)
				continue;
			int dist = INT_MAX >> 1;
			if (j - 1 >= 0)
				dist = min(dist, result[i][j - 1] + 1);
			if (i - 1 >= 0)
				dist = min(dist, result[i - 1][j] + 1);
			result[i][j] = dist;
		}
	
	// backward pass
	for (int i = matrix.size() - 1; i >= 0; --i)
		for (int j = matrix.back().size() - 1; j >= 0; --j)
		{
			if (matrix[i][j] == 0)
				continue;
			int dist = INT_MAX >> 1;
			if (j + 1 < matrix.back().size())
				dist = min(dist, result[i][j + 1] + 1);
			if (i + 1 < matrix.size())
				dist = min(dist, result[i + 1][j] + 1);
			result[i][j] = min(dist, result[i][j]);
		}
	
	return result;
}

/***********************************************************************************/
// int searchInsert(vector<int>& nums, int target){}

// vector<vector<int>> pathSum(TreeNode* root, int sum){}

// int numTrees(int n){} // unique binary search; 

// ListNode* reverseBetween(ListNode* head, int m, int n){}
/***********************************************************************************/
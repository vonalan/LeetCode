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

using namespace std;

class Matrix {
friend ostream &operator<<(ostream &os, Matrix &matrix) {
	pair<int, int> s = matrix.size();
	int m = s.first, n = s.second;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << matrix(i, j) << " ";
		cout << endl;
	}

	return os;
}

public:
	// copy constructor
	Matrix(vector<vector<int>> vec2d) :matrix(vec2d) {} 
	
	// copy assignment operator 
	Matrix &operator=(vector<vector<int>> vec2d) {
		this->matrix = vec2d;
		return *this;
	}

	// move constructor
	// move assignment operator 

	pair<int, int> size() const {
		int m = matrix.size();
		int n = matrix.back().size();

		return make_pair(m, n);
	}

	int operator()(int i, int j) const {
		return matrix[i][j];
	}

private:
	vector<vector<int>> matrix;
};

struct ListNode
{
	int val; 
	ListNode *next; 

	ListNode(int x) : val(x), next(nullptr){}
};

struct TreeNode
{
	int val; 
	TreeNode *left; 
	TreeNode *right; 

	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

struct Interval
{
	int start; 
	int end; 
	Interval() : start(0), end(0){}
	Interval(int s, int e) : start(s), end(e){}

	friend ostream &operator<<(ostream &os, const Interval &interval); 
};

class Solution {
public:
	void public_method();
	int maximalRectangle(vector<vector<char>>& matrix); 
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix); 
private:
	void private_method();
};
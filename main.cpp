#include<iostream>
#include<numeric>
#include"me.h"
#include <ostream>
#include <vector>
#include<assert.h>

using namespace std;

// This is a dynamic programming program to handle the 0-1 backpack problem

int CalculateMaxValue(int capacity, const std::vector<int>& weights, const std::vector<int> values)
{
	assert(weights.size()==values.size());
	assert(capacity>0);
	assert(weights.size()>0);

	int sz = weights.size();
	std::vector<std::vector<int>> dynamic_matrix(sz + 1, std::vector<int>(capacity + 1, 0));
	
	for(int i=0;i<capacity;++i)
	{
		dynamic_matrix[0][i] = 0;
	}

	for(int i = 1; i < sz + 1; ++i)
	{
		for(int j = 0; j < capacity + 1; ++j)
		{
			int no_has = dynamic_matrix[i-1][j]; 
			int has;
			if(j - weights[i-1] >= 0)
			{
				has = dynamic_matrix[i-1][j-weights[i-1]] + values[i-1];
			}
			else
			{
				has = 0;
			}
			dynamic_matrix[i][j] = has>no_has?has:no_has;
		}
	}


	return dynamic_matrix[sz][capacity];
}

int main()
{
	int result = CalculateMaxValue(4, {2,1,3}, {4,2,3});
	std::cout<<result<<std::endl;
	return 0;
}


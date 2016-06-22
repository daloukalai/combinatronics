// This is simple program, which follows combinatronics way of solving problems.
// This program finds the subsets of a given set.


#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> getSubset(vector<int> &v)
{
	vector<vector<int>> subsets;
	vector<int> subset;
	int n = v.size();
	// 1. In combinatronics, there exists 2^n combinations
	int max = 1 << n;
	int k, index;
	for(int i =0; i < max; i++)
	{
		subset.clear();
		k = i;
		index = 0;
		//2. Implement the heart of algo to extract each combination
		while(k > 0)
		{
			if(k & 1 > 0)
			{
				subset.push_back(v[index]);
			}
			k >>= 1;
			index++;
		}
		// 3. Put each combination into the bag
		subsets.push_back(subset);
	}
	return subsets;
}

void print(vector<int> &subset)
{	
	if(subset.size() == 0)
	{
		cout << "{empty}" << endl;
	}
	else
	{
		cout << "{";
		vector<int>::iterator it;
		for(it = subset.begin(); it != subset.end(); ++it)
		{
				cout << *it << ", ";
		}
		cout << "}" << endl;
	}

}
void print(vector<vector<int>> &subsets)
{
	vector<vector<int>>::iterator it;
	for(it = subsets.begin(); it != subsets.end(); ++it)
	{
		print(*it);
	}
}
void main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(8);
	vector<vector<int>> subsetArr;
	subsetArr = getSubset(v);
	print(subsetArr);
}


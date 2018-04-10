// Convert this program to C++

// change to C++ io

// change to one line comments

// change defines of constants to const

// change array to vector<>

// inline any short function

#include <iostream>
#include <vector>
// #include <accumulate>

using namespace std; 

const int vector_size  = 40;


inline void sum(int& p, const vector<int> &d)
{
	p = 0;
	
	// interate through vector, 
	// for(auto &n : d)
	// 	p += n;
	for (int i=0; i < d.size(); i++)
       p += d[i];

}


int main()
{
	vector<int> data(vector_size);

	for(int i = 0; i < data.size(); ++i)
		data.at(i) = i;

	int accum = 0;
	sum(accum, data);

//	int accum = 0;
//	accum = accumulate(data.begin(), data.end(), 0);
	
	cout << "sum is" << accum << endl; 

	return 0;
}



// Convert this program to C++

// change to C++ io

// change to one line comments

// change defines of constants to const

// change array to vector<>

// inline any short function

#include <iostream>
#include <vector>
#include <numeric>

using namespace std; 

const int vector_size  = 40;

int main(){
	vector<int> data(vector_size);

	for(int i = 0; i < data.size(); ++i) 
		data.at(i) = i;
	
	int accum = accumulate(data.begin(), data.end(), 0);

	cout << "Sum is " << accum << endl; 

	return 0;
}



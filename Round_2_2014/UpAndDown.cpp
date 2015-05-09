// https://code.google.com/codejam/contest/3014486/dashboard
// Data-Packing 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
using namespace std;
#include <iostream>
#include <queue>
#include <assert.h>

const char* inFileName = "B-large-practice.in";
const char* outFileName = "out.txt";


int main()
{
	std::ifstream infile(inFileName);
	std::ofstream outfile(outFileName);
	if( infile.fail() || outfile.fail() )
	{
		return 0;
	}

	string line;
	getline(infile,line);
	int T = stoi(line);
	
	for( int Case = 1; Case <= T; Case++ )
	{
		getline(infile,line);
		istringstream iss(line); 
		int N;
		iss >> N;
		vector<int> seq;

		getline(infile,line);
		istringstream iss2(line); 
		for( int i=0; i< N; i++ )
		{
			int n = 0;
			iss2 >> n;
			seq.push_back(n);
		}

		int nbswaps = 0;
		int idx = -1; // index of the minimum in the sequence
		while( seq.size() > 1 )
		{
			// find the smallest number in the sequence
			if( idx == -1 )
			{
				auto it = std::min_element( seq.begin(), seq.end() );
				idx = it - seq.begin(); // index of the iterator
			}

			if( idx == 0 || idx == seq.size()-1 )
			{
				// we are good, remove it and continue with the sequence :
				seq.erase( seq.begin() + idx );
				idx = -1;
			}
			else
			{
				// is that closer to the left or to the right ?
				if( idx < seq.size()/2 )
				{
					int temp = seq[idx];
					seq[idx] = seq[idx-1];
					seq[idx-1] = temp;
					idx--;
				}
				else
				{
					int temp = seq[idx];
					seq[idx] = seq[idx+1];
					seq[idx+1] = temp;
					idx++;
				}
				nbswaps++;
			}
		}

		cout<<"Case #"<<Case<<": "<<nbswaps<<endl;
		outfile<<"Case #"<<Case<<": "<<nbswaps<<endl;
	}	

    infile.close();
	outfile.close();
	system("pause");
	return 0;
}
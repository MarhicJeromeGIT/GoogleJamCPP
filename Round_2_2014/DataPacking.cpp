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

const char* inFileName = "A-large-practice.in";
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
		int N,X;
		iss >> N >> X;
		vector<int> sizes;

		getline(infile,line);
		istringstream iss2(line); 

		for( int i=0; i< N; i++ )
		{
			int s;
			iss2 >> s;
			sizes.push_back(s);
		}
		std::sort( sizes.begin(), sizes.end() );


		int nbdiscs = 0;
		int i = N-1;
		int cds = 0;
		while( sizes[i] > X/2 && i > 0 )
		{
			int rem = X - sizes[i];
			int j=0;
			while( sizes[j] == 0  && j < i )
			{
				j++;
			}
			if( j < i )
			{
				// we can pack those two together.
				if( sizes[j] <= rem )
					sizes[j] = 0;
			}
			sizes[i] = 0;
			i--;
			cds++;
		}
		// count how many file remains
		int remainings = 0;
		for( int i=0; i< N; i++ )
		{
			if( sizes[i] > 0 )
				remainings++;
		}
		cds += ceil( ((float) remainings)/2.0f);

		cout<<"Case #"<<Case<<": "<<cds<<endl;
		outfile<<"Case #"<<Case<<": "<<cds<<endl;
	}	

    infile.close();
	outfile.close();
	system("pause");
	return 0;
}
// My solution for Google jam problem Problem B. Many Prizes
// https://code.google.com/codejam/contest/2442487/dashboard#s=p1
// Jerome

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

const char* inFileName = "A-small-practice.in";
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
		int N,M;
		iss >> N >> M;

		outfile<<"Case #"<<Case<<": "<< (costNormal -	totalPriceCheating) % 1000002013<<endl;
	}

    infile.close();
	outfile.close();
	system("pause");
	return 0;
}
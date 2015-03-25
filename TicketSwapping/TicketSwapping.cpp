// My solution for Google jam problem Problem A. Ticket Swapping
// https://code.google.com/codejam/contest/2442487/dashboard
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


int computePrice(int o, int e, int N)
{
	int cost = 0;
	for( int i=0; i<e-o; i++ )
	{
		cost += N-i;
	}
	return cost;
}

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

		vector<int> origin(N+1,0);
		vector<int> exit(N+1,0);
		int costNormal = 0;
		for( int i=0; i< M; i++ )
		{
			getline(infile,line);
			iss.clear();
			iss.str(line);
			int o,e,p;
			iss >> o >> e >> p;

			origin[o] = p;
			exit[e] = p;

			// price if we were honest
			costNormal += p * computePrice(o,e,N);
		}
		cout<<"Cost Normal = "<<costNormal<<endl;

		// and now if we cheat...
		// let's run the train from station 1 to N :
		map<int,int> cards; // <nb stations, nb cards>
		int totalPriceCheating = 0;
		for( int stn = 1; stn <= N; stn++ )
		{
			// we arrived at a new station : increase the cost of the existing cards
			map<int,int> newCards;
			for( auto it = cards.begin(); it != cards.end(); it++ )
			{
				newCards.insert( pair<int,int>( it->first +1, it->second ) );
			}
			cards = newCards;

			// make the passengers enter : add cards
			if( origin[stn] != 0 )
			{
				cards.insert( pair<int,int>( 0, origin[stn] ) );
			}

			// now all the exiting passengers take a card (the smallest possible to pay as little as possible) :
			int exiting = exit[stn];
			while( exiting > 0 )
			{
				auto it = cards.begin(); // maps are sorted by order of the keys ! convenient.

				if( it->second > exiting ) // number of cards
				{
					totalPriceCheating += exiting * computePrice(0,it->first,N);
					exiting = 0;
					it->second -= exiting;
				}
				else
				{
					totalPriceCheating += it->second * computePrice(0,it->first,N);
					exiting -= it->second;
					cards.erase(it);
				}
			}
		}

		outfile<<"Case #"<<Case<<": "<< (costNormal -	totalPriceCheating) % 1000002013<<endl;
	}

    infile.close();
	outfile.close();
	system("pause");
	return 0;
}
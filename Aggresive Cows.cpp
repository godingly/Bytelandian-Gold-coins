#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
using namespace std;

unsigned AGC(const vector<unsigned>&  barn, unsigned C)
{
	unsigned hi = barn.back() - barn.front();
	unsigned lo = 0;
	unsigned min_dist = barn.back() - barn.front();
	int count = 0;
	while (lo <= hi)
	{
//		if (count++ > 10)	break;
		if ((lo + hi + 1) / 2 == min_dist){
		 	//printf("equal\n");
		 	break;
	 	}
		min_dist = (lo + hi + 1) / 2; // Minimum distance we have to traverse in order to assign a cow
		//printf("min_dist = %u, lo = %u, hi = %u\n", min_dist, lo, hi);
		unsigned assigned = 1;
		unsigned distance = 0;
		for (unsigned i = 1; i < barn.size(); i++)
		{
			distance += barn[i] - barn[i-1];
			//printf(" now at barn[%u] = %u, distance = %d\n", i, barn[i], distance);
			if (distance >= min_dist)
			{
				distance = 0;
				assigned++;
				//printf(" assigned %u cow to barn[%u] = %u\n", assigned, i, barn[i]);
			}
			if (assigned == C)
			{
				break;
			}
		}
		if (assigned == C)
		{
			lo = min_dist;
			//printf(" assigned all, lo = %u\n", lo);
		}
		else 
		{
			hi = min_dist-1;
			//printf(" Couldn't assign all, hi = %u\n", hi);
		}
	}
	return min_dist;
	
}

int main()
{
	unsigned t, N, C;
	t = N = C = 0;
	vector<unsigned> barn;
	int input = 0;
	cin >> t;
	for (; t!= 0; t--)
	{
		barn.clear();
		cin >> N >> C;
		for (; N != 0; N--)
		{
			cin >> input;
			barn.push_back(input);
		}
		sort(barn.begin(), barn.end());
		cout << AGC(barn, C) << endl;
	}
	
}

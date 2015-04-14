#include "WineryList.h"
#include "Winery.h"
#include <vector>


int main()
{

	vector<Winery> wineryList;
	Winery currentWinery;

	ifstream inFile;

	inFile.open("wineries.txt");

	for(int i =0; i < 10; i ++)
	{
		currentWinery.Initiate(inFile);
		wineryList.push_back(currentWinery);
		inFile.ignore();
	}

	for(unsigned int i = 0; i < wineryList.size(); i ++)
	{
		wineryList[i].display();
	}




	return 0;
}




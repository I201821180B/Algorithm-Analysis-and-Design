//Kruskal's algorithm
#include <iostream>
#include <conio.h>
using namespace std;



int main()
{
	int path[8][8]; //tells if path exists betweeen the 2 nodes
	int edge[8][8]; //stores edge weights
	int v = 8; //no. of vertices
	int e = 16; //no. of edges
	
	//-----------------------------GRAPH CREATION------------------------------
	for(int i=0;i<8;i++)
	{
			for(int j=0;j<8;j++)
			{
			 		path[i][j] = 0; //by default,no path
			 		edge[i][j] = 0;
			}
	}

	//Storing entire graph with weights:
	path[0][1] = 1;
	edge[0][1] = 4;
	path[0][7] = 1;
	edge[0][7] = 8;
	path[1][7] = 1;
	edge[1][7] = 11; 
    path[1][8] = 1;
	edge[1][8] = 17;
	path[7][8] = 1;
	edge[7][8] = 7;
	path[1][2] = 1;
	edge[1][2] = 8;
	path[2][8] = 1;
	edge[2][8] = 2;
	path[7][6] = 1;
	edge[7][6] = 1;
	path[6][8] = 1;
	edge[6][8] = 6;
	path[6][5] = 1;
	edge[6][5] = 2;
	path[2][5] = 1;
	edge[2][5] = 4;
	path[5][8] = 1;
	edge[5][8] = 9;
	path[2][3] = 1;
	edge[2][3] = 9;
	path[3][5] = 1;
	edge[3][5] = 14;
	path[3][4] = 1;
	edge[3][4] = 4;
	path[4][5] = 1;
	edge[4][5] = 7;

    //if there is a path from 1 to 7,same for 7 to 1
	for(int i=0;i<8;i++)
	{
			for(int j=0;j<8;j++)
			{
					if(path[i][j] == 1 && path[j][i] == 0)
					{
								  edge[j][i] = edge[i][j];
								  path[j][i] = 1;
					}
			}
	}
	
	getch();
	return 0;
}



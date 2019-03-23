//Prim's algorithm
#include <iostream>
#include <conio.h>
using namespace std;

#define V 8
#define E 16
#define INF 10000

int source = 0;
int path[8][8]; //tells if path exists betweeen the 2 nodes
int edge[8][8]; //stores edge weights
int visited[8];
int key[8];
int mstSet[8]; //initially: doesnt contain any vertices in mst
int mstInd=0;

int inMstSet(int v)
{
	 for(int i=0;i<mstInd;i++)
	 {
			 if(mstSet[i] == v)
			              return 1;
	 }
	 return 0;
}

int minKey()
{
	 int min = INF;
	 int minPos=-1;
	 for(int i=0;i<8;i++)
	 {
			 if(key[i]<min)
			 {
						   min = key[i];
						   minPos=i;
			 }
	 }
	 return minPos;
}

void prim()
{
	 mstSet[0] = source;
	 mstInd++;
	 int minPos = source;
	 
	 while(mstInd != 8)
	 {
                  //update key values
				  for(int i=0;i<8;i++)
				  {
						  if(path[minPos][i] == 1) //neighbours
						  {
							  if(edge[minPos][i] < key[i])
							  {
								  cout<<"Key value of "<<i<<" updated\n";
								  key[i] = edge[minPos][i];
							  }
						  }
				  }

				  for(int i = 0; i < 8;i++)
				  {
						  //if : not in mstSet,min key value then include
						  //it to mstSet.
						  if(inMstSet(i) == 0)
						  {
										 minPos = minKey();
										 mstSet[mstInd++] = minPos;
										 cout<<minPos<<"added to mstSet\n";
										 break;
						  }
				  }
				  
				  
				  
				  cout<<"üpdated key values:\n";
				  for(int i=0;i<8;i++)
				  {
						  cout<<key[i]<<"\t";
				  }
				  cout<<endl;

	 }
	 
}

void init_key()
{
	 for(int i=0;i<8;i++)
	 {
			 key[i] = INF;
	 }
}

int main()
{
	//const int v = V;
	
	init_key();

	//-----------------------------INITIALIZATION------------------------------
	for(int i=0;i<8;i++)
	{
			for(int j=0;j<8;j++)
			{
			 		path[i][j] = 0; //by default,no path
			 		edge[i][j] = 0;
			}
			visited[i] = 0;
	}


	//-----------------------------GRAPH CREATION------------------------------
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

	prim();

	getch();
	return 0;
}



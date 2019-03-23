/* tower of hanoi
fromPole,withPole,toPole
*/
#include <iostream>
#include <conio.h>
using namespace std;

void moveDisk(char fromPole,char toPole)
{
	 cout<<"Moving disk from "<<fromPole<<" to "<<toPole<<endl;
}

void moveTower(int height,char fromPole,char toPole,char withPole)
{
	 if(height>=1)
	 {
				  //move all except last from pole-1 to pole-2
				  moveTower(height-1,fromPole,withPole,toPole);
				  moveDisk(fromPole,toPole);
				  moveTower(height-1,withPole,toPole,fromPole);
	 }

}

int main()
{
	moveTower(3,'A','C','B');
	getch();
	return 0;
}

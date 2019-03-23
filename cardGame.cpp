/*Card:trump card game without trump :P*/

#include <iostream>
#include<conio.h>
#include<string>
#include <time.h>
#include <stdlib.h> //for srand
using namespace std;

struct card
{
	   string suite;
	   int number;
};

void game(card c[],int start)
{
	 //int start=1; //c[0]-c[12] particpant A
	 int startPos;
	 //for(int i=1;i<=13;i++)
	 //{
			 if(start = 1)
			          startPos = 0;
			 else if(start = 2)
			          startPos = 13;
             else if(start = 3)
			          startPos = 26;
             else if(start = 4)
			          startPos = 39;

			while(c[startPos].number != 0)
				startPos++;
			          
			card card1 = c[startPos];
			//cout<<"Round:"<<i<<endl;
			cout<<"Participant:"<<start<<":\t";
			cout<<card1.suite<<"\t"<<card1.number<<endl;

            start++;
	 	    if(start == 5)
	         		   start=1;
	 //}
}
/*void shuffle(card c[])
{
  
          for(int i=0;i<100;i++)
   		  {
			 //swap randomly 2 cards
			 srand(time(NULL));
			 int a=0,b=0;
			 while(a == b)
			 {
                  a = rand() % 52 ; //0-52
                  b = rand() % 52;  //0-52
			 }
			 cout<<a<<" and "<<b<<" swapped\n";
			 string tempSuite = c[a].suite;
			 c[a].suite = c[b].suite;
			 c[b].suite = tempSuite;
			 int tempNo = c[a].number;
			 c[a].number = c[b].number;
			 c[b].number = tempNo;
	    }
}*/

void shuffle(card c[])
{
	 for(int i=0;i<4;i++)
	 {
			 int a=i;
			 int b=51-i;
             string tempSuite = c[a].suite;
			 c[a].suite = c[b].suite;
			 c[b].suite = tempSuite;
			 int tempNo = c[a].number;
			 c[a].number = c[b].number;
			 c[b].number = tempNo;
	 }
	 for(int i=5;i<10;i++)
	 {
			 int a=i;
			 int b=39-i;
             string tempSuite = c[a].suite;
			 c[a].suite = c[b].suite;
			 c[b].suite = tempSuite;
			 int tempNo = c[a].number;
			 c[a].number = c[b].number;
			 c[b].number = tempNo;
	 }
  	 for(int i=10;i<30;i+=2)
	 {
			 int a=i;
			 int b=51-i;
             string tempSuite = c[a].suite;
			 c[a].suite = c[b].suite;
			 c[b].suite = tempSuite;
			 int tempNo = c[a].number;
			 c[a].number = c[b].number;
			 c[b].number = tempNo;
	 }
}

int main()
{
	card c[52];
	
	//Deck of 52 cards
	for(int i=0;i<13;i++)
	{
			c[i].suite = "hearts";
			c[i].number=i+1;
	}
	for(int i=13;i<26;i++)
	{
			c[i].suite = "spades";
			c[i].number=i-12;
	}
	for(int i=26;i<39;i++)
	{
			c[i].suite = "clubs";
			c[i].number=i-25;
	}
	for(int i=39;i<52;i++)
	{
			c[i].suite = "diamond";
			c[i].number=i-38;
	}
	
			shuffle(c);
	cout<<"After shuffling\n";
	cout<<"Partipant 1 has:\n";
	for(int i=0;i<13;i++)
	{
			cout<<c[i].suite<<"\t";
			cout<<c[i].number;
			cout<<endl;
	}
	cout<<"Partipant 2 has:\n";
	for(int i=13;i<26;i++)
	{
			cout<<c[i].suite<<"\t";
			cout<<c[i].number;
			cout<<endl;
	}
	cout<<"Partipant 3 has:\n";
	for(int i=26;i<39;i++)
	{
			cout<<c[i].suite<<"\t";
			cout<<c[i].number;
			cout<<endl;
	}
	cout<<"Partipant 4 has:\n";
	for(int i=39;i<52;i++)
	{
			cout<<c[i].suite<<"\t";
			cout<<c[i].number;
			cout<<endl;
	}
	
	game(c,1);
	
	getch();
	return 0;
}

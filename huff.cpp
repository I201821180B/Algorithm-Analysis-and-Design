#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

#define INT_MAX 10000

using namespace std;
struct node
{
 node * leftChild;
 node * rightChild;
 double frequency;
 string content;
 string code;
};

vector<node> nodeArray;// Stores all nodes

//to extract the 2 lowest frequency nodes
node  extractMin()
{
 double temp = (double) INT_MAX;
 vector<node>::iterator i1,pos;
 for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++)
 {
  if(temp>(*i1).frequency)
  {
     pos = i1;
     temp = (*i1).frequency;
  }
 }

 node tempNode = (*pos);
 nodeArray.erase(pos);

 return tempNode;
}


//extract 2 lowest freq nodes and make new tree
//root will have freq= sum of the freq of these 2
node getHuffmanTree()
{
 while(!nodeArray.empty())
 {
   node * tempNode = new node;
   node * tempNode1 = new node;
   node * tempNode2 = new node;
   *tempNode1 = extractMin();
   *tempNode2 = extractMin();

   tempNode->leftChild = tempNode1;
   tempNode->rightChild = tempNode2;
   tempNode->frequency = tempNode1->frequency+tempNode2->frequency;
   nodeArray.push_back(*tempNode);
   if(nodeArray.size() == 1)//only the root node exists
    break;
 }
    return nodeArray[0];
    
}


void BFS(node * temproot,string s)
{
   node * root1 = new node;
   root1 = temproot;

   root1->code = s;
   if(root1 == NULL)
   {
			//error no tree formed
   }
   //leaf node
   else if(root1->leftChild == NULL && root1->rightChild == NULL)
   {
    	cout<<root1->content<<":"<<root1->code<<endl;
   }
   else
   {
       root1->leftChild->code = s.append("0");
	  s.erase(s.end()-1);
   	  root1->rightChild->code = s.append("1");
   	  s.erase(s.end()-1);
	  //once coded,remove the leaves so that we can move up the tree

      BFS(root1->leftChild,s.append("0"));
	  s.erase(s.end()-1);
      BFS(root1->rightChild,s.append("1"));
   	  s.erase(s.end()-1);
 }
}


void getHuffmanCode()
{
 int size,i;
 double tempDouble;
 string tempString = "";

 cout<<"Enter number of distinct characters"<<endl;
 cin>>size;

 for(i = 0;i<size;i++)
 {
  cout<<"Enter character and freq"<<endl;
  node tempNode;
  cin>>tempString;
  cin>>tempDouble;


  tempNode.frequency = tempDouble;
  tempNode.content = tempString;
  tempNode.leftChild = NULL;
  tempNode.rightChild = NULL;
  nodeArray.push_back(tempNode);
 }
 
 node root = getHuffmanTree();
 BFS(&root,"");
}


int main()
{
 getHuffmanCode();
 getch();
 return 0;
}


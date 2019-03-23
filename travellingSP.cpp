
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
#define N 5
#define INF 100000
int cost[N][N]={
                {0,2,INF,12,5},
                {2,0,4,8,INF},
                {INF,4,0,3,INF},
                {12,8,3,0,10},
                {5,INF,INF,10,0}};
map<string,int> mapstr; //to store previously calculated values

/*Extracts substring of given string*/
string sub(string str,int start,int end){
        string s="";
        for(int i=start;i<end;i++)
                s+=str[i];
        return s;
}
int g(string str){
        if(mapstr[str]!=0) return mapstr[str]; //using old values(dp)
        if(str.length()==1) return cost[str[0]-'0'][0];//at the end,return back to starting node

        int min=INT_MAX;
        string temp;

        for(int i=1;i<str.length();i++){
                temp=str;
                temp=temp.substr(1);
                string temp2;
                                temp2=sub(temp,i-1,i);
                                temp=sub(str,1,i)+sub(str,i+1,str.length());
                temp=temp2+temp;
                                int k=cost[str[0]-'0'][str[i]-'0']+g(temp);
                if(k<min)
                        min=k;
        }
        mapstr[str]=min;
        return min;
}
int main(){
        string str="01234";
        cout<<"Minimum path cost="<<g(str);
        getch();
        return 0;
}

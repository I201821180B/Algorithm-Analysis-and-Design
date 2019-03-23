#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct cards
{
    int num;
    int suite;
};

int win[4]={0,0,0,0};

void play(cards a[], cards b[], cards c[], cards d[], int i,char player1)
{
    cards played_card, ac, bc, cc, dc;
    if(a[i].num==-1){
        int k =0;
        while(a[k].num==-1){
        k++;
        }
        played_card.num = a[k].num;
        played_card.suite = a[k].suite;
        a[k].num=-1;
        a[k].suite=-1;
    }
    else{
        played_card.num = a[i].num;
        played_card.suite = a[i].suite;
        a[i].num=-1;
        a[i].suite=-1;
    }
    bc.num = played_card.num;
    bc.suite = played_card.suite;
    cards tc;

    tc.num = -1;
    int key = -1;
    for(int j=0; j<13; j++){
        if(b[j].suite==played_card.suite&&b[j].num>tc.num){
            tc.num = b[j].num;
            key = j;
        }
    }
    if(key == -1){
        int k =0;
        while(b[k].num==-1){
            k++;
        }
        key = k;
    }
    bc.num = b[key].num;
    bc.suite = b[key].suite;
    b[key].num = -1;
    b[key].suite = -1;

    tc.num = -1;
    key = -1;
    for(int j=0; j<13; j++){
        if(c[j].suite==played_card.suite&&c[j].num>tc.num){
            tc.num = c[j].num;
            key = j;
        }
    }
    if(key == -1){
        int k =0;
        while(c[k].num==-1){
            k++;
        }
        key = k;
    }
    cc.num = c[key].num;
    cc.suite = c[key].suite;
    c[key].num = -1;
    c[key].suite = -1;

    tc.num = -1;
    key = -1;
    for(int j=0; j<13; j++){
        if(d[j].suite==played_card.suite&&d[j].num>tc.num){
            tc.num = d[j].num;
            key = j;
        }
    }
    if(key == -1){
        int k =0;
        while(d[k].num==-1){
            k++;
        }
        key = k;
    }
    dc.num = d[key].num;
    dc.suite = d[key].suite;
    d[key].num = -1;
    d[key].suite = -1;

    cout<<"\nCard Played by "<<player1<<" : "<<played_card.num<<"  "<<played_card.suite;
    cout<<"\nCard Played by "<<char (player1+1>100 ? player1-3:player1+1)<<" : "<<bc.num<<"  "<<bc.suite;
    cout<<"\nCard Played by "<<char (player1+2>100 ? player1-2:player1+2)<<" : "<<cc.num<<"  "<<cc.suite;
    cout<<"\nCard Played by "<<char (player1+3>100 ? player1-1:player1+3)<<" : "<<dc.num<<"  "<<dc.suite;
    int maxi = played_card.num, w = 0;
    if(bc.suite==played_card.suite && bc.num>maxi){
        w = 1;
        maxi = bc.num;
    }
    if(cc.suite==played_card.suite && cc.num>maxi){
        w = 2;
        maxi = cc.num;
    }
    if(dc.suite==played_card.suite && dc.num>maxi){
        w = 3;
        maxi = dc.num;
    }
    if(w==0){
        cout<<"\n"<<player1<<" won.";
        win[player1-97]++;
    }
    else if(w==1){
        cout<<"\n"<<char (player1+1>100 ? player1-3:player1+1)<<" won.";
        win[player1-97]++;
    }
    else if(w==2){
        cout<<"\n"<<char (player1+2>100 ? player1-2:player1+2)<<" won.";
        win[player1-97]++;
    }
    else if(w==3){
        cout<<"\n"<<char (player1+3>100 ? player1-1:player1+3)<<" won.";
        win[player1-97]++;
    }
    system("pause");
}
int main()
{
    srand(time(0));
    cards card[52];
    int f=0;
    
    for(int i=0; i< 4; i++){    //initialize card numbers and suites
        for(int j=0; j<13; j++){
            card[f].num = j;
            card[f].suite = i;
            f++;
        }
    }

    for(int i=0; i<100; i++){    //shuffling
        int r = rand()%40;
        int tn, ts;
        tn = card[r].num;
        ts = card[r].suite;
        card[r].num = card[r+12].num;
        card[r].suite = card[r+12].suite;
        card[r+12].num = tn;
        card[r+12].suite = ts;
    }

    cards a[13], b[13], c[13], d[13];

    for(int i=0; i<13; i++){    //deal to A
        a[i].num = card[i].num;
        a[i].suite = card[i].suite;
    }
    for(int i=13; i<26; i++){   //deal to B
        b[i-13].num = card[i].num;
        b[i-13].suite = card[i].suite;
    }
    for(int i=26; i<39; i++){   //deal to C
        c[i-26].num = card[i].num;
        c[i-26].suite = card[i].suite;
    }
    for(int i=39; i<52; i++){   //deal to D
        d[i-39].num = card[i].num;
        d[i-39].suite = card[i].suite;
    }

    for(int i=0; i<13; i++){
        if(i%4==0){ //A plays first
            play(a,b,c,d,i,'a');
        }
        else if(i%4==1){    //B plays first
            play(b,c,d,a,i,'b');
        }
        else if(i%4==2){    //C plays first
            play(c,d,a,b,i,'c');
        }
        else if(i%4==3){    //D plays first
            play(d,a,b,c,i,'d');
        }
    }
    cout<<"\nGames won by A : "<<win[0]
        <<"\nGames won by B : "<<win[1]
        <<"\nGames won by C : "<<win[2]
        <<"\nGames won by D : "<<win[3];
        system("pause");
        return 0;
}

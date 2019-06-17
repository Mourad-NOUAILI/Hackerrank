#include<iostream>

using namespace std;


int main()
{   
    unsigned int aD,aM,aY,eD,eM,eY;
    cin>>aD>>aM>>aY;
    cin>>eD>>eM>>eY;
    
    unsigned int fine = 0;
    if (aD <= eD && aM <= eM && aY <= eY) fine = 0;
    if (aD > eD && aM == eM && aY == eY) fine = 15 * (aD-eD);
    if (aY == eY && aM > eM) fine = 500 * (aM-eM);
    if (aY > eY) fine = 10000;
    
    cout<<fine<<'\n';
    return 0;
} 

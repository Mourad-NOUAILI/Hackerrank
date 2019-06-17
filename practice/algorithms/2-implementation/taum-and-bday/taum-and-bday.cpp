#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int ULLI;
int main()
{
  unsigned short int nbCases;
  cin>>nbCases;
  
  while (nbCases--)
  {
    ULLI nbBlackGifts , nbWhiteGifts;
    cin>>nbBlackGifts>>nbWhiteGifts;
    
    ULLI costBlackGift , costWhiteGift , costExchange;
    cin>>costBlackGift>>costWhiteGift>>costExchange;
    
    cout<<nbBlackGifts * min(costBlackGift, costWhiteGift + costExchange) + nbWhiteGifts * min(costWhiteGift, costBlackGift+costExchange)<<'\n';
  }
  
  return 0;
}
   

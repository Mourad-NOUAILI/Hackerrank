#include <iostream>
#include <cctype>

using namespace std;

string encrypt(string msg , int len , int k)
{
  string cryptedMsg;
  for (int i = 0 ; i < len ; ++i)
  {
    char car = msg[i];
    if (isalpha(car))
    {
       bool isUpper = isupper(car);
      if (isUpper) car = tolower(car);
      char cryptedLetter = (( (int)car - 'a' + k) % 26) + 'a';
      if (isUpper) cryptedLetter = toupper(cryptedLetter);
      cryptedMsg.push_back(cryptedLetter);
    }
    else
      cryptedMsg.push_back(car);
  }
  return cryptedMsg;
}


int main()
{
  int N,K;
  string message;
  cin>>N;
  cin>>message;
  cin>>K;
  
  cout<<encrypt(message,N,K)<<'\n';
  
  return 0;
}

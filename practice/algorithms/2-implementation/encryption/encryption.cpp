#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void putIntoGrid(vector<vector<char> > & g , int & nbRows , int & nbColumns , string msg , int & len)
{
  len = msg.size();
  nbRows = floor(sqrt(len));
  nbColumns = ceil(sqrt(len));
  
  while (nbRows * nbColumns < len) nbRows++;
  
  for (int i = 1 ; i <= nbRows * nbColumns - len ;++i)
    msg.push_back('#');
  
  len = msg.size();
  nbRows = floor(sqrt(len));
  nbColumns = ceil(sqrt(len));
  
  //if (nbRows * nbColumns < len) nbColumns++;
  
  int iLen = 0;
  for (int iRow = 0 ; iRow < nbRows ; ++iRow)
  {
    vector<char> row;
    g.push_back(row);
    for (int iCol = 0; iCol < nbColumns ; ++iCol)
      g[iRow].push_back(msg[iLen++]);
  }
}

string displayCryptedMessage(vector<vector<char> > & g , int nbRows , int nbColumns)
{
  string cryptedMsg;
   for (int iCol = 0 ; iCol < nbColumns ; ++iCol)
  {
    for (int iRow = 0; iRow < nbRows ; ++iRow)
      if (g[iRow][iCol] != '#')
	cryptedMsg.push_back(g[iRow][iCol]);
    cryptedMsg.push_back(' ');
  }
  cryptedMsg.resize (cryptedMsg.size () - 1);
  return cryptedMsg;
  
}

void displayGrid(vector<vector<char> > & g , int nbRows , int nbColumns , int len)
{
  int iLen = 0;
   for (int iRow = 0; iRow < nbRows ; ++iRow)
  {
    if (iLen > len) return;
    for (int iCol = 0; iCol < nbColumns ; ++iCol)
    {
      cout<<g[iRow][iCol];
      iLen++;
    }
     cout<<'\n';
  }
  
}
  
int main()
{
  string message;
  cin>>message;
  
  vector<vector<char> > grid;
  int nbRows , nbColumns , len;
  putIntoGrid(grid, nbRows , nbColumns,message,len);
 // displayGrid(grid, nbRows , nbColumns,len);
  cout<<displayCryptedMessage(grid, nbRows , nbColumns)<<'\n';
  
  return 0;
}
/*ifmanwasmeanttostayonthegroundgodwouldhavegivenusroots*/

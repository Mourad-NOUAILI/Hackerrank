#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

struct cavityCoord
{
  int nRow;
  int nCol;
};

vector<cavityCoord> cavityList;

/*bool isOnBorder (int row, int col , int n)
{
return ((row < 0) || (row >= n) || (col < 0) || (col >= n));
} */

void fillTheMap (vector <vector<char> > & m , int n)
{
  for (int iRow = 0 ; iRow < n ; ++iRow)
  {
    m.push_back(vector <char> ());
    for (int iCol = 0 ; iCol < n ; ++iCol)
    {
      char depth;
      cin>>depth;
      assert(depth >= '1' && depth <= '9');
      m[iRow].push_back(depth);
    }
  }
}

void displayTheMap (vector <vector<char> > & m)
{
  int len = m.size() ;
  for (int iRow = 0 ; iRow < len ; ++iRow)
  {
    for (int iCol = 0 ; iCol < len ; ++iCol)
      cout<<m[iRow][iCol];
    cout<<'\n';
  }
}

void findCavities(vector <vector<char> > & m)
{
  cavityCoord cavities;
  int len = m.size();
   for (int iRow = 1 ; iRow < len-1 ; ++iRow)
  {
    for (int iCol = 1 ; iCol < len-1 ; ++iCol)
    {
      int curDepth = m[iRow][iCol] - '0';
      if (curDepth > m[iRow-1][iCol] - '0' && curDepth > m[iRow+1][iCol] - '0' && curDepth > m[iRow][iCol-1] - '0' && curDepth > m[iRow][iCol+1] - '0')
      {
	cavities.nRow = iRow;
	cavities.nCol = iCol;
	cavityList.push_back(cavities);
      }
    }
  }
}
    
int main()
{
  int mapSize;
  cin>>mapSize;
  
  assert(mapSize >= 1 && mapSize <= 100);
  
  vector <vector<char> > theMap;
  
  fillTheMap(theMap,mapSize);
  
  findCavities(theMap);
  
  for (unsigned int i = 0 ; i < cavityList.size() ; ++i)
    theMap[cavityList.at(i).nRow][cavityList.at(i).nCol] = 'X';
  
  displayTheMap(theMap);
  
  return 0;
}


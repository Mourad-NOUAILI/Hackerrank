//g++ -Wall -pedantic -std=c++11 matrix_rotation.cpp -o matrix_rotation

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ULLI;

void addLevel(vector< pair<int, int> > & l, int row, int col, int len, int rowAdd, int colAdd) {
    while(len-- > 0)
    {
        l.push_back(make_pair(row, col));
        row += rowAdd;
        col += colAdd;
    }
}

void rotate (vector< vector<ULLI> > & m , unsigned int nbRows , unsigned int nbCols , ULLI r , vector< vector<ULLI> > & result)
{
  unsigned int nbLevels = min(nbRows,nbCols) / 2;
  
  unsigned int lenCol = nbCols;
  unsigned int lenRow = nbRows;
  
  for (unsigned int iLevel = 0 ; iLevel < nbLevels ; ++iLevel)
  {
    vector< pair<int, int> > level;
    
    //Top level
    unsigned int row = iLevel , col = iLevel;
    addLevel(level , row , col , lenCol - 1 , 0 , 1);
    
    // Right level
    row = level.back().first;
    col = level.back().second + 1;
    addLevel(level , row , col , lenRow - 1 , 1 , 0);
    
    // Bottom level
    row = level.back().first + 1;
    col = level.back().second ;
    addLevel(level , row , col , lenCol - 1 , 0 , -1);
        
    // Left level
    row = level.back().first;
    col = level.back().second - 1;
    addLevel(level, row, col, lenRow - 1, -1, 0);

        // Checking
        
        /*for(auto x: level)
            cout<<'('<<x.first<<','<< x.second<<')';
        cout << endl;*/
        
	
        //rotate(level.begin(),level.begin()+(r%levelSize),level.end());
	
	int levelSize = level.size();
	for(int id = 0; id < levelSize; ++id)
	{
            unsigned int r1 = level[id].first , c1 = level[id].second;
            unsigned int r2 = level[(id+r)%levelSize].first, c2 = level[(id+r)%levelSize].second;
            result[r1][c1] = m[r2][c2];
        }
    
    lenRow -= 2;
    lenCol -= 2;
  }
  
}

void fillMatrix(vector< vector<ULLI> > & m , unsigned int nbRows , unsigned int nbCols)
{
  for (unsigned int iRow = 0 ; iRow < nbRows ; ++iRow)
    for (unsigned int iCol = 0 ; iCol < nbCols ; ++iCol)
    {
      cin>>m[iRow][iCol];
      assert(m[iRow][iCol] >= 1 && m[iRow][iCol] <= 100000000);
    }
}

void displayMatrix(vector< vector<ULLI> > & m , unsigned int nbRows , unsigned int nbCols)
{
  for (unsigned int iRow = 0 ; iRow < nbRows ; ++iRow)
  {
    for (unsigned int iCol = 0 ; iCol < nbCols ; ++iCol)
      cout<<m[iRow][iCol]<<' ';
    cout<<'\n';
  }
}

int main()
{
  unsigned int nbRows , nbCols , R;
  cin>>nbRows>>nbCols>>R;
  
  assert(nbRows >= 2);
  assert(nbCols <= 300);
  assert(min(nbRows,nbCols) % 2 == 0);
  assert(R >= 1 && R <= 1000000000);
  
  vector< vector<ULLI> > matrix(nbRows, vector<ULLI> (nbCols) );
  vector< vector<ULLI> > matrixResult(nbRows, vector<ULLI> (nbCols) );

  
  fillMatrix(matrix , nbRows , nbCols);
  rotate(matrix , nbRows , nbCols , R , matrixResult);
  displayMatrix(matrixResult , nbRows , nbCols);
  
  return 0;
}
  

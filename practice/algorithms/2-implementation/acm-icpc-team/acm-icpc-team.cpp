#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

typedef unsigned int UI;
const UI MAX_BITSET_SIZE = 500;

void fillMatrix(vector< bitset<MAX_BITSET_SIZE> > & t , UI nP , UI nT)
{
  for(UI iPeople = 0 ; iPeople < nP ; ++iPeople)
  {
   bitset<MAX_BITSET_SIZE> topic;
   cin>>topic;
   t.push_back(topic);
  }
}

/*void displayMatrix (vector< bitset<MAX_BITSET_SIZE> > & t, UI nP , UI nT)
{
  for (UI iRow = 0 ; iRow < nP ; ++iRow)
  {
      cout<<t[iRow];
    cout<<'\n';
  }
}*/

UI findMaxTopics (vector< bitset<MAX_BITSET_SIZE> > & t, UI nP , UI nT)
{
  UI maxKnownTopics = 0;
  for (UI iRow = 0 ; iRow < nP-1 ; ++iRow)
  {
    for (UI iRow1 = iRow+1 ; iRow1 < nP ; ++iRow1)
    {
      bitset<MAX_BITSET_SIZE> knownTopics = (t[iRow] | t[iRow1]);
      UI nbSetBits =  knownTopics.count();
      maxKnownTopics = max(maxKnownTopics,nbSetBits);
    }
  }
  return maxKnownTopics;
}

UI findTeams (vector< bitset<MAX_BITSET_SIZE> > & t, UI nP , UI nT , UI maxNbTopics)
{
  UI nbTeams = 0;
  for (UI iRow = 0 ; iRow < nP-1 ; ++iRow)
  {
    for (UI iRow1 = iRow+1 ; iRow1 < nP ; ++iRow1)
    {
      bitset<MAX_BITSET_SIZE> knownTopics = (t[iRow] | t[iRow1]);
      if (maxNbTopics == knownTopics.count()) nbTeams++; 
    }
  }
  return nbTeams;
}



int main()
{
  UI nbPeople , nbTopics;
  cin>>nbPeople>>nbTopics;
  
  vector<bitset<MAX_BITSET_SIZE> > topics;
  fillMatrix(topics,nbPeople,nbTopics);
 // displayMatrix(topics,nbPeople,nbTopics);
  UI maxNbTopics = findMaxTopics(topics,nbPeople,nbTopics);
  UI nb2PersonTeam = findTeams(topics,nbPeople,nbTopics,maxNbTopics);
  cout<<maxNbTopics<<'\n';
  cout<<nb2PersonTeam<<'\n';
  
  return 0;
}


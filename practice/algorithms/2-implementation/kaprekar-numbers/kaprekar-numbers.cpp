#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <climits>

using namespace std;
typedef unsigned long long int ULLI;

bool magic(ULLI nombre , int nbChiffres)
{
    ULLI carreNombre = pow(nombre,2);
    ULLI diviseur = 1;
    for (int compteur = 1 ; compteur <= nbChiffres ; compteur++)
        diviseur *= 10;

    ULLI nombreDroite = carreNombre % diviseur;
    ULLI nombreGauche = carreNombre / diviseur;

    return nombre == nombreDroite + nombreGauche;
}

int main()
{
  ULLI p,q;
  cin>>p;
  cin>>q;
  
  unsigned int nb = 0;
  for (ULLI nombre = p ; nombre <= q ; ++nombre)
    {
      ostringstream fluxSortie;
      fluxSortie<<nombre;
      string nombreStr = fluxSortie.str();
      if (magic(nombre,nombreStr.length()))
      {
	nb++;
	cout<<nombre<<' ';
      }
    }
    
    if (nb == 0) cout<<"INVALID RANGE"<<'\n';
    return 0;
}

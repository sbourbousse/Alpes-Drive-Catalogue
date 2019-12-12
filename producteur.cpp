#include "producteur.h"


Producteur::Producteur()
{

}

Producteur::Producteur(int unId, QString unNom, QString unPrenom)
{
   id=unId;
   nom=unNom;
   prenom=unPrenom;
}

int Producteur::getId()
{
    return id;
}

QString Producteur::getNomComplet()
{
    return prenom+" "+nom[0].toUpper()+".";
}


#include "pdf.h"

PDF::PDF()
{
    lesCategories = Passerelle::chargerLesCategories();


    QVector<Client> lesClients = Passerelle::chargerLesClients();

    for (int compteurClients = 0 ; compteurClients<lesClients.size() ; i++)
    {
        creerCatalogue(lesClients[compteurClients]);
    }
}

void PDF::creerCatalogue(Client unClient)
{
    QVector<Producteur> producteursDuClient = unClient.chargerProducteurs();
    QVector<Categorie> categorieDuClient;

    for(int i = 0 ; i<lesCategories.size() ; i++)
    {
        for(int j = 0 ; j<producteursDuClient.size() ; i++)
        {
            if(lesCategories[i].isEnVente(producteursDuClient[i]))
            {
                categorieDuClient.push_back(lesCategories[i]);
                categorieDuClient.last().chargerProduitDuClient(producteursDuClient);
            }
        }
    }

}

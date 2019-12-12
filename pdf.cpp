#include "pdf.h"
#include <QDebug>
#include<QPrinter>
#include <QTextDocument>

PDF::PDF()
{
    lesCategories = Passerelle::chargerLesCategories();


    lesClients = Passerelle::chargerLesClients();

    //PREMIER CLIENT DU VECTEUR
    //creerCatalogue(lesClients[0]);
}

bool PDF::creerCatalogue(Client unClient)
{
    //Nouvelle instance de QPrinter + parametrage
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("Catalogues/"+QString::number(unClient.getId())+".pdf");

    //Creer le document PDF Vierge "nomDocument"
    QTextDocument *leDocument = new QTextDocument;

    //On charge le(s) producteur(s) du  Client passé en paramêtre
    QVector<Producteur> producteursDuClient = unClient.chargerProducteurs();
    //On creer un vecteur de catégorie vide
    QVector<Categorie> categorieDuClient;

    bool categorieChargee;

    //Charger les catégories du client
    for (int i = 0 ; i<lesCategories.size() ; i++)
    {
        categorieDuClient.push_back(lesCategories[i]);
        categorieDuClient[i].chargerProduitDuClient(producteursDuClient);
    }

    QString contenu = "<html><head><meta charset=\"utf8\">"
                      "<style>body{}.test{padding-left:130px}.tableauVentes{border-width:1px;}.tableauVarietes td{}</style></head><body>";

    for(int i = 0; i<categorieDuClient.size() ; i++)
    {
        contenu+=categorieDuClient[i].afficherCategorie();
    }

    contenu += "</body></html>";

    qDebug()<<contenu;


    //J'ajoute mon contenue HTML a mon document
    leDocument->setHtml(contenu);

    //Je donne un format à la page et je l'exporte (dossier Debug par défaut)
    leDocument->setPageSize(printer.pageRect().size());
    leDocument->print(&printer);

    delete leDocument;

    /*if (! leDocument->begin()) { // failed to open file
          qWarning("failed to open file, is it writable?");
          return false;
      }
    else
        return true;*/ return true;

}

bool PDF::creerAllCatalogues()
{
    bool reussi=false;
    for (int compteurClients = 0 ; compteurClients<lesClients.size() ; compteurClients++)
    {
        if(creerCatalogue(lesClients[compteurClients]))
            reussi=true;
    }

    return reussi;
}



//Pour chaque producteur du client
/*for(int i = 0 ; i<producteursDuClient.size() ; i++)
{
    categorieChargee=false;
    //Pour chaque catégorie existante
    for(int j = 0 ; j<lesCategories.size() ; j++)
    {
        //si la catégorie est en vente chez le producteur du client
        if((lesCategories[j].isEnVente(producteursDuClient[i])) || (categorieChargee==false))
        {

            //Ajouter la catégorie au vecteur catégories du client
            categorieDuClient.push_back(lesCategories[j]);
            categorieChargee=true;

            /* Ici on appelle la procédure chargerProduitDuClient de la classe Catégorie,
             * cette procédure va changer la propriétés QVector<Produit> lesProduits de la classe Catégorie,
             * On chargera seulement les produits que les producteurs (passés en paramêtre) ont en vente.
             * Cette procédure appelera pour chaque produit une même procédure de la classe variété qui chargera
             * seulement les variétés mise en vente par un ou plusieurs des producteur passés en paramêtre
             *
            categorieDuClient.last().chargerProduitDuClient(producteursDuClient);

        }
    }
}*/

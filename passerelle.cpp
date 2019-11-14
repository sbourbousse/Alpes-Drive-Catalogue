#include "passerelle.h"
#include <QDebug>

QVector<Categorie> Passerelle::chargerLesCategories()
{
    QVector<Categorie> lesCategories;

    QString recupererLesCategories = "select categorieId,categorieLibelle,categorieImage from categorie where supprime=false";
    QSqlQuery requeteCategories(recupererLesCategories);
    qDebug()<<recupererLesCategories;

    while(requeteCategories.next())
    {
        lesCategories.push_back(Categorie(requeteCategories.value("categorieId").toInt(),
                                          requeteCategorie.value("categorieLibelle").toString(),
                                          requeteCategorie.value("categorieImage").toString(),
                                          chargerLesProduits(requeteCategories.value("categorieId").toInt())));
    }

    requeteCategories.clear();

    return lesCategories;
}

QVector<Produit> Passerelle::chargerLesProduits(int idCategorie)
{
    QVector<Produit> lesProduits;

    QString recupererLesProduits = "select produitId, produitLibelle, produitImage from produit where supprime=false and categorieId="+QString::number(idCategorie);

    QSqlQuery requeteProduits(recupereLesProduits);

    while(requeteProduits.next())
    {
        lesProduits.push_back(Produit(requeteProduits.value("produitId").toInt(),
                                      requeteProduits.value("produitLibelle").toString(),
                                      requeteProduits.value("produitImage").toString(),
                                      chargerLesVarietes(requeteProduits.value("produitId").toInt())));
    }

    requeteProduits.clear();

    return lesProduits;
}

QVector<Variete> Passerelle::chargerLesVarietes(int idProduit)
{
    QVector<Variete> lesVarietes;

    QString recupererLesVarietes = "select varieteId, varieteLibelle, uniteQuantiteVente, uniteLettre from variete natural join unite where supprimer=false and varieteId="+QString::number(idProduit);

    QSqlQuery requeteVarietes(recupererLesVarietes);

    while(requeteVarietes.next())
    {
        lesVarietes.push_back(Variete(requeteVarietes.value("varieteId").toInt(),
                                      requeteVarietes.value("varieteLibelle").toString(),
                                      equeteVarietes.value("uniteQuantiteVente").toInt(),
                                      equeteVarietes.value("uniteLettre").toString(),
                                      chargerLesVentes(requeteVarietes.value("varieteId").toInt())));
    }

    requeteVarietes.clear();

    return lesVarietes;
}

//Je devrais peut etre charger les vente dans producteur.cpp (en fonction producteur)
QVector<Vente> Passerelle::chargerLesVentes(int idVariete, int idProducteur)
{
    QVector<Vente> lesVentes;


    QString recupererLesVentes = "select venteId, prodId, prix, quantite, dateLimiteVente from vente where valide=true and varieteId="+QString::number(idVariete)+" and prodId="+QString::number(idProducteur);

    qDebug()<<recupererLesVentes;

    QSqlQuery requeteVentes(recupererLesVentes);

    while(requeteVentes.next())
    {      
        //Je récupère les informations du producteur qui propose la variété
        QString recupererProducteurVente="select prodId, prodPrenom, prodNom from producteur where supprimer=false and prodId="+recupererLesVentes.value("prodId").toString();
        qDebug()<<recupererProducteurVente;
        QSqlQuery requeteProducteurVente(recupererProducteurVente);


        requeteProducteurVente.first();

        Producteur monProducteur(requeteProducteurVente.value("prodId").toInt(),
                                 requeteProducteurVente.value("prodPrenom").toString(),
                                 requeteProducteurVente.value("prodNom").toString());


        lesVentes.push_back(Vente(recupererLesVentes.value("venteId").toInt(),
                                  monProducteur,
                                  requeteVentes.value("prix").toFloat(),
                                  requeteVentes.value("quantite").toInt(),
                                  requeteVentes.value("dateLimiteVente").toDate()));
    }

    requeteVentes.clear();

    return lesVentes;
}


QVector<Client> Passerelle::chargerLesClients()
{
    QVector<Client> lesClients;

    QString recupererLesClients = "select clientId, clientNom, clientPrenom from client where supprime=false";

    QDebug()<<recupererLesClients;

    QSqlQuery requeteClients(recupererLesClients);

    while(requeteClients.next())
    {
        lesClients.push_back(Client(requeteClients.value("clientId").toInt(),
                                    requeteClients.value("clientNom").toString(),
                                    requeteClients.value("clientPrenom").toString()));
    }

    requeteClients.clear();

    return lesClients;
}


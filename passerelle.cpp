#include "passerelle.h"
#include <QDebug>

QVector<Categorie> Passerelle::chargerLesCategories()
{
    QVector<Categorie> lesCategories;

    QString recupererLesCategories = "select categorieId,categorieLibelle,categorieImage from categorie";
    QSqlQuery requeteCategories(recupererLesCategories);
    qDebug()<<recupererLesCategories;

    while(requeteCategories.next())
    {
        lesCategories.push_back(Categorie(requeteCategories.value("categorieId").toInt(),
                                          requeteCategories.value("categorieLibelle").toString(),
                                          requeteCategories.value("categorieImage").toString(),
                                          chargerLesProduits(requeteCategories.value("categorieId").toInt())));
    }

    requeteCategories.clear();

    return lesCategories;
}

QVector<Produit> Passerelle::chargerLesProduits(int idCategorie)
{
    QVector<Produit> lesProduits;

    QString recupererLesProduits = "select produitId, produitLibelle, produitImage from produit where categorieId="+QString::number(idCategorie);

    QSqlQuery requeteProduits(recupererLesProduits);
    qDebug()<<recupererLesProduits;

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

    QString recupererLesVarietes = "select varieteId, varieteLibelle, uniteQuantiteVente, uniteLettre from variete natural join produit natural join unite where produitId="+QString::number(idProduit);

    QSqlQuery requeteVarietes(recupererLesVarietes);
    qDebug()<<recupererLesVarietes;

    while(requeteVarietes.next())
    {
        lesVarietes.push_back(Variete(requeteVarietes.value("varieteId").toInt(),
                                      requeteVarietes.value("varieteLibelle").toString(),
                                      requeteVarietes.value("uniteQuantiteVente").toInt(),
                                      requeteVarietes.value("uniteLettre").toString(),
                                      chargerLesVentes(requeteVarietes.value("varieteId").toInt())));
    }

    requeteVarietes.clear();

    return lesVarietes;
}

//Je devrais peut etre charger les vente dans producteur.cpp (en fonction producteur)
QVector<Vente> Passerelle::chargerLesVentes(int idVariete)
{
    QVector<Vente> lesVentes;


    QString recupererLesVentes = "select venteId, prodId, prix, quantite, dateLimiteVente from vente where valide=true and varieteId="+QString::number(idVariete);

    qDebug()<<recupererLesVentes;

    QSqlQuery requeteVentes(recupererLesVentes);

    while(requeteVentes.next())
    {      
        //Je récupère les informations du producteur qui propose la variété
        QString recupererProducteurVente="select prodId, prodPrenom, prodNom from producteur where supprime=false and prodId="+requeteVentes.value("prodId").toString();
        qDebug()<<recupererProducteurVente;
        QSqlQuery requeteProducteurVente(recupererProducteurVente);


        requeteProducteurVente.first();

        Producteur monProducteur(requeteProducteurVente.value("prodId").toInt(),
                                 requeteProducteurVente.value("prodPrenom").toString(),
                                 requeteProducteurVente.value("prodNom").toString());


        lesVentes.push_back(Vente(requeteVentes.value("venteId").toInt(),
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

    qDebug()<<recupererLesClients;

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


#ifndef PASSERELLE_H
#define PASSERELLE_H

#include <QSqlQuery>
#include <QVector>
#include <categorie.h>
#include <produit.h>
#include <variete.h>
#include <client.h>


class Passerelle
{
public:
    static QVector<Categorie> chargerLesCategories();
    static QVector<Produit> chargerLesProduits(int idCategorie);
    static QVector<Variete> chargerLesVarietes(int idProduit);
    static QVector<Vente> chargerLesVentes(int idVariete);
    static QVector<Client> chargerLesClients();
};

#endif // PASSERELLE_H

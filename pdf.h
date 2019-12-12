#ifndef PDF_H
#define PDF_H

#include "client.h"
#include "passerelle.h"
#include "categorie.h"
#include <QVector>


class PDF
{
private:
    QVector<Categorie> lesCategories;
    QVector<Client> lesClients;

public:
    PDF();
    bool creerCatalogue(Client unClient);
    bool creerAllCatalogues();
};

#endif // PDF_H

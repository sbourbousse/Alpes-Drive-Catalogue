#ifndef PDF_H
#define PDF_H

#include "client.h"
#include "passerelle.h"
#include "categorie.h"
#include <QVector>


class PDF
{
private:
    Categorie lesCategories;
public:
    PDF();
    void creerCatalogue(Client unClient);
};

#endif // PDF_H

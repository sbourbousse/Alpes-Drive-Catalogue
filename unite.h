#ifndef UNITE_H
#define UNITE_H

#include <QString>

class Unite
{
private:
    int id;
    QString libelle;
    QString lettre;
    int quantiteVente;
public:
    Unite(int unId, QString unLibelle, QString uneLettre, int uneQuantiteVente);
};

#endif // UNITE_H

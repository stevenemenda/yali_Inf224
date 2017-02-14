#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <iostream>
using namespace std;    //?? Comme <string>and<iostream> are defined in namespace std => il faut "using namespace std" ?
class Multimedia{
private:
    string nom;
    string nomFichier; //PATHNAME of the multimedia document
public:
    Multimedia(const string & strNom, const string & strFichier);
    Multimedia();
//    //destructeur
    virtual ~Multimedia();  //?????
    //les getters
    virtual string getNom() const;
    virtual string getNomFichier() const;
    //les setters
    virtual void setNom(string newNom);
    virtual void setNomFichier(string newNomFichier);
    //une méthode d'affichage
    virtual void print(ostream & os) const;
    virtual void play()=0;    //etape4: méthode abstraite
};

#endif // MULTIMEDIA_H

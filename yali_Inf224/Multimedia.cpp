#include"Multimedia.h"
using namespace std;

Multimedia::Multimedia(const string & strNom, const string & strFichier){
    nom = strNom;
    nomFichier = strFichier;
}
Multimedia::Multimedia(){
    cout << "Constructor without parameter"<<endl;
}
Multimedia::~Multimedia(){
    cout <<"\t!"<<"\t"<< "deconstructor of multimedia" << endl;
}
string Multimedia::getNom() const{
    return nom;
}
string Multimedia::getNomFichier() const{
    return nomFichier;
}
void Multimedia::setNom(string newNom){
    nom = newNom;
}
void Multimedia::setNomFichier(string newNomFichier){
    nomFichier = newNomFichier;
}
/* une méthode d'affichage */
void Multimedia::print(ostream& os) const{
    os <<"\t"<< "Nom:" <<"\t"<< nom << endl;
    os <<"\t"<< "Address:" <<"\t"<< &nom << endl;
    os << "\t"<< "Nom du fichier:" <<"\t"<< nomFichier <<endl;
}
/**<test of documentation.
 */
void Multimedia::play(){}

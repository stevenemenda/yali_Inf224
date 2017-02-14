#include"video.h"
using namespace std;

Video::Video(string strNom, string strFichier, unsigned int lastTime){
    Multimedia::Multimedia(strNom, strFichier);
    duree = lastTime;
}
Video::getDuree() const{
    return duree;
}
Video::setDuree(unsigned int newDuree) {duree = newDuree;}
Video::print(ostream &os) const{
    Multimedia::print(os);  //Attention! constructor
    os<<"\t"<< "Duree:" <<"\t"<< duree<<endl;
}
Video::play(){
    string str = "mpv " + Multimedia::getNomFichier() + "/" + Multimedia::getNom() + " &";
    const char * c = str.c_str();
    cout<<c<<endl;
    system(c);
}

#ifndef VIDEO_H
#define VIDEO_H
#include "Multimedia.h"
#include <unistd.h>
class Video : public Multimedia{
private:
    unsigned int duree;
public:
    Video(string strNom=NULL, string strFichier=NULL, unsigned int lastTime=0) : Multimedia(strNom, strFichier),duree(lastTime){} //call the constructor of Multimedia
    virtual unsigned int getDuree() const{return duree;}
    virtual void setDuree(unsigned int newDuree) {duree = newDuree;}
    virtual void print(ostream& os) const{
        Multimedia::print(os);  //Attention! constructor
        os<<"\t"<< "Duree:" <<"\t"<< duree<<endl;
    }
    virtual void play(){
        string str = "mpv " + Multimedia::getNomFichier() + "/" + Multimedia::getNom() + " &";
        const char * c = str.c_str();
        //cout<<c<<endl;
        system(c);
    }
    virtual ~Video(){
        cout <<"\t!"<<"\t"<< "deconstructor of Video" << endl;
    };
};

#endif // VIDEO_H

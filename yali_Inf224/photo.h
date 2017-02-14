#ifndef PHOTO_H
#define PHOTO_H
#include "Multimedia.h"
class Photo : public Multimedia{
private:
    float latitude;
    float longitude;
public:
    Photo(string strNom=NULL,string strFichier=NULL,float lati=0,float longi=0):Multimedia(strNom, strFichier),latitude(lati),longitude(longi){}
    virtual float getLatitude() const{return latitude;}
    virtual float getLongitude() const{return longitude;}
    virtual void setLatitude(float newLati){latitude = newLati;}
    virtual void setLongitude(float newLongi){longitude = newLongi;}
    virtual void print(ostream &os) const{
        Multimedia::print(os);
        os<<"\t"<< "Latitude:" <<"\t"<<latitude<<endl;
        os<<"\t"<< "Longitude:" <<"\t"<<longitude<<endl;
    }
    virtual void play(){
        string str = "imagej " + Multimedia::getNomFichier() + "/" + Multimedia::getNom() + " &";
        const char * c = str.c_str();
        cout<<c<<endl;
        system(c);
    }
    virtual ~Photo(){
        cout <<"\t!"<<"\t"<< "deconstructor of Photo" << endl;
    };
};
#endif // PHOTO_H

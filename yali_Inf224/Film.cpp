#include"Film.h"
using namespace std;

Film::Film(string strNom=NULL, string strFichier=NULL, unsigned int lastTime=0, unsigned int ch=0, unsigned int * duree_ch=nullptr) : Video(strNom,strFichier,lastTime),chapter(ch),array_duree(duree_ch){}
/* 7e Etape: copie des objets */
Film::Film(const Film &film): Video(film){  //1st:heritage of the father class
    chapter = film.chapter;                 //2nd:copy those instences non-ptr
                                            //3rd:copy those ptrs
    if(film.array_duree) array_duree = new unsigned int(* film.array_duree);
    else array_duree = nullptr;
}
Film & Film::operator=(const Film & film){
    Video::operator=(film);             //1st:heritage of the father class
    chapter = film.chapter;             //2nd:copy those instences non-ptr
                                        //3rd:copy those ptrs
    if(array_duree&&film.array_duree){
        *array_duree = *film.array_duree;   //if array_duree is not nullptr, then cope ce que dans le film.array_duree into array_duree
    }
    else{
        delete array_duree;                 //si non, the new address will cover the old adress, and we cannot clear ce que dans le old address anymore, which lead to the "fuite memoire"
        if(film.array_duree) array_duree = new unsigned int(* film.array_duree);
        else array_duree = nullptr;
    }
    return *this;                       //Here we need a return value parce que the operator= is a function which gives its return value to the variable in front of "="
}
/* End 7e Etape */
unsigned int Film::getChapterNumber() const{return chapter;}
unsigned int * Film::getArrayDuree() const{return array_duree;}
void Film::setArrayDuree(unsigned int *newArrayDuree){
    for(unsigned int k = 0; k < chapter; ++k){
        array_duree[k]=newArrayDuree[k];
    }
}
void Film::print(ostream &os) const{
    Video::print(os);
    os <<"\t"<< "Les durees de chaque chapitre : " << endl;
    for(unsigned int k = 0; k < chapter; ++k){
        os <<"\t"<< array_duree[k] <<endl;
    }
    os << endl;
}
Film::~Film(){
    cout <<"\t!"<<"\t"<< "deconstructor of Film" << endl;
    delete array_duree;
}

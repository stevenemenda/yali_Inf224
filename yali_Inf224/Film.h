#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video{
private:
    unsigned int chapter;   //The number of chapters contained in a Film
    unsigned int * array_duree;  //The table of films, length = chapter
    //Wrong: int array_duree[chapter]  because chapter doesn't have a value now
public:
    Film(string strNom, string strFichier, unsigned int lastTime, unsigned int ch, unsigned int * duree_ch);
    /* 7e Etape: copie des objets */
    Film(const Film & film);
    virtual Film & operator=(const Film & film);
    virtual unsigned int getChapterNumber()const;
    virtual unsigned int* getArrayDuree()const;
    virtual void setArrayDuree(unsigned int *newArrayDuree);
    virtual void print(ostream &os) const;
    virtual ~Film();
};
#endif // FILM_H

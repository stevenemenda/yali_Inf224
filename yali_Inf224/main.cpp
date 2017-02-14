#include"Multimedia.h"
#include"video.h"
#include"photo.h"
#include"Film.h"
#include"group.h"
#include <unistd.h>
#include<string>
using namespace std;

int main(){
    /* Test of Multimedia */
//    string path(getcwd(NULL,0));
//    Multimedia * multimedia = new Multimedia("SampleVideo.mp4",path);
//    multimedia->print(cout);
//    multimedia->setNom("newName");
//    multimedia->print(cout);

//    Multimedia * multimedia = new Multimedia("SampleVideo.mp4",path);
//    video -> print(cout);
    /*4e étape*/
    cout<<"4e Etape: Photos et videos"<<endl;
//    get the chemin of the fichier
    string path(getcwd(NULL,0));
    Video * video = new Video("SampleVideo.mp4",path,10);
    video -> print(cout);
//    video -> play();
    delete video;
//    video = NULL;
//    /* test of deconstructor */
//    video -> print(cout);
    Photo * photo = new Photo("psb.jpg",path,10,10);
    photo -> print(cout);
//    photo -> play();
    photo -> setNom("NewName");
    photo -> print(cout);
    delete photo;

    /* 5e Etape: Traitement générique */
    /*not use any function here
    unsigned int length = 5;
    Multimedia ** multimedias = new Multimedia *[length];    //table of 5 multimedias
    unsigned int count = 0;
    multimedias[count++] = new Video("SampleVideo2.mp4", "", 5);
    multimedias[count++] = new Photo("photo1.jpg","",275,183);
    multimedias[count++] = new Photo("photo2.jpg", "", 225,224);
    multimedias[count++] = new Video("SampleVideo3.mp4", "", 13);
    multimedias[count++] = new Photo("photo3.jpg","",275,183);
    for(unsigned int k = 0; k < length; ++k){
        multimedias[k] -> print(cout);
    }*/
    cout<<"\n\n5e Etape: Traitement generique"<<endl;
    void table();
    table();

    /* 6e Etape: Films et tableaux */
    cout<<"\n\n6e Etape: Films et tableaux"<<endl;
    unsigned int num = 3;
    unsigned int *ary =new unsigned int [num];
    ary[0] = 5, ary[1] = 4, ary[2] = 4;
    Film * film = new Film("SampleVideo3.mp4", "", 13,num,ary);
    film -> print(cout);

    /* 7e Etape: Destruction et copie des objets */
    cout<<"\n\n7e Etape: Destruction et copie des objets"<<endl;
    cout<<"\ntest of copie des objets:"<<endl;
    cout<<"\t"<<"Address of the array \"array_duree\" of \"film\" : "<<film->getArrayDuree()<<endl;
    Film * film2 = new Film(*film);
    cout<<"\t"<<"Address of the array \"array_duree\" of \"film2\": "<< film2->getArrayDuree()<<endl;
    //film2->print(cout);
    delete film2;

    cout<<"\ntest of the destruction of objets:"<<endl;
    unsigned int * p = nullptr; //to save the array duree of object film
    p = film->getArrayDuree();
    cout<<"\t"<<"Address of the array \"array_duree\" of \"film\" : "<<p<<endl;
    cout<<"\t"<<*p<<endl;
    cout<<"\t"<<"The object film has been deleted:"<<endl;
    delete film;
    cout<<"\t"<<"Address of the array \"array_duree\" of \"film\" : "<<p<<endl;
    cout<<"\t"<<*p<<"\n"<<endl;

    /* 8e Etape: Créer des groupes */
    Group<Multimedia *> * group1 = new Group<Multimedia *>("Group1");
    group1->push_back(new Video("SampleVideo2.mp4", "", 5));
    group1->push_back(new Photo("photo1.jpg","",275,183));
    group1->push_back(new Video("SampleVideo3.mp4", "", 13));

}

/* [5e étape] To print the name and path of each file in a table */
void printMultimedias(Multimedia **multi, unsigned int length){
    for(unsigned int k = 0; k < length; ++k){
        cout<<"Multimedia "<<k<<":"<<endl;
        multi[k] -> print(cout);
        cout<<endl;
    }
}

/* [5e étape] To generate a table of Multimedias  */
void table(){
    unsigned int length = 5;
    Multimedia ** multimedias = new Multimedia *[length];    //table of 5 multimedias
    unsigned int count = 0;
    string path(getcwd(NULL,0));
    //declare function
    void printMultimedias(Multimedia **multi, unsigned int length);
    multimedias[count++] = new Video("SampleVideo2.mp4", path, 5);
    multimedias[count++] = new Photo("photo1.jpg",path,275,183);
    multimedias[count++] = new Photo("photo2.jpg", path, 225,224);
    multimedias[count++] = new Video("SampleVideo3.mp4", path, 13);
    multimedias[count++] = new Photo("photo3.jpg",path,275,183);
    printMultimedias(multimedias,length);
    delete [] multimedias;
}

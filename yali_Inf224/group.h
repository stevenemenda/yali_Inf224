#ifndef GROUP_H
#define GROUP_H
#include <list>
#include <iostream>
using namespace std;

template <typename T>
class Group:public list<T>{
private:
    string nomGroup;
public:
    //Constructor
    Group(string groupName = NULL){
        groupName = nomGroup;
    }
    //getter
    virtual string getGroupName() const{
        return nomGroup;
    }
    //print
    virtual void print(ostream & os) const{
        for (auto it : *this) it->print(os);
    }
    //distructor
    virtual ~Group(){
    }
};
#endif // GROUP_H

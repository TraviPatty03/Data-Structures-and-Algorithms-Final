#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

#ifndef UNTITLED_SUBJECT_H
#define UNTITLED_SUBJECT_H


class Subject {
public:
    Subject();

    //location
    int cord_x;
    int cord_y;

    //value
    double cost;
    int weight = 1;
    double value;

    //name to tell which subject is which after sorting
    int name;
};


#endif //UNTITLED_SUBJECT_H

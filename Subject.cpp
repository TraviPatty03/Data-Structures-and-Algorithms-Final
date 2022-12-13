//
// Created by travis on 12/8/22.
//

#include "Subject.h"

Subject::Subject() {
    cord_x = 0;
    cord_y = 0;

    cost = 0;

    weight = 1;
    HasBeen = false;
};

void Subject::SetSubjectValues() {
    //randomly sets coordinates
    cord_x = (rand() % 100) + 1;
    cord_y = (rand() % 100) + 1;

    if (cord_x < 50 && cord_y < 50) {
        cost = 0.5; //Super Poor District
    } else if (cord_x < 50 && cord_y >= 50) {
        cost = 1; //Not-so poor District
    } else if (cord_x >= 50 && cord_y < 50) {
        cost = 1.5; // Middle District
    } else if (cord_x >= 50 && cord_y >= 50) {
        cost = 2; //Rich District
    } else {
        cout << "ERROR" << endl;
    }
}
#include "Subject.h"
#include "Functions.h"

using namespace std;

int main() {
    //sets time seed
    srand(time(nullptr));

    //constants. These are just values given by professor
    int size = 100;
    double budget = 10;

    //Array of subjects to allow for easier loops
    Subject *sub = new Subject[size];
    Subject *best = new Subject[size];
    Subject *greedy = new Subject[size];

    //Gets the values not set in the constructor
    makeWeight(sub, size);
    setValues(sub, size);

    //grabs the most valuable from sorted array and makes sure that one subject is not close to another
    MostValuable(sub, best, budget, size);

    //prints Subject Name, Cost, and value
    cout << "-----My Algorithm------" << endl;
    printArray(best, size);

    //Creates greedy sort
    Greedy(sub, greedy, budget, size);

    cout << "----Greedy Algorithm---" << endl;
    printArray(greedy, size);

    //deletes the arrays in the heap
    delete[] sub;
    delete[] best;
    delete[] greedy;

    return 0;
}
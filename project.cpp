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
    Subject *random = new Subject[size];

    //Gets the values not set in the constructor
    setValues(sub, size);

    //grabs the most valuable from sorted array and makes sure that one subject is not close to another
    MostValuable(sub, best, budget, size);

    //Do this first just because it's before all sorting so it's more random
    Random(sub, random, budget, size);

    //prints Subject Name, Cost, and value
    cout << "-----My Algorithm------" << endl;
    cout << "The total Value is: " << totalValue(best, size) << endl;
    cout << "The total Cost is: " << totalCost(best, size) << endl;
    cout << "The level of coverage is: " << LevelOfCoverage(best, size) << "%" << endl;

    //Creates greedy sort
    Greedy(sub, greedy, budget, size);

    cout << "----Greedy Algorithm---" << endl;
    cout << "The total Value is: " << totalValue(greedy, size) << endl;
    cout << "The total Cost is: " << totalCost(greedy, size) << endl;
    cout << "The level of coverage is: " << LevelOfCoverage(greedy, size) << "%" << endl;

    cout << "---Random Algorithm----" << endl;
    cout << "The total Value is: " << totalValue(random, size) << endl;
    cout << "The total Cost is: " << totalCost(random, size) << endl;
    cout << "The level of coverage is: " << LevelOfCoverage(random, size) << "%" << endl;

    //deletes the arrays in the heap
    delete[] sub;
    delete[] best;
    delete[] greedy;
    delete[] random;

    return 0;
}
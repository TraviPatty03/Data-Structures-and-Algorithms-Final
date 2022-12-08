#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

class Subject {
public:
    Subject() {
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
    };

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

//prints the array
void printArray(Subject *sub, int size);

//determine weight of each subject
void makeWeight(Subject sub[], int size);

//sets value of subject
void setValues(Subject sub[], int size);

//creates a new array of most important subject
void MostValuable(Subject sub[], Subject data[], double budget, int size);

//sort array
int partition(Subject arr[], int start, int end);
void quickSort(Subject arr[], int start, int end);


int main() {
    //sets time seed
    srand(time(nullptr));

    //constants. These are just values given by professor
    int size = 100;
    double budget = 10;

    //Array of subjects to allow for easier loops
    Subject *sub = new Subject[size];
    Subject *data = new Subject[size];

    //Gets the values not set in the constructor
    makeWeight(sub, size);
    setValues(sub, size);

    //quick sort algorithm that sorts by value
    quickSort(sub, 0, size - 1);

    //grabs the most valueable from sorted array and makes sure that one subject is not close to another
    MostValuable(sub, data, budget, size);

    //prints Subject Name, Cost, and value
    printArray(data, size);

    //deletes the arrays in the heap
    delete[] sub;
    delete[] data;

    return 0;
}

void printArray(Subject sub[], int size) {
    //print coordinates
    for (int i = 0; i <= size - 1; i++) {
        if (sub[i].value != 0) { //This is mainly for the second array where the array is not filled up
            cout << "Subject " << sub[i].name << endl;
            cout << "Cost - " << sub[i].cost << endl;
            cout << "value - " << sub[i].value << endl;
            cout << endl;
        }
    }
}

void setValues(Subject sub[], int size) {
    for (int i = 0; i <= size - 1; i++) {
        //the value is determined by the weight divided by cost to make sur you get the most bang for your buck
        //the weight is casted as a double since it is instantiated as an int
        sub[i].value = ((double) sub[i].weight / sub[i].cost);
        sub[i].name = i;
    }
}

void MostValuable(Subject sub[], Subject data[], double budget, int size) {
    int x = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (budget <= 0) {
            break;
        }
        //the sqrt equation is the distance equation for a circle, if it is less than 4 that means the circles overlap
        //this is to insure that two subjects are not taken if they are to close together
        if (sqrt(pow(sub[i].cord_x - data[x].cord_x, 2) + pow(sub[i].cord_y - data[x].cord_y, 2) < 4)){
            continue;
        }
        data[x] = sub[i];
        budget -= sub[i].cost;
        x++;
    }
}

void makeWeight(Subject sub[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            //this is to make sure it does not add weight because of itself
            if (i == j) {
                continue;
            }
            //the sqrt equation is the distance equation for a circle, if it is less that 4 that means the circles overlap
            if (sqrt(pow(sub[i].cord_x - sub[j].cord_x, 2) + pow(sub[i].cord_y - sub[j].cord_y, 2)) < 4) {
                sub[i].weight++;
            }
        }
    }
}

int partition(Subject arr[], int start, int end) {

    int pivot = arr[start].value;

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i].value <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i].value <= pivot) {
            i++;
        }

        while (arr[j].value > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(Subject arr[], int start, int end) {

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}
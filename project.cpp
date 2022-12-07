#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

class Subject {
public:
    Subject() {
        cord_x = (rand() % 100) + 1;
        cord_y = (rand() % 100) + 1;

        if (cord_x < 50 && cord_y < 50) {
            cost = 0.5; //Super Poor District
        } else if (cord_x < 50 && cord_y >= 50) {
            cost = 1; //Not-so poor District
        } else if (cord_x >= 50 && cord_y < 50) {
            cost = 1.5; // Middle District
        } else if (cord_x >= 50 && cord_y >= 50) {
            cost = 2; //Rich ass motherfuckers
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
    int name;

private:
};

void printArray(Subject *sub, int size);

//determine weight of each subject
void makeWeight(Subject sub[], int size);

//sets value of subject
void setValues(Subject sub[], int size);

//creates a new array of most important subject
void MostValuable(Subject sub[], Subject data[], int budget, int size);

//sort array
int partition(Subject arr[], int start, int end);

void quickSort(Subject arr[], int start, int end);


int main() {
    srand(time(nullptr));
    int size = 100;
    int budget = 10;

    Subject *sub = new Subject[size];
    Subject *data = new Subject[size];

    makeWeight(sub, size);
    setValues(sub, size);

    quickSort(sub, 0, size - 1);

    MostValuable(sub, data, budget, size);

    printArray(data, size);

    delete[] sub;
    return 0;
}

void printArray(Subject sub[], int size) {
    //print coordinates
    for (int i = 0; i <= size - 1; i++) {
        if (sub[i].value != 0) {
            cout << "Subject " << sub[i].name << endl;
            cout << "Cost - " << sub[i].cost << endl;
            cout << "value - " << sub[i].value << endl;
        }
    }
}

void setValues(Subject sub[], int size) {
    for (int i = 0; i <= size - 1; i++) {
        sub[i].value = ((double) sub[i].weight / sub[i].cost);
        sub[i].name = i;
    }
}

void MostValuable(Subject sub[], Subject data[], int budget, int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (budget <= 0) {
            break;
        }
        data[size - 1 - i] = sub[i];
        budget -= sub[i].cost;
    }
}

void makeWeight(Subject sub[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j)
                continue;

            int distance = sqrt(pow(sub[i].cord_x - sub[j].cord_x, 2) + pow(sub[i].cord_y - sub[j].cord_y, 2));
            if (distance <= 4) {
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
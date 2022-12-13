#include "Subject.h"
#include "Functions.h"

using namespace std;


void printArray(Subject sub[], int size) {
    //print coordinates
    cout << "Called" << endl;
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
        sub[i].SetSubjectValues();
    }
    makeWeight(sub, size);
    for (int i = 0; i <= size - 1; i++) {
        //the value is determined by the weight divided by cost to make sur you get the most bang for your buck
        //the weight is casted as a double since it is instantiated as an int
        sub[i].value = ((double) sub[i].weight * sub[i].cost);
        sub[i].name = i;
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

double totalValue(Subject sub[], int size) {
    double x = 0;
    for (int i = 0; i <= size - 1; i++) {
        x += sub[i].value;
    }
    return x;
}

double totalCost(Subject sub[], int size) {
    double x = 0;
    for (int i = 0; i <= size - 1; i++) {
        x += sub[i].cost;
    }
    return x;
}

double LevelOfCoverage(Subject arr[], int size) {
    double LOC = 0;
    double PI = 3.14;
    for (int i = 0; i <= size - 1; i++) {
        if (arr[i].cost > 0) {
            LOC += PI * 4;
        }
    }
    return LOC;
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

void MostValuable(Subject sub[], Subject data[], double budget, int size) {
    quickSort(sub, 0, size - 1);
    int x = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (budget <= 0) {
            break;
        }
        //the sqrt equation is the distance equation for a circle, if it is less than 4 that means the circles overlap
        //this is to insure that two subjects are not taken if they are to close together
        if (sqrt(pow(sub[i].cord_x - data[x].cord_x, 2) + pow(sub[i].cord_y - data[x].cord_y, 2) < 4)) {
            continue;
        }
        if (budget - sub[i].cost >= 0) {
            data[x] = sub[i];
            budget -= sub[i].cost;
            x++;
        } else {
            continue;
        }
    }
}

int Greedy_partition(Subject arr[], int start, int end) {

    int pivot = arr[start].cost;

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i].cost <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i].cost <= pivot) {
            i++;
        }

        while (arr[j].cost > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void Greedy_quickSort(Subject arr[], int start, int end) {

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = Greedy_partition(arr, start, end);

    // Sorting the left part
    Greedy_quickSort(arr, start, p - 1);

    // Sorting the right part
    Greedy_quickSort(arr, p + 1, end);
}

//this is for case Greedy
void Greedy(Subject sub[], Subject data[], double budget, int size) {
    int x = 0;
    Greedy_quickSort(sub, 0, size - 1);
    for (int i = 0; i <= size - 1; i++) {
        if (budget - sub[i].cost > 0) {
            data[x] = sub[i];
            budget -= sub[i].cost;
            x++;
        }
    }
}

void Random(Subject sub[], Subject arr[], double budget, int size) {
    int i = 0;
    while (true) {
        int x = rand() % size;
        if (!sub[x].HasBeen && budget - sub[x].cost >= 0) {
            arr[i] = sub[x];
            i++;
            budget -= sub[x].cost;
            sub[x].HasBeen = true;
        } else if (budget - sub[x].cost < 0) {
            break;
        }
    }
}
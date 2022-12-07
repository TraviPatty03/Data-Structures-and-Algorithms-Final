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

        if(cord_x < 50 && cord_y < 50){
            cost = 0.5; //Super Poor District
        }
        else if(cord_x < 50 && cord_y >= 50){
            cost = 1; //Not-so poor District
        }
        else if(cord_x >= 50 && cord_y < 50){
            cost = 1.5; // Middle District
        }
        else if(cord_x >= 50 && cord_y >= 50){
            cost = 2; //Rich ass motherfuckers
        }
        else{
            cout << "ERROR" << endl;
        }
    };

    //location
    int cord_x ;
    int cord_y ;

    //value
    double cost;
    int weight = 1;
    double value = weight / cost;

private:
};

void printArray(Subject* sub, int size);

//determine weight of each subject
void makeWeight(Subject sub[], int size);

//sort array
void heapify(Subject arr[], int N, int i);
void heapSort(Subject arr[], int N);

int main() {
    srand(time(nullptr));
    int size = 100;

    Subject* sub = new Subject[size];

    makeWeight(sub, size);

    heapSort(sub, size);

    printArray(sub, size);

    delete [] sub;
    return 0;
}

void printArray(Subject sub[], int size){
    //print coordinates
    for (int i = 0; i <= size - 1; i++) {
        cout << i << ": weight - " << sub[i].weight << endl;
    }
}

void makeWeight(Subject sub[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j)
                continue;

            int distance = sqrt(pow(sub[i].cord_x - sub[j].cord_x, 2) + pow(sub[i].cord_y - sub[j].cord_y, 2));
            if(distance <= 4){
                sub[i].weight++;
            }
        }
    }
}

void heapify(Subject arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l].value > arr[largest].value)
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r].value > arr[largest].value)
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(Subject arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
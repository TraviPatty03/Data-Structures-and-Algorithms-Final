#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

#include "Subject.h"

using namespace std;

void printArray(Subject sub[], int size);

void setValues(Subject sub[], int size);

void makeWeight(Subject sub[], int size);

double totalValue(Subject sub[], int size);

int partition(Subject arr[], int start, int end);

void quickSort(Subject arr[], int start, int end);

void MostValuable(Subject sub[], Subject data[], double budget, int size);

int Greedy_partition(Subject arr[], int start, int end);

void Greedy_quickSort(Subject arr[], int start, int end);

void Greedy(Subject sub[], Subject data[], double budget, int size);

void Random(Subject sub[], Subject arr[], double budget, int size);
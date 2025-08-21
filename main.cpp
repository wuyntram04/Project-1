// Name: Tram Ho
// Date: 8/29/24
// Description: Chapter 9

#include<iostream>
#include "input.h"
#include <string>
#include <iomanip>
using namespace std;

void challenge3();
void selectionSort(double[], int);
void swap(double&, double&);

void challenge6();
void arrSelectionSortAscending(int*, int);

void challenge7();
void arrSelectionSortDescending(int*, int);

void challenge9();
double median(int*, int );

void challenge10();
int* arrReverse(int*, int);

void challenge11();
int* arrExpand(int*, int);

void challenge12();
int* arrShifted(int*, int);

int main()
{
    do
    {
        system("cls");
        cout << "\n\tCMPR121: Chapter 9 Pointer - assignments by Tram Ho";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 3. Drop the Lowest Score";
        cout << "\n\t 6. Case Study Modification #1";
        cout << "\n\t 7. Case Study Modification #2";
        cout << "\n\t 9. Median Function";
        cout << "\n\t10. Reverse Array";
        cout << "\n\t11. Array Expander";
        cout << "\n\t12. Element Shifter";

        cout << "\n\t" << string(80, char(196));
        cout << "\n\t 0. Exit";
        cout << "\n\t" << string(80, char(205));
        cout << "\n";
        switch (inputInteger("\tOption: ", 0, 12))
        {
        case 0: exit(0);
        case 3: challenge3(); break;
        case 6: challenge6(); break;
        case 7: challenge7(); break;
        case 9: challenge9(); break;
        case 10: challenge10(); break;
        case 11: challenge11(); break;
        case 12: challenge12(); break;

        default: cout << "\n\tERROR: Invalid option.\n";
        }

        system("pause");
    } while (true);


    return 0;
}


void challenge3()
{
    system("cls");
    cout << "\n\tChallenge3";
    int size = inputInteger("\n\tEnter the size of the dynamic allocated array: ", true);

    double* scores = new double[size];

    cout << "\n\tPointer of array: " << &scores[0] << "\n\n";

    srand(time(0));

    double sum = 0.0;
    double upper = 100.0;
    double lower = 0.0;

    for (int i = 0; i < size; i++)
    {
        *(scores + i) = (rand() / (double)RAND_MAX) * (upper - lower) + lower;
    }

    // sort the array 
    selectionSort(scores, size);
    
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << & scores[i] << " socre# " << i + 1 << " :\t" << fixed << setprecision(2) << *(scores + i);
        if (i == 0)
        {
            cout << " (lowest score)";  // Indicate the lowest score
        }
        cout << '\n';
        
    }

    // recalcuLate AVERAGE without the lowest score
    for (int i = 1; i < size; i++)  
    {
        sum += *(scores + i);
    }

    cout << "\n\tAverage with lowest score dropped: " << sum / (size - 1) << "\n";

    delete[] scores;
}

void selectionSort(double array[], int size)
{
    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

void swap(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}


// Challenge 6
void challenge6() 
{
    system("cls");
    cout << "\n\tChallenge 6";

    int size = inputInteger("\n\tEnter the number of donations: ", true);
    int* arr = new int[size]; // Dynamically allocate memory for the array

    cout << "\n\tPointer of array: " << &arr[0] << "\n";

    // Input donations
    for (int i = 0; i < size; i++) {
        int value = inputInteger("\n\tEnter the value of donation#" + to_string(i + 1) + ": ", true);
        arr[i] = value;
    }

    // Unsorted 
    cout << "\n\tThe donations, in their original order are:\n\n";
    for (int i = 0; i < size; i++) 
    {
        cout << "\t" << &arr[i] << "\t" << arr[i] << '\n'; // Print each donation value
    }

    // Sort the donations
    arrSelectionSortAscending(arr, size);

    // Print sorted donations
    cout << "\n\n\tThe donations, sorted in ascending order are:\n\n";
    for (int i = 0; i < size; i++) 
    {
        cout << "\t" << & arr[i] << "\t" << arr[i] << '\n'; // Print each donation value
    }
    cout << "\n";

    delete[] arr;
}

void arrSelectionSortAscending(int* array, int size) 
{
    int minIndex; // Stores the index of the minimum element
    int minValue; // Stores the value of the minimum element

    for (int start = 0; start < size - 1; start++) 
    {
        minIndex = start;
        minValue = *(array + start);

        for (int index = start + 1; index < size; index++) 
        {
            if (*(array + index) < minValue) // Compare values directly
            {
                minValue = *(array + index);
                minIndex = index;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != start)
        {
            swap(array[minIndex], array[start]);
        }
    }
}


// Challenge 7
void challenge7()
{
    system("cls");
    cout << "\n\tChallenge 7";

    int size = inputInteger("\n\tEnter the number of donations: ", true);
    int* arr = new int[size]; // Dynamically allocate memory for the array

    cout << "\n\tPointer of array: " << &arr[0] << "\n";

    // Input donations
    for (int i = 0; i < size; i++) {
        int value = inputInteger("\n\tEnter the value of donation#" + to_string(i + 1) + ": ", true);
        arr[i] = value;
    }

    // Unsorted 
    cout << "\n\tThe donations, in their original order are:\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << &arr[i] << "\t" << arr[i] << '\n'; // Print each donation value
    }

    // Sort the donations
    arrSelectionSortDescending(arr, size);

    // Print sorted donations
    cout << "\n\n\tThe donations, sorted in descending order are:\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << &arr[i] << "\t" << arr[i] << '\n'; // Print each donation value
    }
    cout << "\n";

    delete[] arr;
}

void arrSelectionSortDescending(int* array, int size)
{
    int maxIndex;
    int maxValue;

    for (int start = 0; start < size - 1; start++)
    {
        maxIndex = start;
        maxValue = *(array + start);

        for (int i = start + 1; i < size; i++)
        {
            if (*(array + i) > maxValue)
            {
                maxValue = *(array + i);
                maxIndex = i;
            }
        }

        swap(array[maxIndex], array[start]);
    }
}


// Challenge 9
void challenge9()
{
    system("cls");
    cout << "\n\tChallenge 9\n";

    srand(time(0));

    int size = inputInteger("\n\tEnter the number of elements in the array: ", true);
    int* arr = new int[size];

    cout << "\n\tPointer of array: " << &arr[0] << "\n";

    cout << "\n\tThe array set, in their original order are: \n";
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 100 + 1;
        cout << "\t" << &arr[i] << "\t" << *(arr + i) << '\n';
    }

    arrSelectionSortAscending(arr, size);

    cout << "\n\tThe array set, sorted in ascending order are: \n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << &arr[i] << "\t" << *(arr + i) << '\n';
    }

    cout << "\n\tMedian of the array set: " << median(arr, size) << "\n\n";

    delete[] arr;
}

double median(int* array, int size)
{
    if (size % 2 != 0)
    {
        return *(array + size / 2);
    }
    else
    {
        int middle1 = size / 2 - 1;
        int middle2 = size / 2;
        return (*(array + middle1) + *(array + middle2)) / 2.0;
    }
}

// Challenge10
void challenge10()
{
    system("cls");
    cout << "\n\tChallenge 10\n";

    int size = inputInteger("\n\tEnter the number of elements in the array: ", true);
    int* arr = new int[size];

    cout << "\n\tPointer of array: " << &arr[0] << "\n";

    cout << "\n\tThe array set, in their original order are: \n\n";
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 100 + 1;
        cout << "\t" << &arr[i] << "\t" << *(arr + i) << '\n';
    }

   // Reverse array
    int* reverse = arrReverse(arr, size);

    cout << "\n\tThe new array set, in reversed order are: \n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << &reverse[i] << "\t" << *(reverse + i) << '\n';
    }
    cout << "\n";

    delete[] arr;
    delete[] reverse;
}

int* arrReverse(int* array, int size)
{
    int* reverse = new int[size];

    //Choose the last element
    int last = size - 1;

    for (int i = 0; i < size; i++, last--)
    {
        *(reverse + i) = *(array + last);
    }

    return reverse;
}

// Challenge 11
int* arrExpand(int* array, int size)
{
    int size1 = size * 2;

    int* expand = new int[size1];

    for (int i = 0; i < size; i++)
    {
        *(expand + i) = *(array + i);
    }

    for (int i = size; i < size1; i++)
    {
        *(expand + i) = 0;
    }

    return expand;
}

void challenge11()
{
    system("cls");
    cout << "\n\tChallenge 11\n";

    int size = inputInteger("\n\tEnter the number of elements in the array: ", true);
    int* arr = new int[size];

    cout << "\n\tPointer of array: " << &arr[0] << "\n";

    cout << "\n\tThe array set, in their original order are: \n\n";
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 100 + 1;
        cout << "\t" << &arr[i] << "\t" << *(arr + i) << '\n';
    }

    // Expand array
    int* expand = arrExpand(arr, size);

    cout << "\n\tThe new expanded array set are: \n\n";
    for (int i = 0; i < size * 2 ; i++)
    {
        cout << "\t" << &expand[i] << "\t" << *(expand + i) << '\n';
    }
    cout << "\n";

    delete[] arr;
    delete[] expand;
}

// Challenge 12
int* arrShifted(int* array, int size)
{
    int size1 = size + 1;

    int* shifted = new int[size1];

    *(shifted) = 0;

    for (int i = 1; i < size1; i++)
    {
        *(shifted + i) = *(array + (i-1) );
    }

    return shifted;
}

void challenge12()
{
    system("cls");
    cout << "\n\tChallenge 12\n";

    int size = inputInteger("\n\tEnter the number of elements in the array: ", true);
    int* arr = new int[size];

    cout << "\n\tPointer of array: " << &arr[0] << "\n";

    cout << "\n\tThe array set, in their original order are: \n\n";
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 100 + 1;
        cout << "\t" << &arr[i] << "\t" << *(arr + i) << '\n';
    }

    // Shifted array
    int* shifted = arrShifted(arr, size);

    cout << "\n\tThe new one-larger and shifted array set are: \n\n";
    for (int i = 0; i < size + 1; i++)
    {
        cout << "\t" << &shifted[i] << "\t" << *(shifted + i) << '\n';
    }
    cout << "\n";

    delete[] arr;
    delete[] shifted;
}
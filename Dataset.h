#pragma once
#include<iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;
class Dataset
{
private:
    int* array;
    int size;
    int capacity;
    bool isSample;  // true = Sample, false = Population

    void resize()
    {
        int newCapacity = capacity + 1;
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; i++) newArr[i] = array[i];
        delete[] array;
        array = newArr;
        capacity = newCapacity;
    }

    // keeps array sorted after adding one element
    void insertOne(int newValue)
    {
        if (size == capacity) resize();
        array[size] = newValue;
        size++;
        int temp = array[size - 1];
        int j = size - 2;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }

public:
    // Constructor
    Dataset(int initCap = 1)  // starts with 1 slot minimum
    {
        if (initCap < 1) initCap = 1;
        size = 0;
        capacity = initCap;
        array = new int[capacity];
        srand(time(0)); // seed random numbers
    }

    // Destructor
    ~Dataset()
    {
        delete[] array;
    }

    // NEW: insert exactly one specified value
    void insertSort(int value)
    {
        insertOne(value);
    }

    // existing: insert 'count' random values in [0..maxValue]
    void insertSort(int count, int maxValue)
    {
        for (int i = 0; i < count; i++)
        {
            int rnd = rand() % (maxValue + 1);
            insertOne(rnd);
        }
    }

    void display() const
    {
        /*if (size == 0)
        {
            cout << "(empty)\n";
            return;
        }*/
        cout << "\n\t";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << (i == size - 1 ? '\n' : ' ');
        }
    }

    bool CheckEmpty() const
    {
        if (size == 0)
        {
            cout << "\n\tException Error: Dataset is empty.";
            return true;
        }
        return false;
    }

    // Getter
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    const int* data() const { return array; }



    void setSample(bool sample) { isSample = sample; }
    string getType() const
    {
        if (isSample)
        {
            return "Sample";
        }
        else
        {
            return "Population";
        }
    }

   
bool deleteValue(int value)
{

    // Check if value exists at all
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            found = true;
            break;
        }
    }

    cout << "\n\tDelete *-all elements or 1-one element found with value " << value << ": ";
    char option = inputChar(" ");
    switch (option)
    {
    case '1':
    {
        // delete first occurrence only
        for (int i = 0; i < size; i++)
        {
            if (array[i] == value)
            {
                for (int j = i; j < size - 1; j++)
                    array[j] = array[j + 1];
                size--;
                cout << "\n\tCONFIRMATION: One element " << value << " has been found and deleted. ";
                return true;
            }
        }
    }
    break;
    case '*':
    {
        // delete all occurrences
        int newSize = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] != value)
            {
                array[newSize++] = array[i];
            }
        }
        int removed = size - newSize;
        size = newSize;
        cout << "\n\tCONFIRMATION: " << removed << " instance() of element: " << value << " have been found and deleted.";
        return true;
    }
    break;
    default:
        cout << "\n\tERROR: Invalid input. Must be one of '*1' character.";
    }


    if (!found)
    {
        cout << "\n\n\tERROR: No element " << value << " has been found and deleted.";
        return false;
    }
}


void deleteRange(int start, int end)
{

    // Collect deleted values (temporary storage for display)
    int* deleted = new int[size];
    int delCount = 0;

    // Shift elements to remove values in range
    int newSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] >= start && array[i] <= end)
        {
            deleted[delCount++] = array[i];  // store deleted element
        }
        else
        {
            array[newSize++] = array[i];    // keep element
        }
    }

    // Update dataset size
    size = newSize;

    // Output result
    if (delCount > 0)
    {
        cout << "\n\tCONFIRMATION: Element(s): ";
        for (int i = 0; i < delCount; i++)
        {
            cout << deleted[i] << (i == delCount - 1 ? "" : " ");
        }
        cout << " in range(" << start << ".." << end << ") have been deleted.\n";
    }
    else
    {
        cout << "\n\tNo elements found in range(" << start << ".." << end << ").\n";
    }

    delete[] deleted;
}

void deleteAllValues()
{

    delete[] array;        // free the memory
    array = new int[1];    // reset with at least 1 slot
    size = 0;
    capacity = 1;

    cout << "\n\tDataset has been purged of all elements.";
}

};


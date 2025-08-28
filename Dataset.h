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

   


};

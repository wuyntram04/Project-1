#include<iostream>
#include <iomanip>
#include"input.h"
#include<fstream>
#include"Dataset.h"

using namespace std;

void showMenu();
void showIntro();
void insertMenu();
Dataset ds;

int main()
{
    showIntro();

    do
    {
        system("cls");

        cout << "\n\tAddress of Dynamic array: ";
        cout << "\n\tDataset: (" << ds.getType() << ")\n\t";
        ds.display();
        showMenu();

       

        switch (toupper(inputChar("\n\tOption: ")))
        {
        case '0': exit(0);
        case '1':
        {
            system("cls");

            cout << "\n\n\tIn statistics, Population refers to the entire group of data";
            cout << "\n\tpoints that a study is interested in, while a Sample is a";
            cout << "\n\tsubset of that population that is actually used in the study.";

            cout << "\n\n\tConfigure Dataset Menu";
            cout << "\n\t" << string(80, char(205));
            cout << "\n\t\tA. sample";
            cout << "\n\t\tB. population";
            cout << "\n\t" << string(80, char(196));
            cout << "\n\t\tR. return";
            cout << "\n\t" << string(80, char(205));

            switch (toupper(inputChar("\n\t\tOption: ")))
            {
            case 'A':
            {
                cout << "\n\tData Set configured for Sample";
                ds.setSample(true);
            }
                break;

            case 'B':
            {
                cout << "\n\tData Set configured for Population";
                ds.setSample(false);
            }
                break;
            case 'R': break;
            }



        }
        break;
        case '2': 
        {
            insertMenu();
        }

            break;

        default: cout << "\t\tERROR - Invalid option."; break;
        }

        cout << "\n";
        system("pause");

    } while (true);

    return EXIT_SUCCESS;
}

void showMenu()
{
    
    cout << "\n\tERROR: Data Set requires at least 2 values.";

    cout << "\n\n\tDescriptive Statistics Calculator Main Menu\n";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t0. Exit";
    cout << "\n\t1. Configure Dataset to Sample or Polulation";
    cout << "\n\t2. Insert sort value(s) to the Dataset";
    cout << "\n\t3. Delete value(s) from the Dataset";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\tA. Find Minimum \t\t\tN. Find Outliers";
    cout << "\n\tB. Find Maximum \t\t\tO. Find Sum of Squares";
    cout << "\n\tC. Find Range \t\t\t\tP. Find Mean Absolute Deviation";
    cout << "\n\tD. Find Size \t\t\t\tQ. Find Root Mean Square";
    cout << "\n\tE. Find Sum \t\t\t\tR. Find Standard Error of Mean";
    cout << "\n\tF. Find Mean \t\t\t\tS. Find Skewness";
    cout << "\n\tG. Find Median \t\t\t\tT. Find Kurtosis";
    cout << "\n\tH. Find Mode(s) \t\t\tU. Find Kurtosis Excess";
    cout << "\n\tI. Find Standard Deviation \t\tV. Find Coefficient of Variation";
    cout << "\n\tJ. Find Variance \t\t\tW. Find Relative Standard Deviation";
    cout << "\n\tK. Find Midrange \t\t\tX. Display Frequency Table";
    cout << "\n\tL. Find Quartiles \t\t\tY. Display ALL statical results";
    cout << "\n\tM. Find Interquartile Range \t\tZ. Output ALL statical results to text file";
    cout << "\n\t" << string(85, char(205)) << "\n";
   
}

void showIntro()
{
    cout << "\n\tWhat are Descriptive Statistics?";
    cout << "\n\n\tDescriptive statistics summarize certain aspects of a data set (Sample or Population)\n\tusing numeric calculations.";
    cout << "\n\n\thttps://www.calculatorsoup.com/calculators/statistics/descriptivestatistics.php.";
    cout << "\n\nPress any key to continue . . . ";
    cin.get();

    system("cls");
}

void insertMenu()
{
    do
    {
        system("cls");
        cout << "\n\n\tInsert (sort) Dataset Menu";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t\tA. insert a value";
        cout << "\n\t\tB. insert a specified number of random values";
        cout << "\n\t\tC. read data from file and insert values";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t\tR. return";
        cout << "\n\t" << string(80, char(205));

        switch (toupper(inputChar("\n\n\t\tOption: ")))
        {
        case 'A':
        {
            int val = inputInteger("\n\n\tSpecify an integer value to be inserted: ");
            ds.insertSort(val); 
            cout << "\n\t" << val << " has been inserted...\n";
            cout << "\n\t";
            system("pause");
            
        }
        break;
        case 'B':
        {
            int count = inputInteger("\n\n\tSpecify a number of values to be randomly generated into the Dataset: ", 1, 1000);
            int maxVal =  10000;
            ds.insertSort(count, maxVal);
            cout << "\n\tCONFIRMATION: Inserted " << count << " random values into the Dataset.\n";
            cout << "\n\t";
            system("pause");
            break;
        }
        case 'C':
        {
            ifstream inputFile;
            string filename;

            cout << "\n\n\tSpecify a data text file name to read: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
            getline(cin, filename);

            inputFile.open(filename);

            if (inputFile)
            {
                int value = 0;
                int count = 0;

                while (inputFile >> value)
                {
                    ds.insertSort(value);   // insert exact values into dataset
                    count++;
                }

                cout << "\n\tCONFIRMATION: " << count
                    << " element(s) have been read and inserted to the Dataset.\n\n";

                inputFile.close();
            }
            else
            {
                cout << "\n\n\tERROR: File, " << filename << ", cannot be found.\n";
            }

            system("pause");
        }
        case 'R':
            return;
        break;
        }

    } while (true);

}

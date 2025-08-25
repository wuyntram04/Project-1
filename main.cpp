#include <iostream>
#include <limits>
using namespace std;

int inputInteger(const char* prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) return x;
        cout << "Invalid input. Please enter an integer.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void showMainMenu() {
    cout << "\nDescriptive Statistics Calculator Main Menu\n";
    cout << "════════════════════════════════════════════════════════════════════════════════\n";
    cout << " 0. Exit\n";
    cout << " 1. Configure Dataset to Sample or Polulation\n";
    cout << " 2. Insert sort value(s) to the Dataset\n";
    cout << " 3. Delete value(s) from the Dataset\n";
    cout << "───────────────────────────────────────────────────────────────────────────────\n";
    cout << " A. Find Minimum                   N. Find Outliers\n";
    cout << " B. Find Maximum                   O. Find Sum of Squares\n";
    cout << " C. Find Range                     P. Find Mean Absolute Deviation\n";
    cout << " D. Find Size                      Q. Find Root Mean Square\n";
    cout << " E. Find Sum                       R. Find Standard Error of Mean\n";
    cout << " F. Find Mean                      S. Find Skewness\n";
    cout << " G. Find Median                    T. Find Kurtosis\n";
    cout << " H. Find Mode(s)                   U. Find Kurtosis Excess\n";
    cout << " I. Find Standard Deviation        V. Find Coefficient of Variation\n";
    cout << " J. Find Variance                  W. Find Relative Standard Deviation\n";
    cout << " K. Find Midrange                  X. Display Frequency Table\n";
    cout << " L. Find Quartiles                 Y. Display ALL statical results\n";
    cout << " M. Find Interquartile Range       Z. Output ALL statical results to text file\n";
    cout << "════════════════════════════════════════════════════════════════════════════════\n";
    cout << "Option: ";
}

int main() {
    char choice;
    while (true) {
        showMainMenu();
        cin >> choice;

        // unify case (accept lower/upper)
        if (choice >= 'a' && choice <= 'z')
            choice = choice - 'a' + 'A';

        switch (choice) {
        case '0':
            cout << "Exiting program...\n";
            return 0;

        case '1':
            cout << "[Configure Dataset]\n";
            break;
        case '2':
            cout << "[Insert sort value(s)]\n";
            break;
        case '3':
            cout << "[Delete value(s)]\n";
            break;

        case 'A':
            cout << "[Find Minimum]\n";
            break;
        case 'B':
            cout << "[Find Maximum]\n";
            break;
        case 'C':
            cout << "[Find Range]\n";
            break;
        default:
            cout << "ERROR: Invalid option.\n";
        }
    }
}

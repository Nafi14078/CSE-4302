#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("grades.txt");
    if (!inputFile) {
        cerr << "Error opening grades.txt file." << endl;
        return 1;
    }

    vector<double> gpas;
    double gpa;

    // Read GPAs from the file
    while (inputFile >> gpa) {
        gpas.push_back(gpa);
    }

    inputFile.close();

    // Check if there are at least 3 GPAs in the file
    if (gpas.size() < 3) {
        cout << "There are not enough GPAs to find the third lowest GPA." << endl;
        return 0;
    }

    // Sort the GPAs in ascending order
    sort(gpas.begin(), gpas.end());

    // Print the third lowest GPA
    cout << "The third lowest GPA is: " << fixed << setprecision(2) << gpas[2] << endl;

    return 0;
}

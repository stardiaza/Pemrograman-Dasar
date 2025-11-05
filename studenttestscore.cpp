#include <iostream>
#include <string>
using namespace std;

int NUM_OF_STUDENT = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int    testScore;
    char   grade;
};

char gradeFromScore(int score) {
    if      (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else if (score >= 40) return 'E';
    else                  return 'F';
}

int readToArray(studentType arr[], int NUM_OF_STUDENT, istream& in = cin) {
    int i = 0;
    for (; i < NUM_OF_STUDENT; ++i) {
        if (!(in >> arr[i].studentFName >> arr[i].studentLName >> arr[i].testScore)) {
            break;}
        arr[i].grade = gradeFromScore(arr[i].testScore);
    }
    return i;
}

int findHighestScore(const studentType arr[], int n) {
    if (n <= 0) return -1;
    int best = 0;
    for (int i = 1; i < n; i++)
        if (arr[i].testScore > arr[best].testScore) best = i;
    return best;
}

void showRank1(const studentType arr[], int n) {
    int k = findHighestScore(arr, n);
    if (k < 0) { cout << "No students.\n"; return; }
    cout << "Rank 1: " << arr[k].studentFName << ' ' << arr[k].studentLName
         << " (score " << arr[k].testScore << ", grade " << arr[k].grade << ")\n";
}

int main() {
    studentType classList[NUM_OF_STUDENT];

    cout << "Masukkan list student (Format : FirstName LastName Score):\n";
    int n = readToArray(classList, NUM_OF_STUDENT);

    cout << "\nStudent List (" << n << "):\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". "
             << classList[i].studentFName << ' '
             << classList[i].studentLName  << " | "
             << "score: " << classList[i].testScore
             << ", grade: " << classList[i].grade << '\n';
    }

    showRank1(classList, n);
    return 0;
}

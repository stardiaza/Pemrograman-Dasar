#include <iostream>
#include <vector>
#include <iomanip>
#include "PatientRecord.h" // Cukup panggil header utamanya saja

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(0); 

    // Database Dummy
    vector<PatientRecord> records;
    // Perhatikan: Karena Date dan Bill ada di header lain, konstruktor tetap bekerja normal
    records.push_back(PatientRecord("Woko Jidodo", 20250001, 36, 'M', "dr. Rina Putri", "Bedah Umum", Date(1,8,2025), Date(4,8,2025), Bill(1500000, 2250000, 425000)));
    records.push_back(PatientRecord("Pegawati", 20250002, 29, 'F', "dr. Andi Kurnia", "Penyakit Dalam", Date(10,8,2025), Date(12,8,2025), Bill(1100000, 1300000, 210000)));
    records.push_back(PatientRecord("Ribran Gaka", 20250003, 42, 'M', "dr. Wulan Hana", "Bedah Saraf", Date(15,8,2025), Date(18,8,2025), Bill(1800000, 2400000, 530000)));

    int choice;
    int patientIndex = -1;

    // Loop Utama
    while (true) {
        cout << "\n=== HOSPITAL ADMIN SYSTEM ===\n";
        cout << "Select Patient to Manage:\n";
        for (size_t i = 0; i < records.size(); ++i) {
            cout << i + 1 << ". " << records[i].getName() << " (ID: " << records[i].getId() << ")\n";
        }
        cout << "0. Exit Application\n";
        cout << "Choice >> ";
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > records.size()) {
            cout << "Invalid patient selection!\n";
            continue;
        }

        patientIndex = choice - 1;
        bool backToMain = false;

        // Loop Menu Interaktif
        while (!backToMain) {
            cout << "\n--- ACTION MENU: " << records[patientIndex].getName() << " ---\n";
            cout << "1. Display Patient Info\n";
            cout << "2. Print Out Bill\n";
            cout << "3. Confirm Payment & Print Receipt\n";
            cout << "4. Back to Patient List\n";
            cout << "Select Action >> ";
            cin >> choice;

            switch (choice) {
            case 1:
                records[patientIndex].displayHeaderInfo();
                break;
            case 2:
                records[patientIndex].displayBillingInfo();
                break;
            case 3:
                records[patientIndex].processPayment();
                break;
            case 4:
                backToMain = true;
                break;
            default:
                cout << "Invalid option.\n";
            }
        }
    }

    cout << "Application Closed.\n";
    return 0;
}
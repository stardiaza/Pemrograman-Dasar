#ifndef PATIENTRECORD_H
#define PATIENTRECORD_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Bill.h"  

using namespace std;

class PatientRecord {
private:
    string patientName;
    int patientId;
    int age;
    char gender;
    string doctorName;
    string doctorSpec;
    Date admitDate;
    Date dischargeDate;
    Bill bill;
    bool isPaid; 

public:
    PatientRecord(string pName, int pId, int pAge, char pGender, 
                  string docName, string docSpec, 
                  Date admit, Date discharge, Bill pBill)
        : patientName(pName), patientId(pId), age(pAge), gender(pGender),
          doctorName(docName), doctorSpec(docSpec), 
          admitDate(admit), dischargeDate(discharge), bill(pBill) {
              isPaid = false; 
          }

    string getName() const { return patientName; }
    int getId() const { return patientId; }
    bool getPaymentStatus() const { return isPaid; }

    // Display Patient Info
    void displayHeaderInfo() const {
        cout << "\n--- PATIENT INFO ---\n";
        cout << "ID          : " << patientId << "\n";
        cout << "Name        : " << patientName << "\n";
        cout << "Age/Gender  : " << age << " / " << gender << "\n";
        cout << "Doctor      : " << doctorName << " (" << doctorSpec << ")\n";
        cout << "Stay Period : " << admitDate.toString() << " to " << dischargeDate.toString() << "\n";
    }

    // Print Bill/Invoice
    void displayBillingInfo() const {
        cout << "\n--- BILLING INVOICE ---\n";
        cout << "Doctor Fee  : Rp " << bill.getDocFee() << "\n";
        cout << "Room Charge : Rp " << bill.getRoomCharge() << "\n";
        cout << "Pharmacy    : Rp " << bill.getPharCharge() << "\n";
        cout << "-------------------------\n";
        cout << "TOTAL       : Rp " << bill.calculateTotal() << "\n";
        cout << "STATUS      : " << (isPaid ? "[PAID / LUNAS]" : "[UNPAID / BELUM BAYAR]") << "\n";
    }

    // Confirm Payment & Receipt
    void processPayment() {
        if (isPaid) {
            cout << "\n[!] Tagihan ini sudah lunas sebelumnya.\n";
        } else {
            isPaid = true;
            cout << "\nProcessing payment...\n";
            cout << "Payment Success!\n";
            
            // Print Official Receipt
            cout << "\n==============================\n";
            cout << "      OFFICIAL RECEIPT       \n";
            cout << "==============================\n";
            cout << "Date: " << dischargeDate.toString() << "\n"; 
            cout << "Received from: " << patientName << "\n";
            cout << "Amount       : Rp " << bill.calculateTotal() << "\n";
            cout << "\n      *** PAID / LUNAS *** \n";
            cout << "==============================\n";
        }
    }
};

#endif

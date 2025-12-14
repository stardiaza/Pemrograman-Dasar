#ifndef BILL_H
#define BILL_H

using namespace std;

class Bill {
private:
    double docFee, roomCharge, pharCharge;
public:
    Bill(double doc = 0, double room = 0, double phar = 0) 
        : docFee(doc), roomCharge(room), pharCharge(phar) {}

    double calculateTotal() const { return docFee + roomCharge + pharCharge; }
    double getDocFee() const { return docFee; }
    double getRoomCharge() const { return roomCharge; }
    double getPharCharge() const { return pharCharge; }
};

#endif
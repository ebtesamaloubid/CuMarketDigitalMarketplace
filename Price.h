#ifndef PRICE_H
#define PRICE_H

#include <iostream>
using namespace std;

class Price {
public:
    Price();
    Price(double value);

    bool operator<(const Price& p) const;
    bool operator==(const Price& p) const;
    friend ostream& operator<<(ostream& p, const Price& price);
    friend istream& operator>>(istream& in, Price& price);
    bool inRange(const Price& min, const Price& max) const;
    void print() const;

private:
    double value;
};

#endif 

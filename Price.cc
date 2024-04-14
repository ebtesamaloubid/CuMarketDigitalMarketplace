#include "Price.h"
#include <iomanip>

// Constructors
Price::Price(){
    this -> value =0; 
}

Price::Price(double value){
    this->value = value; 
} 

bool Price::operator<(const Price& p) const {
    return this->value < p.value;
}

bool Price::operator==(const Price& p) const {
    return this->value == p.value;
}

ostream& operator<<(ostream& p, const Price& price) {
    //print p the value to two decimal places with a dollar sign in front
    p <<fixed << setprecision(2) << "$" << price.value;
    return p;
}

istream& operator>>(istream& in, Price& price) {
    string input;
    in >> input;
    size_t charector = input.find('$');
    if (charector != string::npos) {
        input.erase(charector, 1);
    }
    price.value = stod(input);
    return in;
}

bool Price::inRange(const Price& min, const Price& max) const {
    bool check = (this->value >= min.value && this->value <= max.value);
    return check;
}

void Price::print() const {
    cout << fixed << setprecision(2) << "$" << this->value << endl;
}

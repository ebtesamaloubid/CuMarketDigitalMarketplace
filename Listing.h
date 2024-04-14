#ifndef LISTING_H
#define LISTING_H

#include "Price.h"
#include "Category.h"
#include <string>
using namespace std;

class Listing {
public:
    Listing(const string& user, const string& title, cat::Category category, const string& description, const Price& price);
    bool lessThan(Listing& listing) const;
    void print() const;
    friend ostream& operator<<(ostream& output, const Listing& listing);

    // move them later
    const Price& getPrice() const { return price; }
    cat::Category getCategory() const { return category; }
    const string& getTitle() const { return title; } 

private:
    string user;
   string title;
    string description;
    cat::Category category;
    Price price;
};

#endif 

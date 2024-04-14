#include "Listing.h"
#include <iostream>

Listing::Listing(const string& user, const string& title, cat::Category category, const string& description, const Price& price){
    this->user = user;
    this->title = title;
    this->category = category;
    this->description = description;
    this->price= price;
}

bool Listing::lessThan(Listing& listing) const {
    bool check = this->title < listing.title;
    return check;
}

void Listing::print() const {
    cout << "User: " << user << endl
            << "Title: " << title << endl
            << "Category: " << cat::categoryToString(category) << endl
            << "Description: " << description <<endl
            << "Price: $" << price << endl;
}

ostream& operator<<(ostream& output, const Listing& listing) {
    output << "User: " << listing.user <<endl
        << "Title: " << listing.title << endl
        << "Category: " << cat::categoryToString(listing.category) << endl
        << "Description: " << listing.description << endl
        << "Price: $" << listing.price << endl;
    return output;
}
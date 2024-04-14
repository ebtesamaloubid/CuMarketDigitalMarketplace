#ifndef CUMARKET_H
#define CUMARKET_H

#include <iostream>
#include <string>
#include "List.h"
#include "Listing.h"
#include "Filter.h"
using namespace std;
using namespace cat;

class CuMarket {
public:
    CuMarket();
    ~CuMarket();

    void addListing(const string& name, const string& listTitle, Category category, const string& description, const Price& price);
    void removeListing(const string& listTitle);
    void searchListings(const Filter& filter, List<Listing*>& list);

private:
    List<Listing*> listings;
};

#endif

#include "CuMarket.h"

CuMarket::CuMarket() {}

CuMarket::~CuMarket() {
    for (int i = 0; i < listings.getSize(); ++i) {
        delete listings[i];
    }
}


void CuMarket::addListing(const string& userName, const string& listTitle, Category category, const string& description, const Price& price) {
    bool check = !listings.isFull();
    if (check) {
        Listing* newListing = new Listing(userName, listTitle, category, description, price);
        listings += newListing;
    } else {
        cout << "List is full" << endl;
    }
}

void CuMarket::removeListing(const std::string& listTitle) {
    for (int i = 0; i < listings.getSize(); ++i) {
        bool check = listings[i]->getTitle() == listTitle;
        if (check) {
            delete listings[i];
            listings -= listings[i];
            return;
        }
    }
    cout << " No listing found with this title " << listTitle << endl;
}

void CuMarket::searchListings(const Filter& filter, List<Listing*>& list) {
    for (int i = 0; i < listings.getSize(); ++i) {
        if (filter.matches(*listings[i])) {
            list += listings[i];
        }
    }
}

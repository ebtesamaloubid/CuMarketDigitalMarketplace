#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Listing.h"
#include "List.h"
#include "Filter.h"
//#include "Category.h"
using namespace std;
using namespace cat;

class View {
		
	public:
		void menu(vector<string>&, int& choice, const Filter& filter);
		void menu(vector<string>&, int& choice);
		void printListings(const List<Listing*>& listings);
		void listingMenu( const List<Listing*>& listings, int& choice);
		void printListing(const Listing&);

		// user input
        void promptPriceRange(Price& min, Price& max);
		void promptCategory(Category& category);
		



	
		
};
#endif
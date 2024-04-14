#include "Filter.h"

// Filter Class
bool Filter::matches(const Listing& listing) const {
    return true; 
}

void Filter::print(ostream& out) const {
    out << "This Filter will select everything." << endl;
}

ostream& operator<<(ostream& out, const Filter& filter) {
    filter.print(out);
    return out;
}

// Price_Filter Class
Price_Filter::Price_Filter(const Price& min, const Price& max){
    this->min = min;
    this->max = max;
} 

bool Price_Filter::matches(const Listing& listing) const {
    bool matches = listing.getPrice().inRange(min, max); 
    return matches;
}

void Price_Filter::print(ostream& out) const {
    out << "The input matches a Listing with the given price range: min:" << min << " max: " << max << endl;
}

// Cat_Filter Class
Cat_Filter::Cat_Filter(cat::Category category){
    this -> category = category;
}

bool Cat_Filter::matches(const Listing& listing) const {
    // use getter
    bool matches = listing.getCategory() == category; 
    return matches;
}

void Cat_Filter::print(std::ostream& out) const {
    out << "The input matches a Listing in the category: " << cat::categoryToString(category) << endl;
}



// PriceAndCat_Filter Class
PriceAndCat_Filter::PriceAndCat_Filter(const Price& min, const Price& max, cat::Category category)
    : Price_Filter(min, max), Cat_Filter(category) {}

bool PriceAndCat_Filter::matches(const Listing& listing) const {
    bool priceMatches =Price_Filter::matches(listing);
    bool catMatches= Cat_Filter::matches(listing);
    return (priceMatches && catMatches);
}

void PriceAndCat_Filter::print(std::ostream& out) const {
    out << "The input matches a Listing in the category: " << cat::categoryToString(this->getCategory())<< " and price range: min: " << this->getMin() << " max:  " << this->getMax() << endl;
}

// getters
const Price& Price_Filter:: getMin() const { return min; }
const Price& Price_Filter::getMax() const { return max; }
cat::Category Cat_Filter::getCategory() const { return category; }


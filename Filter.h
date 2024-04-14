#ifndef FILTER_H
#define FILTER_H

#include "Listing.h"
using namespace std;

class Filter {
public:
//This should always return true (this is the “no filter” Filter).
    virtual bool matches(const Listing& listing) const;
    virtual void print(ostream& out) const;
    friend ostream& operator<<(ostream& out, const Filter& filter);
};

class Price_Filter : virtual public Filter {
private:
    Price min, max;
public:
    Price_Filter(const Price& min, const Price& max);
    bool matches(const Listing& listing) const override;
    void print(ostream& out) const override;
    const Price& getMin() const;
    const Price& getMax() const;
};

class Cat_Filter : virtual public Filter {
private:
    cat::Category category;
public:
    Cat_Filter(cat::Category category);
    bool matches(const Listing& listing) const override;
    void print(ostream& out) const override;
    cat::Category getCategory() const;
};

class PriceAndCat_Filter : public Price_Filter, public Cat_Filter {
public:
    PriceAndCat_Filter(const Price& min, const Price& max, cat::Category category);
    bool matches(const Listing& listing) const override;
    void print(ostream& out) const override;
};

#endif 

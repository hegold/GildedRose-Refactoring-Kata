#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}

    bool isAgedBrie() const;
    bool isSulfuras() const;
    bool isBackstagePass() const;
    
    void decrementSellIn();
    void decrementQuality();
    //void incrementQuality();
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
};


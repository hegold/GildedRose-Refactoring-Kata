#include <string>
#include <vector>

using namespace std;

class Item
{
	int sellIn;
	int quality;
public:
    string name;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
    
    int getSellIn() const;
    int getQuality() const;
    void zeroQuality() { quality = 0; }

    bool isAgedBrie() const;
    bool isSulfuras() const;
    bool isBackstagePass() const;
    
    void decrementSellIn();
    void decrementQuality();
    void incrementQuality();
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();

	void adjustQualityAfterSellIn(Item& item);

    void adjustQualityBeforeSellIn(Item& item);

};


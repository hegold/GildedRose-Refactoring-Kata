#include <string>
#include <vector>
#include <memory>

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
    bool isPastSellIn() const;
    
    virtual bool isAgedBrie() const;
    bool isSulfuras() const;
    bool isBackstagePass() const;
    
    void decrementSellIn();
    void decrementQuality();
    void incrementQuality();

    void preAdjustQuality();
    void postAdjustQuality();
};

class AgedBrie : public Item {
public:
    AgedBrie(string name, int sellIn, int quality) : Item(name, sellIn, quality) {}
    
    virtual bool isAgedBrie() const override;
};

struct ItemFactory {
	static shared_ptr<Item> make(string name, int sellIn, int quality);
};

class GildedRose
{
public:
    vector<Item>& items; // legacy
    GildedRose(vector<Item>& items);

    vector<shared_ptr<Item>> newItems;
    GildedRose(vector<shared_ptr<Item>> items);
    
    void updateQuality();
};


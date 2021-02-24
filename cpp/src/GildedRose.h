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
    
    bool isSulfuras() const;
    bool isBackstagePass() const;
    
    virtual bool getsBetterWithAge() const;

    void decrementSellIn();
    void decrementQuality();
    void incrementQuality();

    void preAdjustQuality();
    void postAdjustQuality();
};

class ItemGettingBetterWithAge : public Item {
public:
    ItemGettingBetterWithAge(string name, int sellIn, int quality) : Item(name, sellIn, quality) {}
    
    virtual bool getsBetterWithAge() const override;
};

struct ItemFactory {
	static shared_ptr<Item> make(string name, int sellIn, int quality);
};

class GildedRose
{
    vector<shared_ptr<Item>> newItems;
public:

    GildedRose(vector<Item>& items);
    GildedRose(vector<shared_ptr<Item>> items);
    
    void updateQuality();
};


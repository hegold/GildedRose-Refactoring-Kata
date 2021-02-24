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
    
    void decrementQuality();
    void incrementQuality();

    void decrementSellIn();
    virtual void preAdjustQuality();
    virtual void postAdjustQuality();
};

class ItemGettingBetterWithAge : public Item {
public:
    ItemGettingBetterWithAge(string name, int sellIn, int quality) : Item(name, sellIn, quality) {}

	virtual void preAdjustQuality() override;
	virtual void postAdjustQuality() override;
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


#include <string>
#include <vector>
#include <memory>

using namespace std;



class Item
{
	int sellIn;
protected:
	int quality;
public:
    string name;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
    
    int getSellIn() const;
    int getQuality() const;
    void zeroQuality() { quality = 0; }
    bool isPastSellIn() const;
    
    void incrementQuality();

    virtual void decrementSellInThenAdjustQualityIfPassedSellin();
    virtual void decrementQuality();
    virtual void updateQuality();
    virtual void adjustQualityAfterSellInPasses();
};

class ItemGettingBetterWithAge : public Item {
public:
    ItemGettingBetterWithAge(string name, int sellIn, int quality) : Item(name, sellIn, quality) {}

	virtual void updateQuality() override;
	virtual void adjustQualityAfterSellInPasses() override;
};

class BackstagePass : public Item {
public:
	BackstagePass(string name, int sellIn, int quality) : Item(name, sellIn, quality) {}

	virtual void updateQuality() override;
	virtual void adjustQualityAfterSellInPasses() override;
};

class Sulfuras : public Item {
public:
    Sulfuras(string name, int sellIn, int quality) : Item(name, sellIn, quality) {}

    virtual void decrementSellInThenAdjustQualityIfPassedSellin() override;
    virtual void decrementQuality() override;
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


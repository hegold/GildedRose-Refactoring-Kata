#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (Item& item : items)
    {
        adjustQualityBeforeSellIn(item);

        item.decrementSellIn();

		adjustQualityAfterSellIn(item);

    }
}


void GildedRose::adjustQualityBeforeSellIn(Item& item) {
	if (item.isAgedBrie()) {
		item.incrementQuality();
	}
	else if (item.isBackstagePass())
	{
		item.incrementQuality();

		if (item.getSellIn() < 11)
		{
			item.incrementQuality();
		}

		if (item.getSellIn() < 6)
		{
			item.incrementQuality();
		}
	}
	else {
		item.decrementQuality();
	}
}

void GildedRose::adjustQualityAfterSellIn(Item& item) {
	if (item.getSellIn() < 0)
	{
		if (item.isAgedBrie())
		{
			item.incrementQuality();
		}
		else {
			if (item.isBackstagePass())
			{
				item.zeroQuality();
			}
			else
			{
				item.decrementQuality();
			}
		}
	}
}

int Item::getSellIn() const {
	return sellIn;
}

int Item::getQuality() const {
	return quality;
}

bool Item::isAgedBrie() const {
    return name == "Aged Brie";
}

bool Item::isSulfuras() const {
    return name == "Sulfuras, Hand of Ragnaros";
}

bool Item::isBackstagePass() const {
    return name == "Backstage passes to a TAFKAL80ETC concert";
}

void Item::decrementSellIn() {
	if (!isSulfuras()) {
		--sellIn;
	}
}

void Item::decrementQuality() {
    if (quality > 0 && !isSulfuras()) {
        --quality;
    }
}

void Item::incrementQuality() {
    if (quality < 50) {
        ++quality;
    }
}

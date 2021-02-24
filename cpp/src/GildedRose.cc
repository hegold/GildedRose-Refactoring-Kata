#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (Item& item : items)
    {
        if (!item.isAgedBrie() && !item.isBackstagePass())
        {
            item.decrementQuality();
        }
        else
        {
            item.incrementQuality();

            if (item.isBackstagePass())
            {
                if (item.getSellIn() < 11)
                {
                    item.incrementQuality();
                }

                if (item.getSellIn() < 6)
                {
                    item.incrementQuality();
                }
            }
        }

        item.decrementSellIn();

        if (item.getSellIn() < 0)
        {
            if (!item.isAgedBrie())
            {
                if (!item.isBackstagePass())
                {
                    item.decrementQuality();
                }
                else
                {
                    item.setQualityREMOVE(0);
                }
            }
            else
            {
                item.incrementQuality();
            }
        }
    }
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

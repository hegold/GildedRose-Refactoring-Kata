#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (Item& item : items)
    {
        if (!item.isAgedBrie() && !item.isBackstagePass())
        {
            if (item.quality > 0)
            {
                if (!item.isSulfuras())
                {
                    item.decrementQuality();
                }
            }
        }
        else
        {
            if (item.quality < 50)
            {
                item.incrementQuality();;

                if (item.isBackstagePass())
                {
                    if (item.sellIn < 11)
                    {
                        if (item.quality < 50)
                        {
                            item.incrementQuality();
                        }
                    }

                    if (item.sellIn < 6)
                    {
                        if (item.quality < 50)
                        {
                            item.incrementQuality();
                        }
                    }
                }
            }
        }

        if (!item.isSulfuras())
        {
            item.decrementSellIn();
        }

        if (item.sellIn < 0)
        {
            if (!item.isAgedBrie())
            {
                if (!item.isBackstagePass())
                {
                    if (item.quality > 0)
                    {
                        if (!item.isSulfuras())
                        {
                            item.decrementQuality();
                        }
                    }
                }
                else
                {
                    item.quality = 0;
                }
            }
            else
            {
                if (item.quality < 50)
                {
                    item.incrementQuality();
                }
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
    --sellIn;
}

void Item::decrementQuality() {
    --quality;
}

void Item::incrementQuality() {
    ++quality;
}

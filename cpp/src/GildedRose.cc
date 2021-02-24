#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (int i = 0; i < items.size(); i++)
    {
        Item& item = items[i];

        if (!item.isAgedBrie() && !item.isBackstagePass())
        {
            if (item.quality > 0)
            {
                if (!item.isSulfuras())
                {
                    item.quality = item.quality - 1;
                }
            }
        }
        else
        {
            if (item.quality < 50)
            {
                item.quality = item.quality + 1;

                if (item.isBackstagePass())
                {
                    if (item.sellIn < 11)
                    {
                        if (item.quality < 50)
                        {
                            item.quality = item.quality + 1;
                        }
                    }

                    if (item.sellIn < 6)
                    {
                        if (item.quality < 50)
                        {
                            item.quality = item.quality + 1;
                        }
                    }
                }
            }
        }

        if (!item.isSulfuras())
        {
            item.sellIn = item.sellIn - 1;
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
                            item.quality = item.quality - 1;
                        }
                    }
                }
                else
                {
                    item.quality = item.quality - item.quality;
                }
            }
            else
            {
                if (item.quality < 50)
                {
                    item.quality = item.quality + 1;
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

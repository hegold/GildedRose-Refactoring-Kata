#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (Item& item : items)
    {
		item.preAdjustQuality();
        item.decrementSellIn();
		item.postAdjustQuality();
    }
}

int Item::getSellIn() const {
	return sellIn;
}

int Item::getQuality() const {
	return quality;
}

bool Item::isPastSellIn() const {
	return sellIn < 0;
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
	if (isBackstagePass() && isPastSellIn()) {
		quality = 0;
	}
	else if (isAgedBrie() && isPastSellIn()) {
		incrementQuality();
	}
	else if (quality > 0 && !isSulfuras()) {
        --quality;
    }
}

void Item::incrementQuality() {
    if (quality < 50) {
        ++quality;
    }
}

void Item::preAdjustQuality() {
	if (isAgedBrie()) {
		incrementQuality();
	}
	else if (isBackstagePass())
	{
		incrementQuality();

		if (getSellIn() < 11)
		{
			incrementQuality();
		}

		if (getSellIn() < 6)
		{
			incrementQuality();
		}
	}
	else {
		decrementQuality();
	}
}

void Item::postAdjustQuality() {
	if (isPastSellIn())
	{
		decrementQuality();
	}
}

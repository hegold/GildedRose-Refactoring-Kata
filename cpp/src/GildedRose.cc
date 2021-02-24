#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) 
	: items(items)
{}
    
GildedRose::GildedRose(vector<shared_ptr<Item>> items)
	: newItems(std::move(items))
	, items(vector<Item>()) 
{}

void GildedRose::updateQuality() 
{
    for (Item& item : items)
    {
		item.preAdjustQuality();
        item.decrementSellIn();
		item.postAdjustQuality();
    }

	for (auto&& item : newItems)
	{
		item->preAdjustQuality();
		item->decrementSellIn();
		item->postAdjustQuality();
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
	if (quality > 0 && !isSulfuras()) {
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
		if (isBackstagePass()) {
			quality = 0;
		}
		else if (isAgedBrie()) {
			incrementQuality();
		}
		else {
			decrementQuality();
		}
	}
}

bool AgedBrie::isAgedBrie() const {
	return true;
}

std::shared_ptr<Item> ItemFactory::make(string name, int sellIn, int quality) {
	if (name == "Aged Brie") {
		return make_shared<AgedBrie>(name, sellIn, quality);
	}
	else {
		return make_shared<Item>(name, sellIn, quality);
	}
}

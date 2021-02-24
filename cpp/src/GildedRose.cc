#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) {
	for (auto&& item : items) {
		newItems.push_back(ItemFactory::make(item.name, item.getSellIn(), item.getQuality()));
	}
}
    
GildedRose::GildedRose(vector<shared_ptr<Item>> items)
	: newItems(std::move(items))
{}

void GildedRose::updateQuality() 
{
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

bool Item::isSulfuras() const {
    return name == "Sulfuras, Hand of Ragnaros";
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
	decrementQuality();
}

void Item::postAdjustQuality() {
	if (isPastSellIn())
	{
		decrementQuality();
	}
}

void ItemGettingBetterWithAge::preAdjustQuality() {
	incrementQuality();
}

void ItemGettingBetterWithAge::postAdjustQuality() {
	if (isPastSellIn())
	{
		incrementQuality();
	}
}

std::shared_ptr<Item> ItemFactory::make(string name, int sellIn, int quality) {
	if (name == "Aged Brie") {
		return make_shared<ItemGettingBetterWithAge>(name, sellIn, quality);
	}
	else if (name == "Backstage passes to a TAFKAL80ETC concert") {
		return make_shared<BackstagePass>(name, sellIn, quality);
	}
	else {
		return make_shared<Item>(name, sellIn, quality);
	}
}

void BackstagePass::preAdjustQuality() {
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

void BackstagePass::postAdjustQuality() {
	if (isPastSellIn())
	{
		quality = 0;
	}
}

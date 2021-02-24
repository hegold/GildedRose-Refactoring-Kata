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
		item->decrementSellInThenAdjustQualityIfPassedSellin();
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

void Item::decrementSellInThenAdjustQualityIfPassedSellin() {
	--sellIn;
	if (isPastSellIn()) {
		postAdjustQuality();
	}
}

void Item::decrementQuality() {
	if (quality > 0) {
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
	decrementQuality();
}

void ItemGettingBetterWithAge::preAdjustQuality() {
	incrementQuality();
}

void ItemGettingBetterWithAge::postAdjustQuality() {
	incrementQuality();
}

std::shared_ptr<Item> ItemFactory::make(string name, int sellIn, int quality) {
	if (name == "Aged Brie") {
		return make_shared<ItemGettingBetterWithAge>(name, sellIn, quality);
	}
	else if (name == "Backstage passes to a TAFKAL80ETC concert") {
		return make_shared<BackstagePass>(name, sellIn, quality);
	}
	else if (name == "Sulfuras, Hand of Ragnaros") {
		return make_shared<Sulfuras>(name, sellIn, quality);
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
	quality = 0;
}

void Sulfuras::decrementSellInThenAdjustQualityIfPassedSellin() {
	// Does not change sell in
}

void Sulfuras::decrementQuality() {
	// Does not lose quality
}


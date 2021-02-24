// Include header files for test frameworks 
#include <gtest/gtest.h>
#include <ApprovalTests.hpp>

// Include code to be tested
#include "GildedRose.h"

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
        << "name: " << obj.name
        << ", sellIn: " << obj.sellIn
        << ", quality: " << obj.quality;
}

TEST(GildedRoseApprovalTests, VerifyCombinations) {

	std::vector<string> names { 
		"+5 Dexterity Vest",
		"Foo",
		"Aged Brie",
		"Elixir of the Mongoose",
		"Sulfuras, Hand of Ragnaros",
		"Backstage passes to a TAFKAL80ETC concert",
		"Conjured Mana Cake" 
	};
    std::vector<int> sellIns { -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    std::vector<int> qualities { -1, 0, 6, 7, 19, 20, 29, 30, 49, 80, 1000 };

    auto f = [](string name, int sellIn, int quality) {
        vector<Item> items = {Item(name, sellIn, quality)};
        GildedRose app(items);
        app.updateQuality();
        return items[0];
    };

    ApprovalTests::CombinationApprovals::verifyAllCombinations(
            f,
            names, sellIns, qualities);

}

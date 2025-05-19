//
// Created by floron on 4/29/25.
//

#include "../headers/GameRNG.h"

#include "../headers/Exception.h"
#include "../headers/GameScreen.h"
#include "../headers/GameDataParser.h"

GameRNG::GameRNG(const std::string &game_data_location){
    faction_influence["ECLIPSE"] = 0;
    faction_influence["OMNITERRA"] = 0;
    faction_influence["LEGION"] = 0;
    faction_influence["CULT"] = 0;

    std::vector<Card> null_card;
    std::vector<int> null_change(4, 0);
    null_card.emplace_back(null_change, null_change, null_change, null_change, "", "back.png" );
    const CardPack null_pack("NULL_PACK", "back.png", null_card, false, "");
    card_packs["NULL_PACK"] = null_pack;
    GameDataParser::parseCardPacks(game_data_location, card_packs);

    current_card_index = 0;
    years_in_power = 0;
}

GameRNG::GameRNG(const std::string& game_data_location, const int game_seed_, const std::string &starting_pack) : GameRNG(game_data_location) {
    game_seed = game_seed_;
    current_pack_name = starting_pack;
}

/* TODO: FUNCTII UTILE, DA PLANGE CPPCHECK
// cppcheck-suppress getCurrentPackName
const std::string& GameRNG::getCurrentPackName() const {
    return current_pack_name;
}

// cppcheck-suppress getCurrentCardIndex
int GameRNG::getCurrentCardIndex() const {
    return current_card_index;
}

// cppcheck-suppress getCardPacksMap
const std::map<std::string, CardPack>& GameRNG::getCardPacksMap() {
    return card_packs;
}
*/
void GameRNG::pickNewPack() {
    std::string next_pack = getCurrentPack().getNextPackName();

    if (!next_pack.empty() && !card_packs.contains(next_pack)) {
        throw InvalidCardPack(next_pack);
    }

    current_pack_name = !next_pack.empty() ? next_pack : "GENERAL_PACK_1";

    current_card_index = 0;
    years_in_power++;
}

void GameRNG::nextCard(Constants::SwipeDirection direction) {
    if (const CardPack& current_pack = getCurrentPack(); current_card_index == current_pack.size() - 1) {
        if (current_pack.isFinalPack()) {
            if (current_pack_name == "FINAL_ECLIPSE_PACK") {
                game_ended = true;
                return;
            }
        }
        else {
            pickNewPack();
            return;
        }
    }

    Card& current_card = getCurrentCard();
    const std::vector<int> &change = direction == Constants::SwipeDirection::Left ? current_card.getLeftChange() : current_card.getRightChange();
    const std::vector<int> &change_factions = direction == Constants::SwipeDirection::Left ? current_card.getLeftFactionChange() : current_card.getRightFactionChange();
    industry += change[0];
    popularity += change[1];
    power += change[2];
    finances += change[3];

    faction_influence["ECLIPSE"] += change_factions[0];
    faction_influence["OMNITERRA"] += change_factions[1];
    faction_influence["LEGION"] += change_factions[2];
    faction_influence["CULT"] += change_factions[3];

    current_card_index++;
}

Card& GameRNG::getCurrentCard() {
    if (const auto pack_it = card_packs.find(current_pack_name); pack_it == card_packs.end() || pack_it->second.size() <= current_card_index) {
        throw CardOutOfBounds(current_pack_name, current_card_index);
    }

    return getCurrentPack()[current_card_index];
}

Card& GameRNG::getNextCard() {
    if (current_card_index == getCurrentPack().size() - 1) {
        return card_packs["NULL_PACK"][0];
    }

    const auto pack_it = card_packs.find(current_pack_name);
    if (pack_it == card_packs.end() || pack_it->second.size() <= current_card_index + 1) {
        throw CardOutOfBounds(current_pack_name, current_card_index + 1);
    }
    return pack_it->second[current_card_index + 1];
}

const std::string& GameRNG::getCurrentPackCardBackLocation() {
    return card_packs[current_pack_name].getPackCardBackLocation();
}

CardPack& GameRNG::getCurrentPack() {
    return card_packs[current_pack_name];
}

int GameRNG::getValue(Constants::GameRNGValues value) const {
    switch (value) {
        case Constants::GameRNGValues::Industry:
            return industry;
        case Constants::GameRNGValues::Popularity:
            return popularity;
        case Constants::GameRNGValues::Power:
            return power;
        case Constants::GameRNGValues::Finances:
            return finances;
        default:
            return 0;
    }
}

int GameRNG::getYearsInPower() const {
    return years_in_power;
}

bool GameRNG::hasGameEnded() const {
    return game_ended;
}
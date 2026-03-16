#include "../default.h"
#include "player.h"


struct Splayer{
    char nickname[16];
    u16 playerClass;
    u32 hitpoints;
    u32 manapoints;
    u16 playerLevel;

    u16 strength;
    u16 agility;
    u16 intellect;
    u16 stamina;

    u16 attackPower;
    u16 criticalStrike;
    u16 spellPower;

    u32 armor;

    u16 movementSpeed;
    u16 playerLight;
    // FULL Player is 134Bytes
};

struct Sequiment{
    u16 helmetID;
    u16 neckID;
    u16 chestID;
    u16 backID;
    u16 handsID;
    u16 legsID;
    u16 feetID;
    u16 ringID;
    
    u16 mainSlotID;
    u16 offhandSlotID;

    // Overall 20Bytes
};

struct Sbackpack{
    u32 item1ID;
    u32 item2ID;
    u32 item3ID;
    u32 item4ID;

    u32 item5ID;
    u32 item6ID;
    u32 item7ID;
    u32 item8ID;

    u32 item9ID;
    u32 item10ID;
    u32 item11ID;
    u32 item12ID;

    u32 item13ID;
    u32 item14ID;
    u32 item15ID;
    u32 item16ID;

    // Overall 64Bytes
};
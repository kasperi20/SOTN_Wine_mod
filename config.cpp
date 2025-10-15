#include "script_component.hpp"

class cfgPatches {
    class ADDON {
        name = "SOTN Wine";
        author = "Feeniks_FIN";

        units[] = {
            "SOTN_Wine_Item",
            "SOTN_Wine_Half_Item",
            "SOTN_Wine_Empty_Item"
        };
        weapons[] = {
            "SOTN_Wine",
            "SOTN_Wine_Half",
            "SOTN_Wine_Empty"
        };
		requiredVersion = 0.1;
        requiredAddons[] = { "CBA_main", "ace_interact_menu" };
    };
};

class cfgWeapons {
    class ACE_Canteen;
    class CBA_MiscItem_ItemInfo;

    class SOTN_Wine: ACE_Canteen
    {
        author = "Feeniks_FIN";
        displayName = "Wine bottle";
        scope = 2;
        descriptionShort = CSTRING(Wine_Bottle_Description);
        model = "x\exz\addons\SOTN_Wine\winebottle";
        picture = QPATHTOF(Data\wine_bottle_icon_co.paa);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 5;
        };
        XGVAR(consumeTime) = 10;
        XGVAR(thirstQuenched) = 10;
        XGVAR(consumeText) = CSTRING(DrinkingFromX);
        acex_field_rations_replacementItem = "SOTN_Wine_Half";
        XGVAR(consumeAnims)[] = {QGVAR(drinkStand), QGVAR(drinkCrouch), QGVAR(drinkProne)};
        XGVAR(consumeSounds)[] = {QGVAR(drink1), QGVAR(drink1), QGVAR(drink2)};
        ACE_isFieldRationItem = 1;
    };

    class SOTN_Wine_Half: SOTN_Wine
    {
        author = "Feeniks_FIN";
        displayName = "Wine bottle half";
        descriptionShort = CSTRING(Wine_Bottle_Half_Description);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 3;
        };
        acex_field_rations_replacementItem = "SOTN_Wine_Empty";
        XGVAR(refillItem) = "SOTN_Wine";
        XGVAR(refillAmount) = 0.5;
        XGVAR(refillTime) = 8;
    };

    class SOTN_Wine_Empty: SOTN_Wine {
        author = "Feeniks_FIN";
        displayName = "Wine bottle empty";
        descriptionShort = CSTRING(Wine_Bottle_Empty_Description);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
        XGVAR(refillItem) = "SOTN_Wine";
        XGVAR(thirstQuenched) = 0;
        XGVAR(replacementItem) = "";
        XGVAR(refillAmount) = 1;
        XGVAR(refillTime) = 8;
    };

};

class cfgVehicles {
    class Item_Base_F; //Base calss for items

    class SOTN_Wine_Item: Item_Base_F
    {
        author = "Feeniks_FIN";
        scope = 2;
        scopeCurator = 2;
        displayName = "wine bottle";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(SOTN_Wine, 1);
       };
    };

    class SOTN_Wine_Half_Item: Item_Base_F {
        author = "Feeniks_FIN";
        scope = 2;
        scopeCurator = 2;
        displayName = "wine bottle half";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(SOTN_Wine,1);
        };
    };
    
    class SOTN_Wine_Empty_Item: Item_Base_F {
        author = "Feeniks_FIN";
        scope = 2;
        scopeCurator = 2;
        displayName = "wine bottle empty";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(SOTN_Wine,1);
        };
    };
};
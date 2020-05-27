class CfgPatches {
    class vk_pn_manpad {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"ace_missileguidance"};
    };
};

class Extended_PreInit_EventHandlers {
    class vk_pn_manpad {
        init = "vk_pn_fnc_attackProfile_MANPAD = compile preprocessFileLineNumbers '\vk_pn_manpad\fnc_attackProfile_MANPAD.sqf'";
    };
};

class Ace_missileguidance_AttackProfiles {
    class vk_pn_manpad {
        name = "";
        visualName = "";
        description = "";

        functionName = "vk_pn_fnc_attackProfile_MANPAD";
    };
};

class CfgMagazineWells {
    class Titan_Long {
        vk_pnav[] = {"vk_pnav_Titan_AA"};
    };
};


#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"

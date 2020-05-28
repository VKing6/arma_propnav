class CfgPatches {
    class vk_pn_manpad {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"vk_pn_guidance"};
    };
};

class CfgMagazineWells {
    class Titan_Long {
        vk_pn[] = {"vk_pn_Titan_AA"};
    };
};


#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"

class CfgPatches {
    class manpad_guidance_test {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {};
    };
};

class Extended_PreInit_EventHandlers {
    class manpad_test {
        init = "pnav_fnc_fired = compile preprocessFileLineNumbers '\vk_pnav_manpad\pnav_fnc_fired.sqf'";
    };
};
class Extended_FiredBIS_EventHandlers {
    class All {
        fired = "_this call pnav_fnc_fired";
    };
};

class CfgAmmo {
    class MissileBase;
    class M_Titan_AA: MissileBase {

    };
};
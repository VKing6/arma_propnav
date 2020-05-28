class CfgPatches {
    class vk_pn_guidance {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"ace_missileguidance"};
    };
};

class Extended_PreInit_EventHandlers {
    class vk_pn_guidance {
        init = "call compile preprocessFileLineNumbers '\vk_pn_guidance\XEH_PreInit.sqf'";
    };
};

class Ace_missileguidance_AttackProfiles {
    class vk_pn_sam {
        name = "";
        visualName = "";
        description = "";

        functionName = "vk_pn_fnc_attackProfile_sam";
    };
    class vk_pn_sam_vls {
        name = "";
        visualName = "";
        description = "";

        functionName = "vk_pn_fnc_attackProfile_sam_vls";
    };
};

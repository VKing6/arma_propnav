class CfgPatches {
    class vk_pn_vls {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"ace_missileguidance"};
    };
};

class Extended_PreInit_EventHandlers {
    class vk_pn_vls {
        init = "vk_pn_fnc_attackProfile_VLS = compile preprocessFileLineNumbers '\vk_pn_vls\fnc_attackProfile_vls.sqf'";
    };
};

class Ace_missileguidance_AttackProfiles {
    class vk_pn_vls {
        name = "";
        visualName = "";
        description = "";

        functionName = "vk_pn_fnc_attackProfile_VLS";
    };
};

class CfgWeapons {
    class weapon_VLS_01;
    class vk_pnav_VLS_SAM: weapon_VLS_01 {
        displayname = "RIM-145(v) VLS";
        magazines[] = {"vk_pnav_16rnd_rim145_vls"};
    };
};

class CfgMagazines {
    class magazine_Missile_mim145_x4;
    class vk_pnav_16rnd_rim145_vls: magazine_Missile_mim145_x4 {
        displayName = "RIM-145(v)";
        descriptionShort = "RIM-145(v) Surface-to-Air Missile";
        ammo = "vk_pnav_M_rim145";
        count = 16;
        initSpeed = 50;
    };
};

class CfgAmmo {
    class ammo_Missile_mim145;
    class vk_pnav_M_rim145: ammo_Missile_mim145 {
        initTime = 0.6;
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.001;      // Minium flap deflection for guidance
            //maxDeflection = 0.025;       // Maximum flap deflection for guidance
            maxDeflection = 0.05;       // Maximum flap deflection for guidance
            incDeflection = 0.001;      // The incrmeent in which deflection adjusts.
            canVanillaLock = 1;

            defaultSeekerType = "ARH";
            seekerTypes[] = { "Optic", "ARH" }; 
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL", "LOAL" };

            seekerAngle = 120;
            seekerAccuracy = 1;

            seekerMinRange = 0;
            seekerMaxRange = 15000;

            defaultAttackProfile = "vk_pn_vls";
            attackProfiles[] = { "vk_pn_vls" };
        };
    };
};
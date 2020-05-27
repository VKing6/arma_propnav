class CfgPatches {
    class vk_pn_vls {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"itc_land_vls","ace_missileguidance"};
    };
};

class Extended_PreInit_EventHandlers {
    class vk_pn_vls {
        init = "vk_pn_fnc_attackProfile_VLS = compile preprocessFileLineNumbers '\vk_pn_vls\fnc_attackProfile_sam_vls.sqf'";
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

class CfgVehicles {
    class StaticWeapon;
    class StaticMGWeapon : StaticWeapon {
        class Turrets {
            class MainTurret;
        };
    };
    class B_Ship_MRLS_01_base_F : StaticMGWeapon {
        class Turrets : Turrets {
            class MainTurret: MainTurret {};
        };
        class AnimationSources {
            class Missiles_revolving;
        };
    };
    class itc_land_b_vls2 : B_Ship_MRLS_01_base_F {};
    class vk_pnav_b_vls2_mod: itc_land_b_vls2 {
        displayName = "MN230(v)K VLS (Air Defense)";
        class Turrets : Turrets {
            class MainTurret: MainTurret {
                weapons[] = {"vk_pnav_mn230essm_mod_launcher"};
                magazines[] = {"vk_pnav_mn230essm_mod_x18"};
            };
        };
        class AnimationSources: AnimationSources {
            class Missiles_revolving: Missiles_revolving {
                weapon = "vk_pnav_mn230essm_mod_launcher";
            };
        };
    };
};

class CfgWeapons {
    class itc_land_mn230essm_launcher;
    class vk_pnav_mn230essm_mod_launcher: itc_land_mn230essm_launcher {
        magazines[] = {"vk_pnav_mn230essm_mod_x18"};
    };
};

class CfgMagazines {
    class itc_land_mn230essm_x18;
    class vk_pnav_mn230essm_mod_x18: itc_land_mn230essm_x18 {
        ammo = "vk_pnav_ammo_mn230_essm_mod";
        initSpeed = 30;
    };
};

class CfgAmmo {
    class itc_land_ammo_mn230_essm;
    class vk_pnav_ammo_mn230_essm_mod: itc_land_ammo_mn230_essm {
        initTime = 1;
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.000;      // Minium flap deflection for guidance
            //maxDeflection = 0.025;       // Maximum flap deflection for guidance
            maxDeflection = 0.01;       // Maximum flap deflection for guidance
            incDeflection = 0.001;      // The incrmeent in which deflection adjusts.
            canVanillaLock = 1;

            defaultSeekerType = "ARH";
            seekerTypes[] = { "Optic", "ARH" }; 
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL", "LOAL" };

            seekerAngle = 120;
            seekerAccuracy = 1;

            seekerMinRange = 0;
            seekerMaxRange = 20000;

            defaultAttackProfile = "vk_pn_vls";
            attackProfiles[] = { "vk_pn_vls" };
        };
    };
};
class CfgPatches {
    class vk_pn_manpad {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"ace_missileguidance"};
    };
};

class Extended_PreInit_EventHandlers {
    class manpad_test {
        init = "vk_pn_fnc_attackProfile_MANPAD = compile preprocessFileLineNumbers '\vk_pn_manpad\fnc_attackProfile_MANPAD.sqf'";
    };
};

class Ace_missileguidance_AttackProfiles {
    class vk_pn_MANPAD {
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

class CfgWeapons {
    class Launcher_Base_F;
    class launch_Titan_base: Launcher_Base_F {
        weaponLockDelay = 0.1;
    };
    class launch_O_Titan_F;
    class rhs_weap_fim92: launch_O_Titan_F {
        weaponLockDelay = 0.1;
        magazines[] = {"rhs_fim92_mag", "vk_pnav_fim92_mag"};
        magazineWell[] = {};
    };
    class rhs_weap_strela;
    class rhs_weap_igla: rhs_weap_strela {
        weaponLockDelay = 0.1;
        magazines[] = {"rhs_mag_9k38_rocket", "vk_pnav_9k38_mag"};
        magazineWell[] = {};
    };
    class rhs_weap_TOW_Launcher;
    class rhs_weap_stinger_Launcher: rhs_weap_TOW_Launcher {
        weaponLockDelay = 0.1;
        magazines[] = {"rhs_mag_4Rnd_stinger", "rhs_mag_2Rnd_stinger",
                       "vk_pnav_4Rnd_stinger", "vk_pnav_2Rnd_stinger"};
    };
};

class CfgMagazines {
    class CA_LauncherMagazine;
    class Titan_AA: CA_LauncherMagazine {};
    class vk_pnav_Titan_AA: Titan_AA {
        displayName = "Super Titan AA";
        ammo = "vk_pnav_M_Titan_AA";
        initSpeed = 60;
        ace_overpressure_priority = 5;
        ace_overpressure_angle = 30;
        ace_overpressure_range = 1;
        ace_overpressure_damage = 0.2;
    };
    class rhs_fim92_mag: Titan_AA {};
    class vk_pnav_fim92_mag: rhs_fim92_mag {
        displayName = "FIM-92(v)K";
        ammo = "vk_pnav_fim92_missile";
        ace_overpressure_priority = 5;
        ace_overpressure_angle = 30;
        ace_overpressure_range = 1;
        ace_overpressure_damage = 0.2;
    };
    class rhs_mag_9k38_rocket;
    class vk_pnav_9k38_mag: rhs_mag_9k38_rocket {
        displayName = "9K38Vk";
        ammo = "vk_pnav_9k38_missile";
        ace_overpressure_priority = 5;
        ace_overpressure_angle = 30;
        ace_overpressure_range = 1;
        ace_overpressure_damage = 0.2;
    };

    class rhs_mag_4Rnd_stinger;
    class vk_pnav_4Rnd_stinger: rhs_mag_4Rnd_stinger {
        ammo = "vk_pnav_fim92_missile";
        displayname = "FIM-92(v)K Stinger";
        displaynameshort = "FIM-92(v)K";
        initspeed = 60;
    };
    class rhs_mag_2Rnd_stinger;
    class vk_pnav_2Rnd_stinger: rhs_mag_2Rnd_stinger {
        ammo = "vk_pnav_fim92_missile";
        displayname = "FIM-92(v)K Stinger";
        displaynameshort = "FIM-92(v)K";
        initspeed = 60;
    };
};

class CfgAmmo {
    class MissileBase;
    class M_Titan_AA: MissileBase {};
    class vk_pnav_M_Titan_AA: M_Titan_AA {
        initTime = 0.2;
    
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.001;      // Minium flap deflection for guidance
            //maxDeflection = 0.025;       // Maximum flap deflection for guidance
            maxDeflection = 0.05;       // Maximum flap deflection for guidance
            incDeflection = 0.001;      // The incrmeent in which deflection adjusts.
            canVanillaLock = 1;

            defaultSeekerType = "Optic";
            seekerTypes[] = { "Optic", "Thermal" }; 
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL", "LOAL" };

            seekerAngle = 120;
            seekerAccuracy = 1;

            seekerMinRange = 0;
            seekerMaxRange = 5000;

            defaultAttackProfile = "vk_pn_MANPAD";
            attackProfiles[] = { "vk_pn_MANPAD" };
        };
    };
    class rhs_ammo_fim92_missile: M_Titan_AA {};
    class vk_pnav_fim92_missile: rhs_ammo_fim92_missile {
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.001;      // Minium flap deflection for guidance
            //maxDeflection = 0.025;       // Maximum flap deflection for guidance
            maxDeflection = 0.05;       // Maximum flap deflection for guidance
            incDeflection = 0.001;      // The incrmeent in which deflection adjusts.
            canVanillaLock = 1;

            defaultSeekerType = "Optic";
            seekerTypes[] = { "Optic", "Thermal" }; 
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL", "LOAL" };

            seekerAngle = 120;
            seekerAccuracy = 1;

            seekerMinRange = 0;
            seekerMaxRange = 5000;

            defaultAttackProfile = "vk_pn_MANPAD";
            attackProfiles[] = { "vk_pn_MANPAD" };
        };
    };
    class rhs_ammo_9k38;
    class vk_pnav_9k38_missile: rhs_ammo_9k38 {
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.001;      // Minium flap deflection for guidance
            //maxDeflection = 0.025;       // Maximum flap deflection for guidance
            maxDeflection = 0.05;       // Maximum flap deflection for guidance
            incDeflection = 0.001;      // The incrmeent in which deflection adjusts.
            canVanillaLock = 1;

            defaultSeekerType = "Optic";
            seekerTypes[] = { "Optic", "Thermal" }; 
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL", "LOAL" };

            seekerAngle = 120;
            seekerAccuracy = 1;

            seekerMinRange = 0;
            seekerMaxRange = 5000;

            defaultAttackProfile = "vk_pn_MANPAD";
            attackProfiles[] = { "vk_pn_MANPAD" };
        };
    };
};
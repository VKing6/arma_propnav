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

class CfgMagazines {
    class CA_LauncherMagazine;
    class Titan_AA: CA_LauncherMagazine {
        initSpeed = 60;
        ace_overpressure_priority = 5;
        ace_overpressure_angle = 30;
        ace_overpressure_range = 1;
        ace_overpressure_damage = 0.2;
    };
};

class CfgAmmo {
    class MissileBase;
    class M_Titan_AA: MissileBase {
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
};
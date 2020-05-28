class CfgAmmo {
    class MissileBase;
    class M_Titan_AA: MissileBase {};
    class vk_pn_M_Titan_AA: M_Titan_AA {
        initTime = 0.2;
    
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.0;      // Minium flap deflection for guidance
            maxDeflection = 0.025;       // Maximum flap deflection for guidance
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

            defaultAttackProfile = "vk_pn_manpad";
            attackProfiles[] = { "vk_pn_manpad" };
        };
    };
};
class CfgAmmo {
    class itc_land_ammo_mn230_essm;
    class vk_pn_ammo_mn230_essm_mod: itc_land_ammo_mn230_essm {
        initTime = 1;
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.000;      // Minium flap deflection for guidance
            maxDeflection = 0.01;       // Maximum flap deflection for guidance
            incDeflection = 0.001;      // The incrmeent in which deflection adjusts.
            canVanillaLock = 1;

            defaultSeekerType = "ARH";
            seekerTypes[] = { "ARH" }; 
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            seekerAngle = 120;
            seekerAccuracy = 1;

            seekerMinRange = 0;
            seekerMaxRange = 20000;

            defaultAttackProfile = "vk_pn_sam_vls";
            attackProfiles[] = { "vk_pn_sam_vls" };
        };
    };
};
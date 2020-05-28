class CfgAmmo {
    class ammo_Missile_rim116;
    class vk_pn_rim116_missile: ammo_Missile_rim116 {
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
            seekerMaxRange = 8000;

            defaultAttackProfile = "vk_pn_sam";
            attackProfiles[] = { "vk_pn_sam" };
        };
    };
    class ammo_Missile_rim162;
    class vk_pn_rim162_missile: ammo_Missile_rim162 {
        class ace_missileguidance {
            enabled = 1;
            
            minDeflection = 0.000;      // Minium flap deflection for guidance
            maxDeflection = 0.01;       // Maximum flap deflection for guidance
            incDeflection = 0.001;      // The incrmeent in which deflection adjusts.
            canVanillaLock = 1;

            defaultSeekerType = "ARH";
            seekerTypes[] = {  "ARH" }; 
            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            seekerAngle = 120;
            seekerAccuracy = 1;

            seekerMinRange = 0;
            seekerMaxRange = 12000;

            defaultAttackProfile = "vk_pn_sam";
            attackProfiles[] = { "vk_pn_sam" };
        };
    };
    class ammo_Missile_mim145;
    class vk_pn_mim145_missile: ammo_Missile_mim145 {
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
            seekerMaxRange = 25000;

            defaultAttackProfile = "vk_pn_sam";
            attackProfiles[] = { "vk_pn_sam" };
        };
    };
    class vk_pn_s750_missile: vk_pn_mim145_missile {
        model = "\A3\Weapons_F_Sams\Ammo\Missile_SAM_04_fly_F.p3d";
        proxyShape = "\A3\Weapons_F_Sams\Ammo\Missile_SAM_04_fly_F.p3d";
    };
};
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
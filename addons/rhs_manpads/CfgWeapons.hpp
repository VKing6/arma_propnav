class CfgWeapons {
    class launch_O_Titan_F;
    class rhs_weap_fim92: launch_O_Titan_F {
        weaponLockDelay = 0.1;
        magazines[] = {"rhs_fim92_mag", "vk_pn_fim92_mag"};
        magazineWell[] = {};
    };
    class rhs_weap_strela;
    class rhs_weap_igla: rhs_weap_strela {
        weaponLockDelay = 0.1;
        magazines[] = {"rhs_mag_9k38_rocket", "vk_pn_9k38_mag"};
        magazineWell[] = {};
    };
    class rhs_weap_TOW_Launcher;
    class rhs_weap_stinger_Launcher: rhs_weap_TOW_Launcher {
        weaponLockDelay = 0.1;
        magazines[] = {"rhs_mag_4Rnd_stinger", "rhs_mag_2Rnd_stinger",
                       "vk_pn_4Rnd_stinger", "vk_pn_2Rnd_stinger"};
    };
};
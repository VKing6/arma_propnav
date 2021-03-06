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
class CfgVehicles {
    class StaticMGWeapon;
    class SAM_System_01_base_F: StaticMGWeapon {
        class Turrets;
    };
    class B_SAM_System_01_F: SAM_System_01_base_F {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class vk_pn_rim116ram: B_SAM_System_01_F {
        displayName = "RIM-116(v)K RAM";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {"vk_pn_rim116_mag_x21"};
            };
        };
    };

    class SAM_System_02_base_F: StaticMGWeapon {
        class Turrets;
    };
    class B_SAM_System_02_F: SAM_System_02_base_F {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class vk_pn_rim162essm: B_SAM_System_02_F {
        displayName = "RIM-162(v)K ESSM";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {"vk_pn_rim162_mag_x8"};
            };
        };
    };

    class SAM_System_03_base_F: StaticMGWeapon {
        class Turrets;
    };
    class B_SAM_System_03_F: SAM_System_03_base_F {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class vk_pn_mim145: B_SAM_System_03_F {
        displayName = "MIM-145(v)K";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {"vk_pn_mim145_mag_x4"};
            };
        };
    };

    class SAM_System_04_base_F: StaticMGWeapon {
        class Turrets;
    };
    class O_SAM_System_04_F: SAM_System_04_base_F {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class vk_pn_s750: O_SAM_System_04_F {
        displayName = "S750 ВК";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {"vk_pn_s750_mag_x4"};
            };
        };
    };
};
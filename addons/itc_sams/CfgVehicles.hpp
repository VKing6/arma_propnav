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
    class vk_pn_b_vls2_mod: itc_land_b_vls2 {
        displayName = "MN230(v)K VLS (Air Defense)";
        class Turrets : Turrets {
            class MainTurret: MainTurret {
                weapons[] = {"vk_pn_mn230essm_mod_launcher"};
                magazines[] = {"vk_pn_mn230essm_mod_x18"};
            };
        };
        class AnimationSources: AnimationSources {
            class Missiles_revolving: Missiles_revolving {
                weapon = "vk_pn_mn230essm_mod_launcher";
            };
        };
    };
};
class CfgVehicles {
    class LandVehicle;
    class Tank: LandVehicle {
        class NewTurret;
        class Sounds;
        class HitPoints;
        class CommanderOptics;
    };
    class Tank_F: Tank {
        class Turrets {
            class MainTurret: NewTurret {
                class Turrets {
                    class CommanderOptics;
                };
            };
        };
        class AnimationSources;
        class ViewPilot;
        class ViewOptics;
        class ViewCargo;
        class HeadLimits;
        class HitPoints: HitPoints {
            class HitHull;
            class HitEngine;
            class HitLTrack;
            class HitRTrack;
        };
        class Sounds: Sounds {
            class Engine;
            class Movement;
        };
        class EventHandlers;
    };
    class APC_Tracked_03_base_F: Tank_F {};
    class RHS_M2A2_Base: APC_Tracked_03_base_F {};
    class RHS_M6: RHS_M2A2_Base {};
    class vk_pnav_M6: RHS_M6 {
        displayName = "M2A6(v)";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {"rhs_mag_1100Rnd_762x51_M240", "rhs_mag_1100Rnd_762x51_M240",
                    "vk_pnav_4Rnd_stinger", "vk_pnav_4Rnd_stinger", "vk_pnav_4Rnd_stinger",
                    "rhs_mag_70Rnd_25mm_M242_APFSDS", "rhs_mag_230Rnd_25mm_M242_HEI", 
                    "rhs_mag_70Rnd_25mm_M242_APFSDS", "rhs_mag_230Rnd_25mm_M242_HEI", 
                    "rhs_laserfcsmag", "rhs_laserfcsmag"};
            };
        };
        class TransportMagazines {
            class _xx_rhs_mag_30Rnd_556x45_M855A1_Stanag {
                magazine = "rhs_mag_30Rnd_556x45_M855A1_Stanag";
                count = 75;
            };
            class _xx_rhsusf_100Rnd_556x45_soft_pouch {
                magazine = "rhsusf_100Rnd_556x45_soft_pouch";
                count = 11;
            };
            class _xx_rhsusf_100Rnd_762x51 {
                magazine = "rhsusf_100Rnd_762x51";
                count = 11;
            };
            class _xx_rhs_fim92_mag {
                magazine = "vk_pnav_fim92_mag";
                count = 4;
            };
            class _xx_rhs_mag_M441_HE {
                magazine = "rhs_mag_M441_HE";
                count = 20;
            };
            class _xx_rhs_mag_M714_white {
                magazine = "rhs_mag_M714_white";
                count = 8;
            };
            class _xx_rhs_mag_M662_red {
                magazine = "rhs_mag_M662_red";
                count = 4;
            };
            class _xx_rhs_mag_m67 {
                magazine = "rhs_mag_m67";
                count = 10;
            };
            class _xx_rhs_mag_m18_green {
                magazine = "rhs_mag_m18_green";
                count = 4;
            };
            class _xx_rhs_mag_m18_red {
                magazine = "rhs_mag_m18_red";
                count = 4;
            };
            class _xx_rhs_mag_an_m8hc {
                magazine = "rhs_mag_an_m8hc";
                count = 10;
            };
            class _xx_rhs_M136_mag {
                magazine = "rhs_M136_mag";
                count = 2;
            };
        };
    };
    class RHS_M6_wd: RHS_M6 {};
	class vk_pnav_M6_wd: RHS_M6_wd {
        displayName = "M2A6(v)";
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {"rhs_mag_1100Rnd_762x51_M240", "rhs_mag_1100Rnd_762x51_M240",
                    "vk_pnav_4Rnd_stinger", "vk_pnav_4Rnd_stinger", "vk_pnav_4Rnd_stinger",
                    "rhs_mag_70Rnd_25mm_M242_APFSDS", "rhs_mag_230Rnd_25mm_M242_HEI", 
                    "rhs_mag_70Rnd_25mm_M242_APFSDS", "rhs_mag_230Rnd_25mm_M242_HEI", 
                    "rhs_laserfcsmag", "rhs_laserfcsmag"};
            };
        };
        class TransportMagazines {
            class _xx_rhs_mag_30Rnd_556x45_M855A1_Stanag {
                magazine = "rhs_mag_30Rnd_556x45_M855A1_Stanag";
                count = 75;
            };
            class _xx_rhsusf_100Rnd_556x45_soft_pouch {
                magazine = "rhsusf_100Rnd_556x45_soft_pouch";
                count = 11;
            };
            class _xx_rhsusf_100Rnd_762x51 {
                magazine = "rhsusf_100Rnd_762x51";
                count = 11;
            };
            class _xx_rhs_fim92_mag {
                magazine = "vk_pnav_fim92_mag";
                count = 4;
            };
            class _xx_rhs_mag_M441_HE {
                magazine = "rhs_mag_M441_HE";
                count = 20;
            };
            class _xx_rhs_mag_M714_white {
                magazine = "rhs_mag_M714_white";
                count = 8;
            };
            class _xx_rhs_mag_M662_red {
                magazine = "rhs_mag_M662_red";
                count = 4;
            };
            class _xx_rhs_mag_m67 {
                magazine = "rhs_mag_m67";
                count = 10;
            };
            class _xx_rhs_mag_m18_green {
                magazine = "rhs_mag_m18_green";
                count = 4;
            };
            class _xx_rhs_mag_m18_red {
                magazine = "rhs_mag_m18_red";
                count = 4;
            };
            class _xx_rhs_mag_an_m8hc {
                magazine = "rhs_mag_an_m8hc";
                count = 10;
            };
            class _xx_rhs_M136_mag {
                magazine = "rhs_M136_mag";
                count = 2;
            };
        };
    };
};
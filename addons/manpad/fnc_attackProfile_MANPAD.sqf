/*
 * Author: VKing
 * Attack profile: MANPADS
 *
 * Arguments:
 * 0: Seeker Target PosASL <ARRAY>
 * 1: Guidance Arg Array <ARRAY>
 * 2: Attack Profile State <ARRAY>
 *
 * Return Value:
 * Missile Aim PosASL <ARRAY>
 *
 * Example:
 * [[1,2,3], [], []] call ace_missileguidance_fnc_attackProfile_LIN;
 *
 * Public: No
 */
// #define DEBUG_MODE_FULL
//#include "script_component.hpp"

#define STAGE_LAUNCH 1
#define STAGE_BOOST 2
#define STAGE_TERMINAL 3

params ["_seekerTargetPos", "_args","_attackProfileStateParams"];
_args params ["_firedEH", "_launchParams"];
_launchParams params ["","_targetLaunchParams"];
_targetLaunchParams params ["_target", "", "_launchPos"];
_firedEH params ["_shooter","_weapon","","","","","_projectile","_gunner"];


if (_seekerTargetPos isEqualTo [0,0,0]) exitWith {_seekerTargetPos};


if (_attackProfileStateParams isEqualTo []) then {
    _attackProfileStateParams set [0, STAGE_LAUNCH];

    private _wepDir = (_shooter weaponDirection _weapon) call CBA_fnc_vect2polar;
    private _initAimOffset = [100, _wepDir # 1, _wepDir # 2] call CBA_fnc_polar2vect;
    private _initTargetPos = getPosASL _shooter vectorAdd (_initAimOffset);
    _attackProfileStateParams set [1, _initTargetPos];
};

private _wep = _projectile;
private _tgt = _target;
private _wpos = _projectile modelToWorldWorld [0,0,0];
private _tpos = getposASL _tgt;


private _distanceToShooter = _wpos vectorDistance _launchPos;
private _distanceToTarget = _wpos vectorDistance _tpos;
private _RTM = _tpos vectorDiff _wpos;
private _Vca = vectorMagnitude (velocity _wep vectorDiff velocity _tgt);
private _tgo = if (_Vca != 0) then {vectorMagnitude _RTM / _Vca} else {0};
private _intercept = _tpos vectorAdd ((velocity _tgt) vectorMultiply (_tgo min 4));

private _returnTargetPos = _seekerTargetPos;



switch (_attackProfileStateParams select 0) do {
    case STAGE_LAUNCH: {
        if (_distanceToShooter < 15) then {
            _returnTargetPos = _attackProfileStateParams select 1;
        } else {
            _attackProfileStateParams set [0, STAGE_BOOST];
        };
    };
    case STAGE_BOOST: {
        if (_distanceToShooter < 50) then {
            _returnTargetPos = _tpos;
        } else {
            _attackProfileStateParams set [0, STAGE_TERMINAL];
        };
    };
    case STAGE_TERMINAL: {
        _returnTargetPos = _intercept;
        //_returnTargetPos = _seekerTargetPos;
        if (_distanceToTarget < 5) then {
            triggerAmmo _wep;
            #ifdef DEBUG_MODE_FULL 
                player sideChat "Fuze!";
            #endif
        };
    };
};

#ifdef DEBUG_MODE_FULL

drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\explosive_ca.paa", [0,1,0,1], ASLtoAGL (_attackProfileStateParams select 1), 0.75, 0.75, 0, "Init", 1, 0.025, "TahomaB"];

drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\board_ca.paa", [0,1,0,1], ASLtoAGL _intercept, 0.75, 0.75, 0, "Intercept", 1, 0.025, "TahomaB"];
drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\board_ca.paa", [1,0,1,1], ASLtoAGL _seekerTargetPos, 0.75, 0.75, 0, "ACE_Intercept", 1, 0.025, "TahomaB"];

drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\attack_ca.paa", [1,0,0,1], ASLtoAGL _returnTargetPos, 0.75, 0.75, 0, "", 1, 0.025, "TahomaB"];

drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selectover_ca.paa", [1,0,0,1], ASLtoAGL _wpos, 0.75, 0.75, 0, "SAM", 1, 0.025, "TahomaB"];

drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\explosive_ca.paa", [0,1,1,1], ASLtoAGL _tpos, 0.75, 0.75, 0, "Target", 1, 0.025, "TahomaB"];

private _ps = "#particlesource" createVehicleLocal (ASLtoAGL _wpos);
_PS setParticleParams [["\A3\Data_f\cl_basic", 8, 3, 1], "", "Billboard", 1, 3.0141, [0, 0, 2], [0, 0, 0], 1, 1.275, 1, 0, [1, 1], [[1, 1, 0, 1], [1, 1, 0, 1], [1, 1, 0, 1]], [1], 1, 0, "", "", nil];
_PS setDropInterval 3.0;
private _tps = "#particlesource" createVehicleLocal (ASLtoAGL _tpos);
_tps setParticleParams [["\A3\Data_f\cl_basic", 8, 3, 1], "", "Billboard", 1, 3.0141, [0, 0, 2], [0, 0, 0], 1, 1.275, 1, 0, [1, 1], [[1, 0, 0, 1], [1, 0, 0, 1], [1, 0, 0, 1]], [1], 1, 0, "", "", nil];
_tps setDropInterval 3.0;

#endif //DEBUG_MODE_FULL

_returnTargetPos;

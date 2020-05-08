/*
 * Author: VKing
 * Attack profile: VLS SAM
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
_firedEH params ["_shooter","","","","","","_projectile"];


if (_seekerTargetPos isEqualTo [0,0,0]) exitWith {_seekerTargetPos};


if (_attackProfileStateParams isEqualTo []) then {
    _attackProfileStateParams set [0, STAGE_LAUNCH];

	private _initTargetPos = getPosASL _shooter vectorAdd [0,0,100];
    _attackProfileStateParams set [1, _initTargetPos];
};

private _wep = _projectile;
private _tgt =_target;
private _wpos = _projectile modelToWorldWorld [0,0,0];
private _tpos = _seekerTargetPos;

private _distanceToShooter = _wpos vectorDistance _launchPos;

private _RTM = _tpos vectorDiff _wpos;
private _Vca = vectorMagnitude (velocity _wep vectorDiff velocity _tgt);
private _tgo = if (_Vca != 0) then {vectorMagnitude _RTM / _Vca} else {0};
private _intercept = _tpos vectorAdd ((velocity _tgt) vectorMultiply _tgo);

private _returnTargetPos = _seekerTargetPos;


switch (_attackProfileStateParams select 0) do {
	case STAGE_LAUNCH: {
		if (_distanceToShooter < 30) then {
            _returnTargetPos = _attackProfileStateParams select 1;
		} else {
			_attackProfileStateParams set [0, STAGE_BOOST];
		};
	};
	case STAGE_BOOST: {
		if (_distanceToShooter < 80) then {
            _returnTargetPos = _seekerTargetPos;
		} else {
			_attackProfileStateParams set [0, STAGE_TERMINAL];
		};
	};
	case STAGE_TERMINAL: {
		_returnTargetPos = _intercept;
		if (_distanceToTarget < 10) then {triggerAmmo _wep; player sideChat "Fuze!"};
	};
};


drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\explosive_ca.paa", [0,1,0,1], ASLtoAGL (_attackProfileStateParams select 1), 0.75, 0.75, 0, "Init", 1, 0.025, "TahomaB"];

drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\board_ca.paa", [0,1,0,1], ASLtoAGL _returnTargetPos, 0.75, 0.75, 0, "Target", 1, 0.025, "TahomaB"];

drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selectover_ca.paa", [1,0,0,1], ASLtoAGL _wpos, 0.75, 0.75, 0, "SAM", 1, 0.025, "TahomaB"];
private _ps = "#particlesource" createVehicleLocal (ASLtoAGL _wpos);
_PS setParticleParams [["\A3\Data_f\cl_basic", 8, 3, 1], "", "Billboard", 1, 3.0141, [0, 0, 2], [0, 0, 0], 1, 1.275, 1, 0, [1, 1], [[1, 1, 0, 1], [1, 1, 0, 1], [1, 1, 0, 1]], [1], 1, 0, "", "", nil];
_PS setDropInterval 3.0;


_returnTargetPos;

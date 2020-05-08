/*
 * Author: VKing
 * Attack profile: MANPADS
 *
 * Arguments:
 * 0:
 *
 * Return Value:
 * 
 *
 * Example:
 * 
 *
 * Public: No
 */
// #define DEBUG_MODE_FULL
//#include "script_component.hpp"

#define STAGE_LAUNCH 1
#define STAGE_BOOST 2
#define STAGE_TERMINAL 3

params ["_shooter","","","","","","_projectile"];


if (isNull _projectile) exitWith {player sideChat "Exit: No projectile"};
player sideChat str (missileTarget _projectile);
if (isNull missileTarget _projectile) exitWith {player sideChat "Exit: No missileTarget"};

private _wepDir = [secondaryWeapon _shooter] call ace_common_fnc_getWeaponAzimuthAndInclination;
private _initAimOffset = [100, _wepDir select 0, _wepDir select 1] call CBA_fnc_polar2vect;
private _initTargetPos = getPosASL _shooter vectorAdd (_initAimOffset);
private _attackProfileStateParams = [STAGE_LAUNCH, _initTargetPos];

private _target = missileTarget _projectile;
_projectile setMissileTarget objNull;

private _firedHandler = [{
	params ["_params", "_pfh"];
	if (isNull _projectile || !alive _projectile) then {
		[_pfh] call CBA_fnc_removePerFrameHandler;
	};
	_params params ["_shooter", "_wep", "_tgt", "_attackProfileStateParams"];

	private _wpos = _wep modelToWorldWorld [0,0,0];
	private _tpos = _tgt modelToWorldWorld [0,0,0];
	private _launchPos = getPosASL _shooter;

	private _distanceToShooter = _wpos vectorDistance _launchPos;
	private _distanceToTarget = _wpos vectorDistance _tpos;
	private _RTM = _tpos vectorDiff _wpos;
	private _Vca = vectorMagnitude (velocity _wep vectorDiff velocity _tgt);
	private _tgo = if (_Vca != 0) then {vectorMagnitude _RTM / _Vca} else {0};
	private _intercept = _tpos vectorAdd ((velocity _tgt) vectorMultiply _tgo);

	private _returnTargetPos = _tpos;


	switch (_attackProfileStateParams select 0) do {
		case STAGE_LAUNCH: {
			if (_distanceToShooter < 15) then {
				_returnTargetPos = _attackProfileStateParams select 1;
			} else {
				_attackProfileStateParams set [0, STAGE_BOOST];
			};
		};
		case STAGE_BOOST: {
			if (_distanceToShooter < 30) then {
				_returnTargetPos = _tpos;
			} else {
				_attackProfileStateParams set [0, STAGE_TERMINAL];
			};
		};
		case STAGE_TERMINAL: {
			_returnTargetPos = _intercept;
			if (_distanceToTarget < 5) then {triggerAmmo _wep; player sideChat "Fuze!"};
		};
	};

	drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\explosive_ca.paa", [0,1,0,1], ASLtoAGL (_attackProfileStateParams select 1), 0.75, 0.75, 0, "Init", 1, 0.025, "TahomaB"];

	drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\board_ca.paa", [0,1,0,1], ASLtoAGL _returnTargetPos, 0.75, 0.75, 0, "Target", 1, 0.025, "TahomaB"];

	drawIcon3D ["\a3\ui_f\data\IGUI\Cfg\Cursors\selectover_ca.paa", [1,0,0,1], ASLtoAGL _wpos, 0.75, 0.75, 0, "SAM", 1, 0.025, "TahomaB"];
	private _ps = "#particlesource" createVehicleLocal (ASLtoAGL _wpos);
	_PS setParticleParams [["\A3\Data_f\cl_basic", 8, 3, 1], "", "Billboard", 1, 3.0141, [0, 0, 2], [0, 0, 0], 1, 1.275, 1, 0, [1, 1], [[1, 1, 0, 1], [1, 1, 0, 1], [1, 1, 0, 1]], [1], 1, 0, "", "", nil];
	_PS setDropInterval 3.0;

	hintsilent format ["%1\n%2\n%3", missileTarget _wep, _returnTargetPos, missileTargetPos _wep];

	_wep setMissileTargetPos _intercept;
	
}, 0, [_shooter, _projectile, _target, _attackProfileStateParams]] call CBA_fnc_addPerFrameHandler;
/*
*
*	Made by: Noffearr
*	
*
*/

#ifndef SC_ACMGR_H
#define SC_ACMGR_H

#include "ScriptPCH.h"
#include "Config.h"
#include "AnticheatData.h"

class AnticheatData;
typedef std::map<uint32, AnticheatData> AnticheatPlayersDataMap;

enum hackTypes
{
	SPEED_HACK = 0,
	FLY_HACK,
	WALKWATER_HACK,
	JUMP_HACK,
	TELEPORTPLANE_HACK,
	WALLCLIMB_HACK,
};

struct ReportsInfo
{
	uint32 Times;
};
static std::map<uint32, ReportsInfo> reportTimes;

class ClearTimes : public BasicEvent
{
public:
	ClearTimes(Player* player) : _Plr(player) {}

	bool Execute(uint64 /*time*/, uint32 /*diff*/)
	{
		reportTimes.clear();
		return true;
	}
	Player* _Plr;
};

class AnticheatMgr
{
	friend class ACE_Singleton<AnticheatMgr, ACE_Null_Mutex>;
	AnticheatMgr();

public:
	void StartHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);

private:
	void SpeedHackDetection(Player* player, MovementInfo movementInfo);
	void FlyHackDetection(Player* player, MovementInfo movementInfo);
	void WalkOnWaterHackDetection(Player* player, MovementInfo movementInfo);
	void JumpHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
	void TeleportPlaneHackDetection(Player* player, MovementInfo);
	void ClimbHackDetection(Player* player, MovementInfo movementInfo, uint32 opcode);
	void Alerts(Player* player, uint8 alertType, uint8 hackType);
	void Report(Player* player, uint8 hackType);
	AnticheatPlayersDataMap m_Players;
};
#define sAnticheatMgr ACE_Singleton<AnticheatMgr, ACE_Null_Mutex>::instance()

#endif

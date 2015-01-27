/*
*
*	Made by: Noffearr
*	
*
*/

#ifndef SC_ACDATA_H
#define SC_ACDATA_H

#include "AnticheatMgr.h"

class AnticheatData
{
public:
	AnticheatData();

	uint32 GetLastOpcode() const;
	void SetLastOpcode(uint32 opcode);

	const MovementInfo& GetLastMovementInfo() const;
	void SetLastMovementInfo(MovementInfo& moveInfo);

	void SetPosition(float x, float y, float z, float o);
private:
	uint32 lastOpcode;
	MovementInfo lastMovementInfo;
};

#endif
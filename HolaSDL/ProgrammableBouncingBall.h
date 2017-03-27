#ifndef _H_ProgrammableBouncingBall_H_
#define _H_ProgrammableBouncingBall_H_
#include "PBBExternAccess.h"

class ProgrammableBouncingBall : public PBBExternAccess 
{
public:
	ProgrammableBouncingBall();
	~ProgrammableBouncingBall();
protected:
	bool onClick();
	void update();
};
#endif

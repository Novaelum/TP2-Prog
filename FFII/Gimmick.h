#pragma once

//First 'Clean & Simple' iteration

#include "Common.h"
#include "Animation.h"

class Gimmick :
	public Animation
{
public:
	Gimmick();
	~Gimmick();

	void Update();
	const std::string GIMMICK_PATH;
	const point<int> START_SRC_POS;
	const point<int> FRAME_SRC_SIZE;
};


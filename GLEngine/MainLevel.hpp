#ifndef MAINLEVEL_HPP
#define MAINLEVEL_HPP

#include "Level.hpp"
#include "PlayerMove.hpp"
#include "BallMove.hpp"

class MainLevel : public Level
{
public:
	MainLevel();
	virtual void Init() override;
};

#endif
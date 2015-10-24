#ifndef MAINLEVEL_HPP
#define MAINLEVEL_HPP

#include "Level.hpp"
#include "PlayerController.hpp"

class MainLevel : public Level
{
public:
	MainLevel(std::string name);
	virtual void Init() override;
};

#endif
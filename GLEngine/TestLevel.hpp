#ifndef TESTLEVEL_HPP
#define TESTLEVEL_HPP

#include "Level.hpp"
#include "PlayerController.hpp"

class TestLevel : public Level
{
public:
	TestLevel(std::string name);
	virtual void Init() override;
};

#endif

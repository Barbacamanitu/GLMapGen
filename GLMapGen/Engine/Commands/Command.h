#pragma once
#include <memory>

class Command
{
public:
	typedef std::unique_ptr<Command> PTR;
	Command() {};
	~Command() {};
	virtual void execute() = 0;
};

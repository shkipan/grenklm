//
// Created by bruteflow on 10/14/18.
//

#ifndef RUSH01_PHYSMEMORYMODULE_HPP
#define RUSH01_PHYSMEMORYMODULE_HPP


#include "Module.hpp"

class PhysMemoryModule : public Module
{
public:
	/* Canonical Form */
	PhysMemoryModule();
	PhysMemoryModule(PhysMemoryModule const &src);
	~PhysMemoryModule();
	PhysMemoryModule &operator=(PhysMemoryModule const &rhs);

	void							generateMemoryData();
	std::string						getName() const;
	std::string 					getOutput() const;
	std::string						exec(const char* cmd);

private:
	std::string						_name;
	std::string						_output;
};


#endif //RUSH01_PHYSMEMORYMODULE_HPP

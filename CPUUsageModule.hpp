//
// Created by bruteflow on 10/14/18.
//

#ifndef RUSH01_CPUUSAGEMODULE_HPP
#define RUSH01_CPUUSAGEMODULE_HPP


#include <vector>
#include <string>
#include "Module.hpp"

class CPUUsageModule : public Module
{
public:
	/* Canonical Form */
	CPUUsageModule();
	CPUUsageModule(CPUUsageModule const &src);
	~CPUUsageModule();
	CPUUsageModule &operator=(CPUUsageModule const &rhs);

	void							tick();
	std::string 					getOutput() const;
	std::string						getName() const;
	std::string						getCoreCount() const;
	std::string						getCPUInfo() const;
	std::string						exec(const char* cmd);
private:
	std::string						_name;
	std::string						_output;
};


#endif //RUSH01_CPUUSAGEMODULE_HPP

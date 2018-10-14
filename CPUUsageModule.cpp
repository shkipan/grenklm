//
// Created by bruteflow on 10/14/18.
//

#include "CPUUsageModule.hpp"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sstream>
#include <sys/sysctl.h>

/* Default constructor */
CPUUsageModule::CPUUsageModule()
:_name("CPU Module:\n"), _output()
{
	tick();
}

/* Copy constructor */
CPUUsageModule::CPUUsageModule(CPUUsageModule const &src)
:_name(src._name), _output(src._output)
{}

/* Default destructor */
CPUUsageModule::~CPUUsageModule()
{}

/* Assignment operator overload (Update) */
CPUUsageModule &CPUUsageModule::operator=(CPUUsageModule const &rhs)
{
	/* this->data = rhs.data */
	_name = rhs._name;
	_output = rhs._output;
	return *this;
}

void CPUUsageModule::tick()
{
	_output = exec("top -l 1 | grep -E 'CPU usage:'");
}

std::string CPUUsageModule::getOutput() const
{
	std::stringstream ss;
	std::string tmp;

	ss << getCPUInfo() << "\n" << getCoreCount() << _output;
	tmp = ss.str();
	return tmp;
}

std::string CPUUsageModule::getName() const
{
	return _name;
}

std::string CPUUsageModule::exec(const char* cmd)
{
	std::array<char, 128> buffer;
	std::string result;
	std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
			result += buffer.data();
	}
	return result;
}

std::string CPUUsageModule::getCoreCount() const
{
	int mib[4];
	int numCPU;
	std::size_t len = sizeof(numCPU);
	/* set the mib for hw.ncpu */
	mib[0] = CTL_HW;
	mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU;

	/* get the number of CPUs from the system */
	sysctl(mib, 2, &numCPU, &len, NULL, 0);

	if (numCPU < 1)
	{
		mib[1] = HW_NCPU;
		sysctl(mib, 2, &numCPU, &len, NULL, 0);
		if (numCPU < 1)
			numCPU = 1;
	}
	std::string tmp;
	std::stringstream ss;
	ss << "CPU Core Count: " << numCPU << " cores" << "\n";
	tmp = ss.str();
	return tmp;
}

std::string CPUUsageModule::getCPUInfo() const
{
	char buffer[100];
	size_t bufferlen = 100;
	sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
	return buffer;
}

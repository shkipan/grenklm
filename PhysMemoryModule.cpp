//
// Created by bruteflow on 10/14/18.
//

#include "PhysMemoryModule.hpp"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <sstream>
#include <sys/sysctl.h>

/* Default constructor */
PhysMemoryModule::PhysMemoryModule()
:_name("\nPhysical Memory Module: \n"), _output()
{
	generateMemoryData();
}

/* Copy constructor */
PhysMemoryModule::PhysMemoryModule(PhysMemoryModule const &src)
:_name(src._name), _output(src._output)
{}

/* Default destructor */
PhysMemoryModule::~PhysMemoryModule()
{}

/* Assignment operator overload (Update) */
PhysMemoryModule &PhysMemoryModule::operator=(PhysMemoryModule const &rhs)
{
	/* this->data = rhs.data */
	_name = rhs._name;
	_output = rhs._output;
	return *this;
}

void PhysMemoryModule::generateMemoryData()
{
	_output = exec("top -l 1 | grep -E 'PhysMem:'");
}

std::string PhysMemoryModule::getOutput() const
{
	return _output;
}

std::string PhysMemoryModule::exec(const char* cmd)
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

std::string PhysMemoryModule::getName() const
{
	return _name;
}

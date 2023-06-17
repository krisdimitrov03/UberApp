#pragma once
#include "String.h"

class IdFactory
{
	static IdFactory instance;
	
	IdFactory() = default;
public:
	IdFactory(const IdFactory&) = delete;
	IdFactory& operator=(const IdFactory&) = delete;

	static IdFactory& getInstance();

	String create() const;
};
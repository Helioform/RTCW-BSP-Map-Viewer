#pragma once
#include "HelperFunctions.h"

template <typename T> class Singleton
{
	static T* ms_singleton;
public:

	Singleton(void)
	{
		assert(!ms_singleton);
		int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
		ms_singleton = (T*)((int)this + offset);
	}

	~Singleton(void)
	{
		assert(ms_singleton);
		ms_singleton = nullptr;
	}

	static T& GetSingleton(void)
	{
		return (*ms_singleton);
	}

	static T* GetSingletonPointer(void)
	{
		return (ms_singleton);
	}
};


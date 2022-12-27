#pragma once
#include "CObserver.h"

class CSubject
{
public:
	virtual void ResisterObserver(CObserver* observer)=0;
	virtual void RemoveObserver(CObserver* observer) = 0;
	virtual void Notifyobserver() = 0;
};
#pragma once
class CObserver
{
public:

	virtual void update(float temperature, float humidity, int pressure) = 0;
};


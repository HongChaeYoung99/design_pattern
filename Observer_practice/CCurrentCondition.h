#pragma once
#include "CObserver.h"
#include "CSubject.h"

class CCurrentCondition : public CObserver{
public:
	CCurrentCondition(CSubject* weatherData);
	~CCurrentCondition();
	void update(float temperature, float humidity, int pressure);
	void display();
private:
	CSubject* mWeatherData;
	float mHumidity;
	int mPressure;
	float mTemperature;
};
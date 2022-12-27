#include "CCurrentCondition.h"
#include "CSubject.h"
#include <stdio.h>
CCurrentCondition::CCurrentCondition(CSubject* weatherData)
{
	mWeatherData = weatherData;
	mWeatherData->ResisterObserver(this);
}

CCurrentCondition::~CCurrentCondition()
{
}

void CCurrentCondition::update(float temperature, float humidity, int pressure) {
	mTemperature = temperature;
	mHumidity = humidity;
	mPressure = pressure;
	display();
}

void CCurrentCondition::display()
{
	printf("현재 압력 : %d\n", mPressure);
	printf("현재 온도 : %f\n", mTemperature);
	printf("현재 습도 : %f\n", mHumidity);
}
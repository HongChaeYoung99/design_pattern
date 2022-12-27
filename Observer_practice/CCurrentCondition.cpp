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
	printf("���� �з� : %d\n", mPressure);
	printf("���� �µ� : %f\n", mTemperature);
	printf("���� ���� : %f\n", mHumidity);
}
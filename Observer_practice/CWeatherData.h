#pragma once
#include "CSubject.h"
#include "CObserver.h"
#include <vector>

class CWeatherData : public CSubject
{
public:
	CWeatherData() {
		mHumidity = 0.22;
		mPressure = 12;
		mTemperature = 1.2;
	}
	~CWeatherData() {

	}

	void SetMeasureChanged(float huminity, int pressure, float temperature);
	void ResisterObserver(CObserver* observer);
	void MeasurementChanged();
	void RemoveObserver(CObserver* observer);

private:
	float mHumidity;
	int mPressure;
	float mTemperature;
	std::vector<CObserver*> mObserver;
	void Notifyobserver();
};


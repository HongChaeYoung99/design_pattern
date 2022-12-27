#include "CWeatherData.h"

void CWeatherData::ResisterObserver(CObserver* observer)
{
	mObserver.push_back(observer);
}

void CWeatherData::Notifyobserver()
{
	std::vector<CObserver*>::iterator iter = mObserver.begin();
	for (; iter != mObserver.end(); iter++) {
		CObserver* observer = *iter;
		observer->update(mTemperature, mHumidity, mPressure);
	}
}

void CWeatherData::RemoveObserver(CObserver* observer) {
	std::vector<CObserver*>::iterator iter;
	iter = find(mObserver.begin(), mObserver.end(), observer);
	if (iter != mObserver.end())
	{
		mObserver.erase(iter);
	}
}

void CWeatherData::SetMeasureChanged(float humidity, int pressure, float temperature)
{
	mHumidity = humidity;

	mPressure = pressure;
	mTemperature = temperature;
	MeasurementChanged();
}

void CWeatherData::MeasurementChanged()
{
	Notifyobserver();
}



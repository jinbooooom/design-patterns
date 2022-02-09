#ifndef WEATHER_DATA_HPP
#define WEATHER_DATA_HPP

#include "Subject.hpp"
#include "Observer.hpp"

class WeatherData : public Subject
{
private:
    float temperature;                        // 温度
    float humidity;                           // 湿度
    float pressure;                           // 压强

private:
    void measurementsChanged()
    {
        notifyObservers();
    }

public:
    void registerObserver(Observer *o)
    {
        mObservers.insert(o);
    }

    void removeObserver(Observer *o)
    {
        mObservers.erase(o);
    }

    void notifyObservers()
    {
        for (auto o : mObservers)
        {
            o->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float t, float h, float p)
    {
        temperature = t;
        humidity = h;
        pressure = p;
        measurementsChanged();
    }
};

#endif
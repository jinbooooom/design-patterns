#ifndef WEATHER_DATA_HPP
#define WEATHER_DATA_HPP

#include "Subject.hpp"
#include "Observer.hpp"

#include <unordered_set>

class WeatherData : public Subject
{
private:
    std::unordered_set<Observer *> observers; // 有一个无序set用来记录注册的观察者
    float temperature;                        // 温度
    float humidity;                           // 湿度
    float pressure;                           // 压强

public:
    void registerObserver(Observer *o)
    {
        observers.insert(o);
    }

    void removeObserver(Observer *o)
    {
        observers.erase(o);
    }

    void notifyObservers()
    {
        for (auto o : observers)
        {
            o->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged()
    {
        notifyObservers();
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
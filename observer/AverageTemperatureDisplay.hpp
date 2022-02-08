#ifndef AVERAGE_TEMPERATURE_DISPLAY_HPP
#define AVERAGE_TEMPERATURE_DISPLAY_HPP

#include "Observer.hpp"
#include "Subject.hpp"
#include "DisplayElement.hpp"

#include <iostream>
#include <memory>

// 此布告板根据 WeatherDate 对象显示当前观测值
class AverageTemperatureDisplay : public Observer, public DisplayElement
{
private:
    float temperature;
    float humidity;
    unsigned int cnt;                     // 记录更新的次数，用于统计均值
    unsigned int sumTemperature;          // 记录累计的温度，用于统计均值
    std::shared_ptr<Subject> weatherData; // 考虑到以后想要取消注册，所以有了对 Subject 的引用会比较方便

public:
    AverageTemperatureDisplay(std::shared_ptr<Subject> w)
        : temperature(0.0f),
          humidity(0.0f),
          weatherData(std::move(w))
    {
        registerSubject();
    }

    void registerSubject()
    {
        weatherData->registerObserver(this);
    }

    void removeSubject()
    {
        weatherData->removeObserver(this);
    }

    ~AverageTemperatureDisplay()
    {
        weatherData->removeObserver(this);
    }

    void update(float t, float h, float p)
    {
        temperature = t;
        ++cnt;
        sumTemperature += temperature;
        display();
    }

    void display() override
    {
        std::cout << "Average temperature is: " << sumTemperature / cnt << "F degrees" << std::endl;
    }
};

#endif

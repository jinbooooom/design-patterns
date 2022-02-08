#ifndef CURRENT_CONDITIONS_DISPLAY_HPP
#define CURRENT_CONDITIONS_DISPLAY_HPP

#include "Observer.hpp"
#include "DisplayElement.hpp"

#include <iostream>
#include <memory>

// 此布告板根据 WeatherDate 对象显示当前观测值
class CurrentConditionsDisplay : public Observer, public DisplayElement
{
private:
    float temperature;                    // 温度
    float humidity;                       // 湿度
    std::shared_ptr<Subject> weatherData; // 以后想要取消注册，所以有了对 Subject 的引用会比较方便

public:
    CurrentConditionsDisplay(std::shared_ptr<Subject> w)
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

    ~CurrentConditionsDisplay()
    {
        weatherData->removeObserver(this);
    }

    void update(float t, float h, float p)
    {
        temperature = t;
        humidity = h;
        display();
    }

    // 显示温度和湿度
    void display() override
    {
        std::cout << "Current condidions: " << temperature << "F degrees and "
                  << humidity << "% humidity" << std::endl;
    }
};

#endif

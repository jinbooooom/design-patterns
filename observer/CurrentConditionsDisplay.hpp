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
    float temperature;
    float humidity;
    std::shared_ptr<Subject> weatherData;

public:
    CurrentConditionsDisplay(std::shared_ptr<Subject> w)
        : temperature(0.0f),
          humidity(0.0f),
          weatherData(std::move(w))
    {
    }

    void registerObserver()
    {
        weatherData->registerObserver(this);
    }

    ~CurrentConditionsDisplay()
    {
        weatherData->registerObserver(this);
    }

    void update(float t, float h, float p)
    {
        temperature = t;
        humidity = h;
        display();
    }

    void display() override
    {
        std::cout << "Current condidions: " << temperature << "F degrees and "
                  << humidity << "% humidity" << std::endl;
    }
};

#endif

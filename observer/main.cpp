#include "WeatherData.hpp"
#include "CurrentConditionsDisplay.hpp"
#include "AverageTemperatureDisplay.hpp"

void WeatherStationWithFunctions()
{
    auto w = std::make_shared<WeatherData>();
    CurrentConditionsDisplay *currentDisplay = new CurrentConditionsDisplay(w);
    //currentDisplay->registerObserver();
    AverageTemperatureDisplay *averageTemperatureDisplay = new AverageTemperatureDisplay(w);
    //averageTemperatureDisplay->registerObserver();

    // 只要主题的值改变了，就会通知观察者即CurrentConditionsDisplay，然后观察者打印出来
    w->setMeasurements(80, 65, 30.4f);
    w->setMeasurements(82, 70, 29.2f);
    w->setMeasurements(78, 90, 29.2f);

    std::cout << "现在 averageTemperatureDisplay 不再观察 WeatherData" << std::endl;
    // w->removeObserver(averageTemperatureDisplay);
    /**
     * 跟上面注释的那一行效果等价，但由于实际工程中，不方便通过 subject（即 w）去移除观察者（取消订阅），
     * 所以在观察者实例中保留订阅者的引用，方便移除观察者（取消订阅）。
    */
    averageTemperatureDisplay->removeSubject(); 

    w->setMeasurements(74, 66, 30.6f);
    w->setMeasurements(86, 68, 32.6f);

    delete currentDisplay;
    delete averageTemperatureDisplay;
}

int main()
{
    WeatherStationWithFunctions();
}

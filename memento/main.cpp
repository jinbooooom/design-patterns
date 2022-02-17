#include "Caretaker.hpp"
#include "Memento.hpp"
#include "Originator.hpp"

int main()
{
    Originator ori;
    Caretaker ct;

    ori.setState("S0");
    std::cout << ori;
    ct.setMemento(ori.saveStateToMemento());

    ori.setState("S1");
    std::cout << ori;
    ct.setMemento(ori.saveStateToMemento());

    ori.setState("S2");
    std::cout << ori;
    ct.setMemento(ori.saveStateToMemento());

    ori.setState("S3");
    std::cout << ori;

    ori.restoreFromMemento(ct.getMemento());
    std::cout << ori;

    ori.restoreFromMemento(ct.getMemento());
    std::cout << ori;

    ori.restoreFromMemento(ct.getMemento());
    std::cout << ori;

    ori.restoreFromMemento(ct.getMemento());
    std::cout << ori;

    ori.restoreFromMemento(ct.getMemento());
    std::cout << ori;

    return 0;
}
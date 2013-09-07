#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <vector>
#include <algorithm>

template<typename T>
class Subject;

template<typename T>
class Observer
{
public:
    Observer(T& s): subject_(s)
    {
        subject_.attach(this);
    }
    virtual ~Observer()
    {
        subject_.deregister(this);
    }

    virtual void check(std::string message) = 0;

    bool validSubject {true};
protected:
    T& subject_;
};

template<typename T>
class Subject
{
public:
    Subject() = default;
    ~Subject()
    {
        for (auto& obs : observers_)
        {
            obs->validSubject = false;
        }
    }
    void notify(std::string message = "")
    {
        for (auto& obs : observers_)
        {
            obs->check(message);
        }
    }

    void attach(Observer<T>* observer)
    {
        observers_.push_back(observer);
    }
    void deregister(Observer<T>* observer)
    {
        observers_.erase(std::remove(
                            observers_.begin(),
                            observers_.end(),
                            observer), observers_.end());
    }
private:
    std::vector<Observer<T>*> observers_;
};

#endif /* OBSERVER_HPP */

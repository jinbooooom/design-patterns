template <typename T>
class Singleton
{
public:
    static T &getInstance();
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    Singleton() = default;
    ~Singleton() = default;
};

template <typename T>
T &Singleton<T>::getInstance()
{
    static T instance;
    return instance;
}
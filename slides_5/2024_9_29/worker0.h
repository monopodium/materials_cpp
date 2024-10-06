#ifndef WORKER0_H_
#define WORKER0_H_
#include <string>
#include <vector>
class Worker // an abstract base class
{
private:
    std::string fullname;
    long id;

public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string &s, long n)
        : fullname(s), id(n) {}
    virtual ~Worker() = 0; // pure virtual destructor
    virtual void Set();
    virtual void Show() const;
};

class Waiter : public Worker
{
private:
    int panache;

public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string &s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker &wk, int p = 0)
        : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};
// class Singer : virtual public Worker {...};
class Singer : public Worker
{
public:
    enum
    {
        other,
        alto,
        contralto,
        soprano,
        bass,
        baritone,
        tenor
    };
    enum
    {
        Vtypes = 7
    };

private:
    static std::vector<std::string> pv; // string equivs of voice types
    int voice;

public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string &s, long n, int v = other)
        : Worker(s, n), voice(v) {}
    Singer(const Worker &wk, int v = other)
        : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};
#endif
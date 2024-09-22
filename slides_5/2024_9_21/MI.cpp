// 多继承的问题：
// inheriting different methods with the same name from two different base classes and inheriting
// multiple instances of a class via two or more related immediate base classes.
#include "worker0.h"
#include <iostream>


Worker::~Worker() {}
void Worker::Set()
{
    std::cout << "Enter worker's name: ";
    std::getline(std::cin, fullname);
}
void Worker::Show() const
{
    std::cout << "Name: " << fullname << "\n";
}

// Waiter methods
void Waiter::Set()
{
    Worker::Set();
    std::cout << "Enter waiter's panache rating: ";
    std::cin >> panache;
    while (std::cin.get() != '\n')
        continue;
}
void Waiter::Show() const
{
    std::cout << "Category: waiter\n";
    Worker::Show();
    std::cout << "Panache rating: " << panache << "\n";
}
// Singer methods
std::vector<std::string> Singer::pv = {"other", "alto", "contralto",
                      "soprano", "bass", "baritone", "tenor"};
void Singer::Set()
{
    Worker::Set();
    std::cout << "Enter number for singer's vocal range:\n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        std::cout << i << ": " << pv[i] << " ";
        if (i % 4 == 3)
            std::cout << std::endl;
    }
    if (i % 4 != 0)
        std::cout << std::endl;
    while (std::cin >> voice && (voice < 0 || voice >= Vtypes))
        std::cout << "Please enter a value >= 0 and < " << Vtypes << std::endl;
    while (std::cin.get() != '\n')
        continue;
}
void Singer::Show() const
{
    std::cout << "Category: singer\n";
    Worker::Show();
    std::cout << "Vocal range: " << pv[voice] << std::endl;
}
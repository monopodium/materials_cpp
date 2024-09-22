#include <iostream>
#include "worker0.h"
#include <vector>
const int LIM = 4;

// problems:

// How many workers?
// Which method?
class SingingWaiter : public Singer, public Waiter
{
public:
    SingingWaiter() {}
    SingingWaiter(const std::string &s, long n, int p = 0, int v = Singer::other)
        :  Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker &wk, int p = 0, int v = Singer::other)
        :  Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter &wt, int v = Singer::other)
        : Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer &wt, int p = 0)
        :  Waiter(wt, p), Singer(wt) {}
    // void Show() const
    // {
    //     std::cout << "Category: Singing Waiter\n";
    //     // Waiter::Show();
    //     // Singer::Show();
    // }
};
int main()
{
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    std::vector<Worker *> pw = {&bob, &bev};
    int i;
    for (i = 0; i < pw.size(); i++)
    {
        pw[i]->Show();
        std::cout << std::endl;
    }
    Worker * pw1 = (Waiter *) &bob; // the Worker in Waiter
    Worker * pw2 = (Singer *) &bev; // the Worker in Singer
    std::cout << pw1<<std::endl;
    std::cout << pw2<<std::endl;

    std::cout << "=========================="<<std::endl;
    SingingWaiter sw("Elise", 381L, 6, Singer::soprano);
    Waiter* w1 = &sw;
    Singer* s1 = &sw;   
    SingingWaiter* sw1 = &sw;
    w1->Show();
    s1->Show();
    //sw1->Show();
    return 0;
}
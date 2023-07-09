
#include <output.h>
#include <iostream>

io::output::output(int time, const std::vector<int> &floors) :
    total_time(time), floors_in_order(floors)
{
}

int io::output::get_total_time()
{
    return this->total_time;
}

const std::vector<int> io::output::get_floors_in_order()
{
    return this->floors_in_order;
}

void io::output::print()
{
    using namespace std;
    cout << "---------------" << endl;
    cout << "Floors visisted in order: ";
    const std::vector<int>& floors = this->get_floors_in_order();
    for (int i = 0; i < floors.size(); ++i)
    {
        if (i == floors.size() - 1)
            cout << floors[i];
        else   
            cout << floors[i] << ", ";
    }
    cout << endl;
    cout << "Total time for this traversal: " << this->get_total_time() << std::endl;
    cout << "---------------" << endl;

}
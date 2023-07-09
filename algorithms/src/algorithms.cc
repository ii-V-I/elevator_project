#include <algorithms.h>
#include <cmath>

int algorithms::get_path_travel_time(int time_constant, const vector<int>& floors)
{
    using namespace std;
    
    int total_time = 0;
    
    for (int i = 1; i < floors.size(); ++i)
        total_time += (abs(floors[i] - floors[i - 1]) * time_constant);

    return total_time;
}
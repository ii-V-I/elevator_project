#pragma once
#include <vector>
namespace io
{
    struct output 
    {
        private:
        int total_time;
        std::vector<int> floors_in_order;
        public:

        output(int time, const std::vector<int>& floors);

        int get_total_time();

        const std::vector<int> get_floors_in_order();

        void print();
    };
} // namespace io

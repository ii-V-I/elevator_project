#pragma once
#include <vector>
#include <string>
using namespace std;

namespace io
{
    struct input 
    {
        private:

        vector<int> floors;
        int time;

        static void parse_floor(const char* line, std::vector<int>& floors); 
           
        public:

        input();

        input(const char* start, const char* floors, const char* time);

        int get_start();

        const vector<int>& get_floors();

        int get_time();

        void print();
    };   
} // namespace io

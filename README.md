# First Time Build and Run Commands
1. mkdir build
2. cd mkdir 
3. cmake ..
4. cmake --build .
5. ./elevator *your command and arguements*

# Description
The purpose of this project is to simulate an elevator. I have chosen to do this by creating an executable that can take different commands. The implementation of this
project enables new types of commands and features to be added without interfering 
with the infrastructure in the code. 

The results of a given input are printed to the console.

# Assumptions
1. All inputs are well formed.
2. The valid floor input range is 1-124. 124 comes from the Shanghai Tower in China. 

# Commands
1. --floors start floor,floor,floor,etc
    give a starting floor and then a list of floors to process.
    start -> the starting floor
    floor,floor,floor,etc -> the list of floors to visit
2. --floors-rand min max num
    give the min and max floor for a range and then the number of changes 
    you wish to have happen.
    min -> the mininum floor
    max -> the maximum floor
    num -> the number of floors you wish to visit
3. --path input
    give the absolute path you wish to process. The files must be in the following format. The first line contains the starting floor, the second line contains the floor list separated by commas, and the third line contains the time constant. I have included some example files in ./file_inputs.
    input -> the path where the files are

# Architecture Comments
I picked a basic factory style implementation. This enables new commands and features to be added without impacting the main structure of the code.

# Unimplemented Features

## Interactive mode
I wanted to have the user be able to issue commands like in a real elevator. Due to time constraints I did not complete this. I would have use a threaded approach where the user queues task. The main thread would take user inputs and the secondary thread would process these commands. A basic producer consumer model would have lead to a straight forward implementation. This would have enabled more unique commands like: emergency stop, call operator, open and close doors, etc. 

## Logging
A logging feature would help provide insight into what the elevator was and is doing.

## Elevator Manager Concept

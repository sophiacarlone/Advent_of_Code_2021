#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main(){
    string instruction;
    int value, new_value;
    int horizontal = 0;
    int depth = 0;
    //map<string, int> m;
    ifstream in;
    in.open("d2_input.txt");
    //map<string, int>::iterator itr; //could use auto, but this will be good for memory
    int aim = 0; //part 2

  /* Beautiful code for part 1;
    m.insert(pair<string, int>("forward", 0)); //we know what the initial value should be
    m.insert(pair<string, int>("down", 0)); //we also know all keys
    m.insert(pair<string, int>("up", 0));
  */  

    //part 1
    while(in >> instruction >> value){
        cout << instruction << " " << value << endl;
        if(instruction == "forward"){
            horizontal += value;
            depth += aim * value;
        }
        
        else if (instruction == "down"){
            //depth += value;
            aim += value;
        }

        else {
            //depth -= value;
            aim -= value;
        }
     
        cout << horizontal << " " << depth << endl;
        //more beautiful code for part 1 that I want to keep but will not use for part 2
        //auto data = m.find(instruction); //we know we will find it, cause we already made keys for each instance
        //data->second += value; //part 1
    }

    //testing
    // for (itr = m.begin(); itr != m.end(); ++itr){
    //     cout << itr->first << " " << itr->second << endl;
    // }

    /* in memory of part 1
    int horizontal = (m.find("forward"))->second;
    int depth = ((m.find("down")) -> second) - ((m.find("up"))->second);
    */

    cout << horizontal * depth << endl;  

    in.close(); //forgot this on d1, oops
}
#include <iostream>
#include <vector> //we dont know the amount of data we will hold
#include <fstream>
using namespace std;

int main(){
    vector<int> v;
    int input;
    int p1_count = 0;
    int p2_count = 0;
    int curr_sum = 0;
    int prev_sum = 0;
    ifstream in;
    in.open("d1_input.txt");
    
    //input
    while (!in.eof()){
        in >> input;
        v.push_back(input);
    }

    //part 1
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i+1] > v[i]) p1_count++;
    }

    //part 2
    prev_sum = v[0] + v[1] + v[2];
    for(int i = 1; i+2 < v.size(); i++){
        curr_sum = v[i] + v[i+1] + v[i+2];
        if (curr_sum > prev_sum) p2_count++;
        prev_sum = curr_sum;
    }

    //answers
    cout << p1_count << endl;
    cout << p2_count << endl;
}
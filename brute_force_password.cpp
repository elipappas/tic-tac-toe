#include <iostream>
#include <string.h>
#include <chrono>
using namespace std;

void incrementString(string &result){
    int carry = 1;
    for(int i = result.length() - 1; i >= 0 && carry; --i){
        if(result[i] == 'z'){
            result[i] = 'a';
        }
        else {
            ++result[i];
            carry = 0;
        }
    }
    if(carry){
        result.insert(0,"a");
    }
}

int main(){
    string password = "omnipresence";
    string guess = "";
    auto start = std::chrono::high_resolution_clock::now();
    while(guess != password) {
        incrementString(guess);
        cout << guess << endl;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    string user_password = guess;
    double time = std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count();
    double time_s = time/1000;
    std::cout << time_s << " seconds\n";
}
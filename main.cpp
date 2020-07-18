#include <iostream>
#include "GameOfLife.cpp"
using namespace std;

int main() {


    auto m = new Matrix(50,50);

    m->execute(70);
    return 0;
}
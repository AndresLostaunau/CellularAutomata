#include <iostream>
#include "GameOfLife.cpp"
using namespace std;

int main() {
    /*auto n = new Matrix(10,10,0,9);
    n->execute(95);
    delete n;*/
    auto m = new Matrix(10,10);
    m->execute(90);
    return 0;
}
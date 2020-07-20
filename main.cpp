#include <iostream>
#include "GameOfLife.cpp"
using namespace std;

int main() {


    auto m = new Matrix(80,80);

    m->execute(90);
    return 0;
}
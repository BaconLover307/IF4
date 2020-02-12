#include "Rekening.h"
#include "RekeningGiro.h"
#include "RekeningTabungan.h"
#include <iostream>

using namespace std;

int main() {
    Rekening R1(100);
    RekeningGiro R2(200,200);
    RekeningTabungan R3(300,300);
}

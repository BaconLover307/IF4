#include "Car.h"
#include <bits/stdc++.h>

using namespace std;

Car::Car(Fuel t_fuel) {
    fuel = t_fuel;
    gear = 0;
    ac_power = 0;
    on = false;
}

Fuel Car::getFuel() {
    return fuel;
}

int Car::getGear() {
    return gear;
}

int Car::getAcPower() {
    return ac_power;
}

bool Car::getOn() {
    return on;
}

void Car::fillingFuel(Fuel t_fuel, int amount_in_liter) {
    if (fuel != t_fuel) {
        throw t_fuel;
    } else {
        cout << "Berhasil isi bensin sebanyak " << amount_in_liter << " liter" << endl;
    }
}

void Car::changeGear(int g) {
    if (MIN_GEAR <= g && g <= MAX_GEAR) {
        cout << "Berhasil mengubah gigi menjadi gigi " << g << endl;
    } else {
        gear = g;
        throw g;
    }
}

void Car::changeAcPower(int ac) {
    if (MIN_AC <= ac && ac <= MAX_AC) {
        ac_power = ac;
        cout << "Berhasil mengubah power ac menjadi " << ac << endl;
    } else {
        throw ac;
    }
}

void Car::start() {
    if (on) {
        throw on;
    } else {
        on = true;
        cout << "Berhasil melakukan starter mobil" << endl;
    }
}

void Car::service(Fuel f, int l, int g, int ac) {
    try {
        start();
        fillingFuel(f, l) ;
        changeGear(g);
        changeAcPower(ac);
    }
    catch(bool on) {
        cout << "Mobil sudah menyala\n";
    }
    catch(Fuel f) {
        cout << "Bensin tidak sesuai\n";
    }
    catch(int g) {
        cout << "Input angka diluar range\n";
    }
}
// Nama : Gregorius Jovan Kresnadi
// NIM  : 13518135
// Latihan UTS OOP

// PQElmt.cpp
#include "PQElmt.hpp"

PQElmt::PQElmt() {
  this->value = 0;
  this->prio = 0;
}

PQElmt::PQElmt(int value, int prio) {
  this->value = value;
  this->prio = prio;
}

PQElmt::PQElmt(const PQElmt& other) {
  this->value = other.value;
  this->prio = other.prio;
}

PQElmt::~PQElmt() {
  // Tidak ada pointer
}

int PQElmt::getValue() const {
  return value;
}

int PQElmt::getPrio() const {
  return prio;
}

bool PQElmt::operator==(const PQElmt& other) {
  return (value == other.value) && (prio == other.prio);
}

bool PQElmt::operator<(const PQElmt& other) {
  if (prio != other.prio) {
    return prio < other.prio;
  } else {
    return value > other.value; 
  }
}

bool PQElmt::operator>(const PQElmt& other) {
  if (prio != other.prio) {
    return prio > other.prio;
  } else {
    return value < other.value;
  }
}

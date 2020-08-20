#include <iostream>
#include <memory>
#include "singleton.hpp"

std::shared_ptr<Singleton> Singleton::_instance = nullptr;

std::shared_ptr<Singleton> Singleton::Instance(){
  if (_instance == nullptr) {
    _instance = std::shared_ptr<Singleton>(new Singleton);
  }
  return _instance;
}
void Singleton::print(){
  std::cout << "Hello from singleton print method\n";
}

Singleton::Singleton(){
  std::cout << "Constructor\n";
}
Singleton::~Singleton(){
  std::cout << "Destructor\n";
}

int main() {
  std::shared_ptr<Singleton> a = Singleton::Instance();
  a->print();
}
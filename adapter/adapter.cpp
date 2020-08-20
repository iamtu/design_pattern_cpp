#include <iostream>
#include <memory>

#include "adaptee.hpp"
#include "target.hpp"
//Target want to use function of adaptee but the interface is not related
//Adapter is an target with adaptee member variable.

class Adapter : public Target {
  private:
    std::shared_ptr<Adaptee> _adaptee;
  public:
    Adapter(std::shared_ptr<Adaptee> adaptee) {
      _adaptee = adaptee;
    }
    void request() override {
      _adaptee->specific_request();
      std::cout << "Used fuctionality of adaptee\n";
    }
};

int main() {
  std::shared_ptr<Adaptee> adaptee = std::shared_ptr<Adaptee>(new Adaptee);
  Adapter* a = new Adapter(adaptee);
  a->request();
  delete a;
}
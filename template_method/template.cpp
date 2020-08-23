#include <iostream>

class Abstract {
  public:
    void template_method() {
      this->primitive_1();
      this->primitive_2();
      this->hook();
    }
  protected:
    virtual void hook() {
      std::cout << "Default hook method. empty body.\n";
    }
    virtual void primitive_1() = 0;
    virtual void primitive_2() = 0;
};

class Concrete: public Abstract {
  protected:
    void primitive_1() override {
      std::cout << "Customized primitive_2()\n";
    }
    void primitive_2() override {
      std::cout << "Customized primitive_2()\n";
    }
    void hook() override {
      std::cout << "Customized hook\n";
    }
};

int main() {
  Concrete a;
  a.template_method();
}
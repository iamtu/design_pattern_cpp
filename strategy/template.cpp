#include <iostream>

template <class Strategy>
class Context {
  public:
    void operate(){
      _strategy.do_sort();
    }
  private:
    Strategy _strategy;
};
class Algorithm1 {
  public:
    void do_sort(){
      std::cout << "Algorithm1 sort\n";
    }
};
class Algorithm2 {
  public:
    void do_sort(){
      std::cout << "Algorithm2 sort\n";
    }
};

int main() {
  Context<Algorithm1> context1;
  context1.operate();

  Context<Algorithm2> context2;
  context2.operate();
}
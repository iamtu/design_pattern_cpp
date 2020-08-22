#include <iostream>
#include <memory>

class Algorithm {
  public:
    virtual void do_sort() = 0;
};

class QuickSort: public Algorithm {
  public:
    void do_sort() override {
      std::cout << "Quick sort\n";
    }
};

class BubbleSort: public Algorithm {
  public:
    void do_sort() override {
      std::cout << "Bubble sort\n";
    }
};

class Context {
  public:
    Context(std::shared_ptr<Algorithm> strategy) : _strategy(strategy) {}
    void operate(){
      _strategy->do_sort();
    }
  private:
    std::shared_ptr<Algorithm> _strategy;
};

int main() {
  Context c1 = {std::shared_ptr<Algorithm>(new QuickSort)};
  c1.operate();

  Context c2 = {std::shared_ptr<Algorithm>(new BubbleSort)};
  c2.operate();
}
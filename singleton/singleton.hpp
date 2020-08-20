#include <memory>

class Singleton {
public:
  static std::shared_ptr<Singleton> Instance();
  void print();
  ~Singleton();
protected:
  Singleton();
private:
  static std::shared_ptr<Singleton> _instance;
};
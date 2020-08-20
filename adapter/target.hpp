#include <iostream>
class Target {
  public:
    virtual void request() {
      std::cout << "Request() method should be override\n";  
    }
    virtual ~Target() = default;
};
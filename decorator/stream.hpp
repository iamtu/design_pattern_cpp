#include <iostream>
class Stream {
  public:
    void put_int(){
      std::cout << "Stream put_int\n";
    }
    void put_tring(){
      std::cout << "Stream put_string\n";
    }
    virtual void handle_buffer_full() = 0;
};

class MemoryStream : public Stream {
  public:
    void handle_buffer_full() override {
      std::cout << "MemoryStream handle_buffer_full\n";
    }
};

class FileStream : public Stream {
  public:
    void handle_buffer_full() override {
      std::cout << "FileStream handle_buffer_full\n";
    }
};
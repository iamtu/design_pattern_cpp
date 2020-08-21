#include <memory>

#include "stream.hpp"

class StreamDecorator: public Stream {
  private:
    std::shared_ptr<Stream> _stream;
  public:
    StreamDecorator(std::shared_ptr<Stream> stream){
      _stream = stream;
    }
    virtual void handle_buffer_full() {
      _stream->handle_buffer_full();
    }
};

class ASCII7Stream: public StreamDecorator {
  public:
    ASCII7Stream(std::shared_ptr<Stream> stream): StreamDecorator(stream) {}

    void handle_buffer_full() override {
      std::cout << "Ascii7Stream add some additional step\n";
      StreamDecorator::handle_buffer_full();
    }
};

class CompressingStream: public StreamDecorator {
  public:
    CompressingStream(std::shared_ptr<Stream> stream) : StreamDecorator(stream) {}
    void handle_buffer_full() override {
      std::cout << "CompressingStream add some additional step\n";
      StreamDecorator::handle_buffer_full();
    }
};

int main() {
  std::shared_ptr<FileStream> file_stream = std::shared_ptr<FileStream>(new FileStream);
  std::shared_ptr<ASCII7Stream> ascii7_stream = std::shared_ptr<ASCII7Stream>(new ASCII7Stream(file_stream));
  std::shared_ptr<Stream> stream = std::shared_ptr<Stream>(new CompressingStream(ascii7_stream));
  
  stream->handle_buffer_full();
}
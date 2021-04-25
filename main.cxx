#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>

class X
{
  public:
    X(std::string name)
      : mName(name)
    {
      std::cout << "Construction of " << mName << std::endl;    
    }
    ~X()
    {
      std::cout << "Destruction of " << mName << std::endl;    
    }
    void makeError()
    {
      throw std::runtime_error("WHAAAAAT?");
    }
  private:
    std::string mName;
};

// std::shared_ptr<X> global;

int main() {
  try
  {
    X wX("Jeff");
    auto wY = std::make_shared<X>("NoMemoryLeak");
    // global = wY;
    std::cout << "Hello World!" << std::endl;
    wX.makeError();
    std::cout << "Hello World 2!" << std::endl;
  }
  catch (std::runtime_error &runtimeError)
  {
    std::cout << "error: " << runtimeError.what() << std::endl;
  }
  return 0;
}

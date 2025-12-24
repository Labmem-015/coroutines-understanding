#include "awaitable.hpp"
#include "simple_coroutine.hpp"

using namespace simple_coro;

Task<std::string> foo_coroutine() {
    // call async I/O function here
    // co_await ...;
    std::cout << "This is couroutine" << std::endl;
    co_return std::string("End of coroutine!");
}

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    auto task = foo_coroutine();
    std::cout << "Coroutine result: " << task.get_value() << std::endl;
    std::cout << "The end" << std::endl;
    return EXIT_SUCCESS;
}
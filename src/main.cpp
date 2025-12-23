#include "awaitable.hpp"
#include "simple_coroutine.hpp"

void foo_coroutine() {
    // call async I/O function here
    // co_await ...;
    std::cout << "This is couroutine" << std::endl;
    co_return;
}

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    foo_coroutine();
    std::cout << "The end" << std::endl;
    return EXIT_SUCCESS;
}
#include "awaitable.hpp"
#include "simple_coroutine.hpp"

using namespace simple_coro;

Task<std::string> foo_coroutine() {
    // call async I/O function here
    // co_await ...;
    std::print("This is couroutine");
    co_return std::string("End of coroutine!");
}

int main(int argc, char* argv[]) {
    std::print("Hello, World!");
    auto task = foo_coroutine();
    std::print("Coroutine result: {}", task.get_value());
    std::print("The end");
    return EXIT_SUCCESS;
}
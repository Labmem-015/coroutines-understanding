#include "awaitable.hpp"
#include "task.hpp"

using namespace simple_coro;

Task<void> foo_coroutine() {
    std::print("This is couroutine");
    co_return;
}

int main(int argc, char* argv[]) {
    std::print("Hello, World!");
    auto task = foo_coroutine();
    std::print("Coroutine result");
    std::print("The end");
    return EXIT_SUCCESS;
}
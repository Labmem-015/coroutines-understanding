#include "awaitable.hpp"
#include "task.hpp"

using namespace simple_coro;

Task<void> foo_coroutine() {
    std::print("This is couroutine\n");
    co_return;
}

int main(int argc, char* argv[]) {
    std::print("Example2!\n");
    auto task = foo_coroutine();
    std::print("Coroutine result\n");
    std::print("The end\n");
    return EXIT_SUCCESS;
}
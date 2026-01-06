#include "task.hpp"

using namespace simple_coro;

Task<std::string> foo_coroutine() {
    std::print("This is couroutine\n");
    co_return std::string("End of coroutine!");
}

int main(int argc, char* argv[]) {
    std::print("Hello, World!\n");
    auto task = foo_coroutine();
    std::print("Coroutine result: {}\n", task.get_value());
    std::print("The end\n");
    return EXIT_SUCCESS;
}
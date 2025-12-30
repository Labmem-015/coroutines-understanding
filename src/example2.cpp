#include "awaitable.hpp"
#include "task.hpp"

using namespace simple_coro;

Task<void> awaitable_coroutine() {
    std::print("Begin of the awaitable_coroutine");
    co_return;
}

Task<void> foo_coroutine() {
    std::print("This is a coroutine with a co_await");
    auto task = awaitable_coroutine();
    std::print("before co_await");
    // co_await task;
    std::print("after co_await");
}
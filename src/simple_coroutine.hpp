#pragma once

namespace simple_coro {

struct task;

void foo_coroutine() {
    // call async I/O function here
    // co_await ...;
    std::cout << "This is couroutine" << std::endl;
    co_return;
}
    
} // namespace simple_coro
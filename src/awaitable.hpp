#pragma once

template <typename T>
struct AwaitableEntity {
    class Awaiter {};

    bool await_ready() {
        return false;
    }

    void await_suspend(std::coroutine_handle<> handle) noexcept {
        
    }

    Awaiter operator co_await() {
        return {};
    }
};
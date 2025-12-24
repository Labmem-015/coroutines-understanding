#pragma once

namespace simple_coro {

template<typename T>
struct Task {
    struct promise_type;
    using coro_handle_t = std::coroutine_handle<promise_type>;
    struct promise_type {
        T value;
        auto get_return_object() {return coro_handle_t::from_promise(*this) ;}
        std::suspend_always initial_suspend() noexcept { return {};}
        std::suspend_always final_suspend() noexcept { return {};}
        void return_value(T value) { this->value = value; }
        void unhandled_exception() { std::cout << "Exception here" << std::endl; }
    };
    Task(coro_handle_t handle) : coroutine_h(handle) {
        std::cout << "task created!" << std::endl;
    }
    ~Task() {
        if (coroutine_h) {
            coroutine_h.destroy();
        }
    }
    coro_handle_t coroutine_h;
    T get_value() { 
        return coroutine_h.promise().value;
    }
};
    
} // namespace simple_coro
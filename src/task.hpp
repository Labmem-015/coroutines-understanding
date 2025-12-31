#pragma once

namespace simple_coro {

template<typename T>
struct Promise {
    T value;

    auto get_return_object() {
        std::print("Creating coroutine handle from promise");
        return std::coroutine_handle<Promise>::from_promise(*this);
    }
    
    std::suspend_never initial_suspend() noexcept {
        std::print("Don't await on initial suspention");
        return {};
    }
    
    std::suspend_always final_suspend() noexcept {
        std::print("Await on final suspention");
        return {};
    }
    
    void return_value(T value) {
        std::print("Setting return value for promise_type object");
        this->value = value;
    }
    
    void unhandled_exception() {
        std::print("Unhandled exception caught in the coroutine!"); 
        std::terminate();
    }
};

template<>
struct Promise<void> {
    auto get_return_object() {
        std::print("Creating coroutine handle from promise");
        return std::coroutine_handle<Promise>::from_promise(*this);
    }
    
    std::suspend_never initial_suspend() noexcept {
        std::print("Don't await on initial suspention");
        return {};
    }
    
    std::suspend_never final_suspend() noexcept {
        std::print("Don't await on final suspention");
        return {};
    }
    
    void return_void() {
        std::print("Calling return_void of promise_object");
    }
    
    void unhandled_exception() {
        std::print("Unhandled exception caught in the coroutine!"); 
        std::terminate();
    }
};

template <typename T = void>
struct Task {
    using promise_type = Promise<T>;
    using coro_handle_t = std::coroutine_handle<promise_type>;

    coro_handle_t coroutine_h;

    Task(coro_handle_t handle) : coroutine_h(handle) { std::print("Task object is created!"); }

    ~Task() {
        std::print("Task object is being destroyed.");
        if (coroutine_h) {
            coroutine_h.destroy();
        }
    }
    
    T get_value() requires (!std::is_void_v<T>) {
        std::print("Get the value from the promise_type object");
        return coroutine_h.promise().value;
    }
};

} // namespace simple_coro
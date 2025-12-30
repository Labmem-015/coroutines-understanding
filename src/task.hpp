#pragma once

namespace simple_coro {

template <typename T>
struct Task {
    struct Promise;
    using promise_type = Task<T>::Promise;
    using coro_handle_t = std::coroutine_handle<promise_type>;
    struct Promise {
        auto get_return_object() {
            std::print("Creating coroutine handle from promise");
            return coro_handle_t::from_promise(*this);
        }
        
        std::suspend_never initial_suspend() noexcept {
            std::print("Don't await on initial suspention");
            return {};
        }
        
        std::suspend_always final_suspend() noexcept {
            std::print("Await on final suspention");
            return {};
        }
              
        void unhandled_exception() {
            std::print("Unhandled exception caught in the coroutine!"); 
            std::terminate();
        }
        
        [[no_unique_address]] T value;
    };

    Task(coro_handle_t handle) : coroutine_h(handle) { std::print("Task object is created!"); }

    ~Task() {
        std::print("Task object is being destroyed.");
        if (coroutine_h) {
            coroutine_h.destroy();
        }
    }
    
    coro_handle_t coroutine_h;

    T get_value() requires !void_value {
        std::print("Get the value from the promise_type object");
        return coroutine_h.promise().value;
    }
};

} // namespace simple_coro
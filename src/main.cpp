template <typename T>
struct AwaitableEntity {
    class Awaiter
    bool await_ready() const noexcept {
        return true;
    }

    void await_suspend(std::coroutine_handle<> handle) noexcept {
        
    }

    operator co_await()
};

void foo() {
    // call async I/O function here
    // co_await ...;
}

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    foo();
    std::cout << "The end" << std::endl;
    return EXIT_SUCCESS;
}
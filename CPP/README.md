# C++ Learning Repository

A structured collection of C++ learning materials organized by topics.

## 📁 Folder Structure

### `00-Fundamentals/`
**Basic C++ concepts and language features**
- `concepts.txt` - Core C++ concepts and principles
- `template-meta-programming.txt` - Template metaprogramming techniques
- `diamond-problem-detailed.txt` - Deep dive into the diamond problem in inheritance

### `01-Multithreading/`
**Threading, synchronization, and thread management**
- `multithreading.txt` - Threading basics and concepts
- `ConditionVariables/` - Condition variable patterns and usage
  - `ProducerConsumer.txt` - Producer-consumer pattern implementation

### `02-Concurrency-Patterns/`
**Concurrency problems, patterns, and solutions**
- `concurrency-problems/` - Common concurrency challenges
  - `id-generators.txt` - Thread-safe ID generation
  - `json-parser.txt` - Concurrent JSON parsing
  - `lock-using-atomic-flag.txt` - Lock implementation using atomic flags
  - `threadpools-and-promises.txt` - Thread pools and promise patterns
  - `two-threads-print-numbers-alternate.txt` - Alternating thread execution

### `03-Advanced/`
**Advanced C++ topics**
- `lockfreeprogramming.txt` - Lock-free programming techniques
- `NUMA.txt` - NUMA (Non-Uniform Memory Access) concepts
- `resumebackground.txt` - Background/resume concepts and implementations

### `04-Projects/`
**Practical C++ implementations and projects**
- `cpp-projs/` - Complete project implementations
  - `networks-posix/` - POSIX network programming (client/server)
  - `async-echo-server/` - Asynchronous echo server
  - `CppCon2018/` - CppCon 2018 examples
  - `make-classes-great-again/` - Class design patterns
  - `some-more-templates/` - Template examples

### `05-DSA-Problems/`
**Data structures and algorithms challenges**
- `problems/` - Algorithm and data structure problems
  - `order-book.txt` - Order book implementation
  - `compile-time-order-book.txt` - Compile-time order book optimization

### `config/`
**Build configuration and compiler settings**
- `CMakeLists.txt` - CMake build configuration
- `.clangd` - Clang language server settings
- `.clang-format` - Code formatting configuration
- `compile_commands.json` - Compiler commands database
- `temp.h` - Temporary header file

## 🚀 Getting Started

1. **Learn Fundamentals** → Start with `00-Fundamentals/`
2. **Explore Multithreading** → Move to `01-Multithreading/`
3. **Study Concurrency** → Deep dive into `02-Concurrency-Patterns/`
4. **Advanced Topics** → Review `03-Advanced/`
5. **Build Projects** → Implement in `04-Projects/`
6. **Practice Problems** → Solve challenges in `05-DSA-Problems/`

## 🛠️ Building Projects

To build the projects, navigate to the project directory and use CMake:

```bash
cd 04-Projects/cpp-projs/<project-name>
mkdir -p build && cd build
cmake ..
make
```

## 📝 Notes

- Each `.txt` file contains detailed notes, explanations, and code examples
- Projects in `04-Projects/` include CMakeLists.txt for easy compilation
- Use the `.clang-format` configuration to maintain consistent code style
- Refer to `compile_commands.json` for VS Code integration

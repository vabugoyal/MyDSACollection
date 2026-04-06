#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <variant>
#include <cctype>
#include <thread>
#include <queue>
#include <future>

using namespace std;

class MyThreadPool {
    public: 

        MyThreadPool(size_t poolSize) {
            num_workers = poolSize;
            stop = false;
            for (int i = 0 ; i < num_workers; i++) {
                workers.emplace_back(&MyThreadPool::process, this);
            }
        }

        template<typename F, typename ...Args>
        auto submit(F&& f, Args&& ...args)
        -> std::future<std::invoke_result_t<F, Args...>>
        {
            using R = std::invoke_result_t<F, Args...>;
            auto bound_task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);

            auto task = std::make_shared<std::packaged_task<R()>>(std::move(bound_task));
            future<R> fut = task->get_future();

            {
                std::unique_lock<std::mutex> lock(m);

                if (stop) {
                    throw std::runtime_error("ThreadPool is stopped");
                }

                tasks.emplace([task]() {
                    (*task)();
                });
            }

            cv.notify_one();
            return fut;
        }
        
        void terminate() {
            {
                lock_guard<mutex> l(m);
                stop = true;
            }
            cv.notify_all();

            for (auto &worker: workers) {
                worker.join();
            }
        }

    private: 
        queue<std::function<void()>> tasks;
        size_t num_workers;
        mutex m;
        condition_variable cv;
        vector<thread> workers;
        bool stop;
        
        void process() {
            // process the tasks from queue 
            while(true) {
                unique_lock<mutex> ul(m);
                cv.wait(ul, [this](){return tasks.size() > 0 || stop;});
                if (stop and tasks.empty()) {
                    return;
                }

                auto task = std::move(tasks.front());
                tasks.pop();
                ul.unlock();
                task();
            }        
        }
};



int main() {
    auto start = std::chrono::high_resolution_clock::now();


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;

    return 0;
}



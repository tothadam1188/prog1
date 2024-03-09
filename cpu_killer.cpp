#include <iostream>
#include <vector>
#include <thread>
#include <cmath>

void intensiveComputation()
    {
        double result = 0.0;
        for (int i = 0; i < 1000000; ++i)
            {
                result += std::sin(i) * std::cos(i);
            }
}

int main() {
    while (true)
        {
            unsigned int num_cores = std::thread::hardware_concurrency();
            std::vector<std::thread> threads;

            for (unsigned int i = 0; i < num_cores; ++i)
                {
                    threads.emplace_back(intensiveComputation);
                }

            for (auto& t : threads)
                {
                    t.join();
                }
    }

    return 0;
}

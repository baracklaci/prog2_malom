#ifndef RANDOM
#define RANDOM
#include <random>
#include <chrono>
#include <thread>

class backoff_time_t {
  public:
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_real_distribution<double>  dist;

    backoff_time_t() : rd{}, mt{rd()}, dist{0, 24} {}

    double rand() {
      return dist(mt);
    }
};

thread_local backoff_time_t backoff_time;


#endif

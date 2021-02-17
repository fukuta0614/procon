//
// Created by 福田圭佑 on 2021/02/09.
//

#pragma once


#include <chrono>

struct Timer {
    std::chrono::time_point<std::chrono::system_clock> begin;

    void init() {
        begin = std::chrono::system_clock::now();
    }

    int get_ms() {
        auto cur = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(cur - begin).count();
    }
};

#define start_time() Timer timer; timer.init(); std::cout << __FUNCTION__ << ":" << __LINE__ << " start\n"
#define print_time() std::cout << __FUNCTION__ << ":" << __LINE__ << " " << timer.get_ms() << "ms\n"
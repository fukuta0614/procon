//
// Created by 福田圭佑 on 2021/02/09.
//

#pragma once

#include <random>
#include <vector>

std::random_device rd;
std::mt19937 mt(rd());

template <typename T>
std::vector<T> random_vector(T mx, size_t sz){
    std::vector<T> v(sz);
    for (size_t i = 0; i < sz; ++i) {
        v[i] = mt() % mx;
    }
    return v;
}

std::string random_string(size_t sz){
    std::string s;
    for (size_t i = 0; i < sz; ++i){
        s += (mt() % 26) + 'a';
    }
    return s;
}
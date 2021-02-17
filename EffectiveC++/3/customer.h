#include <utility>

//
// Created by 福田圭佑 on 2021/02/17.
//

#pragma once


class Customer {
    string name;

public:
    Customer() = default;

    explicit Customer(string name) : name(std::move(name)) {
        print("defualt constructor");
    }

    Customer(const Customer& rhs) : name(rhs.name){
        print("Customer copy construcor");
    }

    Customer& operator=(const Customer& rhs){
        print("Customer copy assignment operator");
        name = rhs.name;
        return *this;
    }

};


class PriorityCustomer: public Customer{
    int priority;

public:
    PriorityCustomer() : priority(1) {
        print("defualt constructor");
    }

    PriorityCustomer(const PriorityCustomer& rhs) : priority(rhs.priority) {
        print("PriorityCustomer copy construcor");
    }

    PriorityCustomer& operator=(const PriorityCustomer& rhs){
        print("PriorityCustomer copy assignment operator");
        priority = rhs.priority;
        return *this;
    }
};
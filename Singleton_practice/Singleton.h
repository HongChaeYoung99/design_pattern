#pragma once
#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton(const Singleton& other);
    Singleton() { value = 5; };
    ~Singleton() {};
    int value;

public:
    static Singleton* GetInstance() {
        if (instance == NULL) {
            instance = new Singleton();
        }
        return instance;
    }
    int GetValue() { return value; };
    void SetValue(int a) { value = a; };
}; 

Singleton* Singleton::instance = NULL;
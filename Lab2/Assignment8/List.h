#pragma once
class List{
    private:
        double *arr;
        unsigned int size;
    public:
        List();
        ~List();
        void push_back(double x);
        void pop_first(double x);
        void pop_all(double x);
        void replace(int x, double y);
        void printL();
};
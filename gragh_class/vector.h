#ifndef VECTOR_H
#define VECTOR_H
#include "QDebug"
template <class T>
class Vector {
public:
    //    构造函数
    Vector(int size = 0) :theSize(size), theCapacity(size + SPACE_CAPACITY) {
        data = new T[theCapacity];
    }
    //    析构函数
    ~Vector(void) {
        delete[] data;
    }

    //调整大小
    void resize(int newSize){
        if(newSize <= theCapacity){
            theSize = newSize;
        }else{
            reServe(newSize * 2);
            theSize = newSize;
        }
    }

    //    重新分配空间大小函数
    void reServe(int newCapacity) {
        if (newCapacity <= theCapacity)
            return;

        T* temp = data;
        data = new T[newCapacity];
        for (int i = 0; i < theSize; ++i)
            data[i] = temp[i];
        delete[] temp;
    }
    //    push_back函数
    void push_back(T val) {
        if (theSize == theCapacity)
            reServe(2 * theCapacity + 1);
        data[theSize] = val;
        theSize++;
    }
    int size() {
        return theSize;
    }
    T& operator[](int i)
    {
        if (i > theSize)
        {
            //cout << "索引超过最大值" << endl;
            qDebug() << "索引超过最大值";
            // 返回第一个元素
            return data[0];
        }
        return data[i];
    }

    //头指针，排序的时候用一下
    T* begin()const{
        return data;
    }

private:
    const int SPACE_CAPACITY = 16;
    int theSize;
    int theCapacity;
    T* data;
};
#endif // VECTOR_H

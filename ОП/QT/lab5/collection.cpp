#include "collection.h"
#include <iostream>

Collection::Collection(){};

bool Collection::fillArray(QList<int> arr)
{
    clear();
    for (int value : arr){
        try{
            this->array.append(value);
        }
        catch(...){
            return false;
        }
    }

    return true;
}

QList<int> Collection::getArray()
{
    return this->array;
}

void Collection::clear()
{
    this->array.clear();
}

bool Collection::add_element(int index, int value)
{
    if (index >= 0 && index < array.size() || index == 0 && array.isEmpty()) {
        this->array.insert(index, value);
        return true;
    }
    else if(index == array.size()){
        this->array.append(value);
        return true;
    }
    else {
        return false;
    }
}

int Collection::sum_array()
{
    int s = 0;
    for (int el: this->array){
        s += el;
    }

    return s;
}

int Collection::sum_even()
{
    int s = 0;
    for (int el: this->array){
        if (el % 2 == 0){
            s += el;
        }
    }

    return s;
}

int::Collection::find_first()
{
    for (int i = 0; i < this->array.size(); i++){
        if (this->array[i] > 0){
            return i;
        }
    }

    return -1;
}


int::Collection::find_second()
{
    int ind = -1;
    for (int i = 0; i < this->array.size(); i++){
        if (this->array[i] > 0){
            ind = i;
        }
    }

    return ind;
}


QString Collection::find_element(int index)
{
    if (index >= 0 && index < array.size()){
        return QString::number(this->array[index]);
    }

    return QString::fromUtf8("Неверный индекс");
}

QString Collection::delete_by_index(int index)
{
    for (int i = 0; i < this->array.size(); i++){
        if (i == index){
            this->array.removeAt(i);
            return QString::fromUtf8("");        }
    }

    return QString::fromUtf8("Неверный индекс");
}

QString Collection::delete_by_value(int value)
{
    for (int i = 0; i < this->array.size(); i++){
        if (this->array[i] == value){
            this->array.removeAt(i);
            return QString::fromUtf8("");        }
    }

    return QString::fromUtf8("Неверное значение");
}

QList<int> Collection::task1()
{
    QList<int> arr = this->array;

    for(int i = 0; i < this->array.size(); i++){
        if (this->array[i] == 0){
            arr.removeAt(i);
            arr.insert(0, 0);
        }
    }

    return arr;
}

int Collection::task2()
{
    int ind1 = find_first(), ind2 = find_second();
    if (ind1 != 0 && ind2 != 0 && ind2 > ind1 || ind1 == ind2) {
        int s = 0;
        QList<int>::Iterator it = this->array.begin();

        std::advance(it, ind1 + 1);

        for (; it != this->array.begin() + ind2; ++it) {
            s += *it;
        }

        return s;
    }
    else {
        return 0;
    }
}


#ifndef COLLECTION_H
#define COLLECTION_H
#include <QList>

class Collection
{
private:
    QList<int> array;
public:
    Collection();

    bool fillArray(QList<int> arr);

    QList<int> getArray();

    void clear();

    bool add_element(int index, int value);

    int sum_array();
    int sum_even();

    int find_first();
    int find_second();

    QString find_element(int index);

    QString delete_by_index(int index);
    QString delete_by_value(int value);

    QList<int> task1();
    int task2();

};

#endif // COLLECTION_H

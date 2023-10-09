/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Структура записи в файле
struct AirportRecord {
    string departurePoint;
    int flightNumber;
    string arrivalDate;
    string arrivalTime;
    double arrivalDelayHours;
};

// Структура элемента хеш-таблицы
struct HashTableElement {
    AirportRecord flight;  // Ключ записи в файле
    int recordIndex;   // Номер записи с этим ключом в файле
    bool isDeleted;    // Флаг для пометки удаленных элементов

    HashTableElement() : flight(), recordIndex(-1), isDeleted(true) {}
};

// Класс хеш-таблицы
class HashTable {
private:
    vector<HashTableElement> table;
    int capacity;

public:
    HashTable(int size) : capacity(size) {
        table.resize(capacity);
    }
    vector<HashTableElement> getTable() {
        return table;
    }
    int hashFunction(int flightNumber) {
        return flightNumber % capacity;
    }

    void insert(const AirportRecord& record, int recordIndex) {
        int index = hashFunction(record.flightNumber);

        while (!table[index].isDeleted) {
            index = (index + 1) % capacity;
        }

        table[index].flight = record;
        table[index].recordIndex = recordIndex;
        table[index].isDeleted = false;
    }

    void remove(int flightNumber) {
        int index = findIndex(flightNumber);

        if (index != -1) {
            table[index].isDeleted = true;
        }
    }

    int findIndex(int flightNumber) {
        int index = hashFunction(flightNumber);
        int count = 0;

        while (count<capacity) {
            count++;
            if (table[index].flight.flightNumber == flightNumber && !table[index].isDeleted) {
                return index;
            }

            index = (index + 1) % capacity;
        }

        return -1;
    }

    void rehash() {
        int newCapacity = capacity * 2;
        vector<HashTableElement> newTable(newCapacity);

        for (const HashTableElement& element : table) {
            if (!element.isDeleted) {
                int newIndex = hashFunction(element.flight.flightNumber);

                while (!newTable[newIndex].isDeleted) {
                    newIndex = (newIndex + 1) % newCapacity;
                }

                newTable[newIndex] = element;
            }
        }

        table = newTable;
        capacity = newCapacity;
    }
};

void taskSecond() {
    HashTable airportTable(10);

    // Пример вставки записей
    cout << "Пример вставки записей:" << endl;
    AirportRecord record1 = { "New York", 101, "2023-10-08", "12:00", 0.5 };
    AirportRecord record2 = { "Los Angeles", 202, "2023-10-09", "14:30", 1.0 };
    AirportRecord record3 = { "Moscow", 303, "2023-10-09", "14:30", 1.0 };
    airportTable.insert(record1, 0);
    airportTable.insert(record2, 1);
    airportTable.insert(record3, 2);
    int foundIndex = airportTable.findIndex(303);
    if (foundIndex != -1) {
        cout << "Record found at index " << foundIndex << endl;
    }
    else {
        cout << "Record not found" << endl;
    }
    vector<HashTableElement> vector = airportTable.getTable();
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].recordIndex != -1) cout << airportTable.findIndex(vector[i].flight.flightNumber) << " " << vector[i].flight.departurePoint << " " << vector[i].flight.flightNumber << " " << vector[i].flight.arrivalDate << " " << vector[i].flight.arrivalTime << " " << vector[i].flight.arrivalDelayHours << endl;
    }
    // Пример вставки ключа и разрешение коллизии
    cout << endl << "Пример вставки ключа и разрешение коллизии:" << endl;
    AirportRecord record4 = { "Saint P", 503, "2023-10-09", "14:30", 1.0 };
    airportTable.insert(record4, 3);
    foundIndex = airportTable.findIndex(503);
    if (foundIndex != -1) {
        cout << "Record found at index " << foundIndex << endl;
    }
    else {
        cout << "Record not found" << endl;
    }
    vector = airportTable.getTable();
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].recordIndex != -1) cout << airportTable.findIndex(vector[i].flight.flightNumber) << " " << vector[i].flight.departurePoint << " " << vector[i].flight.flightNumber << " " << vector[i].flight.arrivalDate << " " << vector[i].flight.arrivalTime << " " << vector[i].flight.arrivalDelayHours << endl;
    }
    // Пример удаления записи
    cout << endl << "Пример удаления записи:" << endl;
    airportTable.remove(303);
    foundIndex = airportTable.findIndex(303);
    if (foundIndex != -1) {
        cout << "Record found at index " << foundIndex << endl;
    }
    else {
        cout << "Record not found" << endl;
    }
    vector = airportTable.getTable();
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].recordIndex != -1) cout << airportTable.findIndex(vector[i].flight.flightNumber) << " " << vector[i].flight.departurePoint << " " << vector[i].flight.flightNumber << " " << vector[i].flight.arrivalDate << " " << vector[i].flight.arrivalTime << " " << vector[i].flight.arrivalDelayHours << endl;
    }
    // Пример вставки ключа с рехешированием
    cout << endl << "Пример вставки ключа с рехешированием:" << endl;
    airportTable.rehash();
    foundIndex = airportTable.findIndex(503);
    if (foundIndex != -1) {
        cout << "Record found at index " << foundIndex << endl;
    }
    else {
        cout << "Record not found" << endl;
    }
    vector = airportTable.getTable();
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i].recordIndex != -1) cout << airportTable.findIndex(vector[i].flight.flightNumber) << " " << vector[i].flight.departurePoint << " " << vector[i].flight.flightNumber << " " << vector[i].flight.arrivalDate << " " << vector[i].flight.arrivalTime << " " << vector[i].flight.arrivalDelayHours << endl;
    }
}
int main() {
    setlocale(LC_ALL, "ru");
    taskSecond();
    return 0;
}
*/
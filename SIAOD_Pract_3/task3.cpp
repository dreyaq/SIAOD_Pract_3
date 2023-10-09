
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TABLE_SIZE = 100000; // Размер хеш-таблицы
const string FILE_NAME = "C://Users//hyper//Desktop//ВУЗ//СИАОД//Практическая работа 3//records.dat"; // Имя бинарного файла

struct Record {
    int key;
    // Дополнительные поля, если необходимо
};

class HashTable {
private:
    Record table[TABLE_SIZE];

    // Хеш-функция
    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Конструктор
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].key = -1; // Инициализируем ключи в таблице значением -1 (пусто)
        }
    }

    // Метод для вставки записи в таблицу и файл
    void insert(int key) {
        int index = hash(key);

        while (table[index].key != -1) {
            // Применяем метод открытой адресации (смещение на 1)
            index = (index + 1) % TABLE_SIZE;
        }

        table[index].key = key;

        // Записываем запись в файл
        ofstream file(FILE_NAME, ios::app | ios::binary);
        if (file.is_open()) {
            file.write(reinterpret_cast<char*>(&key), sizeof(int));
            file.close();
        }
    }

    // Метод для удаления записи из таблицы и файла
    void remove(int key) {
        int index = hash(key);

        while (table[index].key != key) {
            // Применяем метод открытой адресации (смещение на 1)
            index = (index + 1) % TABLE_SIZE;
        }

        table[index].key = -1;

        // Удаляем запись из файла
        ifstream inFile(FILE_NAME, ios::binary);
        ofstream outFile("C://Users//hyper//Desktop//ВУЗ//СИАОД//Практическая работа 3//timed.dat", ios::binary);

        if (inFile.is_open() && outFile.is_open()) {
            int readKey;
            while (inFile.read(reinterpret_cast<char*>(&readKey), sizeof(int))) {
                if (readKey != key) {
                    outFile.write(reinterpret_cast<char*>(&readKey), sizeof(int));
                }
            }
            inFile.close();
            outFile.close();

            //std::remove(FILE_NAME.c_str());
            //rename("C://Users//hyper//Desktop//ВУЗ//СИАОД//Практическая работа 3//timed.dat", FILE_NAME.c_str());
        }
    }

    // Метод для поиска записи в файле по значению ключа
    int find(int key) {
        int index = hash(key);
        int count = 0;

        while (table[index].key != key) {
            // Применяем метод открытой адресации (смещение на 1)
            index = (index + 1) % TABLE_SIZE;
            count++;
            if (count == TABLE_SIZE) return -1;
        }

        // Находим номер записи с этим ключом в файле
        int recordNumber = -1;
        ifstream file(FILE_NAME, ios::binary);
        if (file.is_open()) {
            int readKey;
            int currentRecordNumber = 0;
            while (file.read(reinterpret_cast<char*>(&readKey), sizeof(int))) {
                if (readKey == key) {
                    recordNumber = currentRecordNumber;
                    break;
                }
                currentRecordNumber++;
            }
            file.close();
        }

        return recordNumber;
    }
};

int main() {
    HashTable hashtable;

    // Пример использования
    for (int i = 0; i < 100000-1; i++) {hashtable.insert(i);}
    int searchKey = 52;
    int recordNumber = hashtable.find(searchKey);
    if (recordNumber != -1) {
        std::cout << "Record with key " << searchKey << " found at position " << recordNumber << std::endl;
    }
    else {
        std::cout << "Record with key " << searchKey << " not found" << std::endl;
    }

    hashtable.remove(23);
    hashtable.remove(52);
    hashtable.remove(42);
    hashtable.remove(15);

    searchKey = 52;
    recordNumber = hashtable.find(searchKey);
    if (recordNumber != -1) {
        std::cout << "Record with key " << searchKey << " found at position " << recordNumber << std::endl;
    }
    else {
        std::cout << "Record with key " << searchKey << " not found" << std::endl;
    }
    return 0;
}


#include <iostream>
#include <ctime>
using namespace std;

//Наполнение массива рандомными числами
int **fillingArr(int **arr, int rows, int cols) {
    int numbers = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = numbers;
            numbers++;
            }
        }
    return arr;
}
void outputArr(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

//Наполнение массивов рандомным порядком элемнентов
int *randArrNum(int *arr, int size) {
    bool flag;
    for (int i = 0; i < size; ) {
        flag = false;
        int newRandom = rand() % size;
        for (int j = 0; j < i; j++) {
            if (arr[j] == newRandom) {
                flag = true;
            }
        }
        if (!flag) {
            arr[i] = newRandom;
            i++;
        }
    }
    return arr;
}

int main() {
    srand(time(NULL));
    int rows = 0;
    int cols = 0;
    int count = 0;
    
    cout << "Enter rows count: ";
    cin >> rows;
    cout << "Enter cols count: ";
    cin >> cols;
    //Создание двумерного динамического массива
    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int [cols];
    }

    //Наполнение массива
    fillingArr(arr, rows, cols);
    
    //Вывод элементов массива
    outputArr(arr, rows, cols);
    
    //Создание одномерного динамического массива
    int *mas = new int[(rows * rows) + (cols * cols)];
    
    //Создание рандомного массива строк
    int *randRows = new int [rows];
    randRows = randArrNum(randRows, rows);
    
    //Создание рандомного массива столбцов
    int *randCols = new int [cols];
    randCols = randArrNum(randCols, cols);
    
    cout << "___________________ Наполнение массива строкам" << endl;
    
    //Наполнение массива строкам
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mas[count] = arr[randRows[i]][j];
            cout << arr[randRows[i]][j] << "\t";
            count++;
        }
        cout << endl;
    }
    
    cout << "___________________ Наполнение массива столбцами" << endl;
    
    //Наполнение массива столбцами
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            mas[count] = arr[j][randCols[i]];
            cout << arr[j][randCols[i]] << "\t";
            count++;
        }
        cout << endl;
    }
    
    //Вывол элементов одномерного массива
    for (int i = 0; i < count; i++) {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
    
    //Очистка из памяти двумерного динамического массива arr
    for (int i = 0; i < cols; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    //Очистка из памяти одномерного динамического массива randRows
    delete[] randRows;

    //Очистка из памяти одномерного динамического массива randCols
    delete[] randCols;
    randCols = nullptr;
    
    int num = 0;
    cout << "___________________ Наполнение нового массива строками num = " << num << endl;
    
    
    for (; num < count/2; num++) {
        randRows[num] = mas[num];
        cout << randRows[num] << "\t";
    }
    cout << endl;
    
    int **arr2 = new int *[rows];
    for (int i = 0; i < rows; i++) {
        arr2[i] = new int [cols];
    }
    
    fillingArr(arr2, rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < count/2;j++) {
            if (cols % 2 == 0) {
               
            } else {
                if (randRows[i] == mas[count/2 + j]) {
                    if (cols > j) {
                        cout << "cols > j" << endl;
                        cout << "Когда i = " << i << endl;
                        cout << "Когда j = " << j << endl;
                        for (int k = 0; k < cols; k++) {
                            arr2[k][i] = mas[count/2 + k];
                        }
                        outputArr(arr2, rows, cols);
                        j = count/2;
                    } else if (j - cols < cols) {
                        cout << "j - cols < cols" << endl;
                        cout << "Когда i = " << i << endl;
                        cout << "Когда j = " << j << endl;
                        int add = 0;
                        for (int k = cols; k < cols * 2; k++) {
                            arr2[add][i] = mas[count/2 + k];
                            add++;
                        }
                        outputArr(arr2, rows, cols);
                        
                        j = count/2;
                    } else {
                        cout << "else" << endl;
                        cout << "Когда i = " << i << endl;
                        cout << "Когда j = " << j << endl;
                        int add = 0;
                        for (int k = cols * 2; k < cols * 3; k++) {
                            arr2[add][i] = mas[count/2 + k];
                            add++;
                        
                        }
                        outputArr(arr2, rows, cols);
                    }
                }
            }
        }
    }
    
    //Очистка памяти одномерного динамического массива
    delete[] mas;
    mas = nullptr;
    
    //Очистка из памяти двумерного динамического массива
    for (int i = 0; i < cols; i++) {
        delete[] arr2[i];
    }
    delete[] arr2;
    arr2 = nullptr;
        
    return 0;
}

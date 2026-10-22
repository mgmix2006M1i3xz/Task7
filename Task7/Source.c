#include <stdio.h>
#include <locale.h>
#include <math.h>

int word1() {
    char c;
    printf("Введите один символ: ");
    scanf("%c", &c);

    // Используем switch. Так как '0'...'9' идут подряд, 
    // можно использовать "проваливание" (без break) для диапазона.
    switch (c) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        printf("Это цифра.\n");
        break;

        // Для букв можно проверить заглавные и строчные (a-z, A-Z)
        // В теории сказано, что switch работает с целочисленными типами, 
        // поэтому это сработает.
    default:
        // Простая проверка, является ли символ буквой (по диапазону ASCII)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("Это буква.\n");
        }
        else {
            printf("Это другой символ (знак препинания, пробел и т.д.).\n");
        }
        break;
    }
    return 0;
}

int word2() {
    float x, y;
    char c;

    printf("Введите выражение (например, 5+3 или 2*4):\n");
    // Формат ввода: число, символ операции, число (без пробелов)
    scanf("%f%c%f", &x, &c, &y);

    // Интерпретация символа с помощью switch
    switch (c) {
    case '+':
        printf("= %f\n", x + y);
        break;
    case '-':
        printf("= %f\n", x - y);
        break;
    case '*':
        printf("= %f\n", x * y);
        break;
    case '/':
        // Проверка деления на ноль
        if (y != 0) {
            printf("= %f\n", x / y);
        }
        else {
            printf("Ошибка: деление на ноль!\n");
        }
        break;

        // Дополнительный функционал: возведение в степень
    case '^':
        printf("= %f\n", pow(x, y));
        break;

    default:
        printf("Ошибка: неизвестная операция '%c'\n", c);
        break;
    }

    return 0;
}

int word3() {
    char key;

    printf("Нажмите любую цифровую клавишу: ");

    // Функция getch() считывает символ с клавиатуры БЕЗ нажатия Enter 
    // и не отображает его на экране (эхо).
    key = getch();

    // Выводим нажатую клавишу на экран (так как getch её скрыл)
    printf("%c\n", key);

    // Используем switch для проверки, является ли символ цифрой
    switch (key) {
    case '0':
        printf("Была нажата клавиша: 0\n");
        break;
    case '1':
        printf("Была нажата клавиша: 1\n");
        break;
    case '2':
        printf("Была нажата клавиша: 2\n");
        break;
    case '3':
        printf("Была нажата клавиша: 3\n");
        break;
    case '4':
        printf("Была нажата клавиша: 4\n");
        break;
    case '5':
        printf("Была нажата клавиша: 5\n");
        break;
    case '6':
        printf("Была нажата клавиша: 6\n");
        break;
    case '7':
        printf("Была нажата клавиша: 7\n");
        break;
    case '8':
        printf("Была нажата клавиша: 8\n");
        break;
    case '9':
        printf("Была нажата клавиша: 9\n");
        break;
    default:
        printf("Это не цифровая клавиша.\n");
        break;
    }

    return 0;
}

int main() {

    setlocale(LC_ALL, "Rus");
    word1();
    word2();
    word3();

    return 0;
}
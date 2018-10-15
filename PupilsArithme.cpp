#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

char operation(int operation);
float createEquation();
float calculate(int number1, int number2, int operation);

const int plus = 1, subtract = 2, multiplication = 3, division = 4;
int main () {
    int num, i;
    printf("请输入题目个数:");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        createEquation();
    }


}

float createEquation() {
    int number1, number2, number3, operation1, operation2;
    float input_answer, answer = 0;
    do {
        srand(time(0));
        number1 = rand()%100+1;
        number2 = rand()%100+1;
        number3 = rand()%100+1;
        operation1 = rand()%4+1;
        operation2 = rand()%4+1;
        if(operation1 == multiplication || operation1 == division) {
            answer = calculate(calculate(number1, number2, operation1), number3, operation2 );
        }
        else {
            if(operation2 == multiplication || operation2 == division) {
                answer = calculate(number1 ,calculate(number2, number3, operation1), operation2 );
            }
            else {
                answer = calculate(calculate(number1, number2, operation1), number3, operation2 );
            }
        }
    }while(answer < 0);
    printf("%d %c %d %c %d =",number1, operation(operation1),number2, operation(operation2), number3);
    scanf("%f", &input_answer);
    if(answer == input_answer) {
        printf("对了");
    }
    else {
        printf("正确答案是%f", answer);
    }

    printf("\n");
}

char operation(int operation) {
    char c;
    switch(operation) {
        case plus:
            c = '+';
            break;
        case subtract:
            c = '-';
            break;
        case multiplication:
            c = '*';
            break;
        case division:
            c = '/';
            break;
    }
    return c;
}

float calculate(int number1, int number2, int operation) {
    switch(operation) {
        case plus:
            return (float)number1 + number2;
        case subtract:
            return (float)number1 - number2;
        case multiplication:
            return (float)number1 * number2;
        case division:
            return (float)number1 / number2;
    }
}

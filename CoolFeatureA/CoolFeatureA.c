/*
    FILE: CoolFeatureA.c
    AUTHOR: Tristin A. Manson
    FIRST-VERSION: April 13th, 2024
    DESCRIPTION:
        This program holds data structures and functions for calculating
        employee payroll.
*/
// ----------------------------------------------------------------------------
#include <stdio.h>

const double TAX_RATES[] = { 0.33, 0.26, 0.15 };

typedef struct {
    unsigned int id;
    char* trade;
    double hourlyWage;
    double currentHours;
} Worker;

// ----------------------------------------------------------------------------
double getNetPay(Worker* worker);
void printWorker(Worker*);

// ----------------------------------------------------------------------------
int main(void) {
    Worker johnDoe = { 123456, "Carpenter", 26.75, 40.0 };
    printWorker(&johnDoe);
    printf("John's gross pay: $%.2lf\n", johnDoe.hourlyWage * johnDoe.currentHours);
    printf("John's net pay: $%.2lf\n", getNetPay(&johnDoe));
    return 0;
}

// ----------------------------------------------------------------------------
void printWorker(Worker* worker) {
    printf(
        "Worker ID: %u\n  Trade: %s\n  Wage: $%.2lf\n  Current hours worked: %.1lf\n",
        worker->id,
        worker->trade,
        worker->hourlyWage,
        worker->currentHours
    );
}

double getNetPay(Worker* worker) {
    double hoursWorked = worker->currentHours;
    double wage = worker->hourlyWage;
    double grossPay = hoursWorked * wage;
    if (wage < 26.86) {
        return grossPay - (grossPay * TAX_RATES[2]);
    }
    if (wage > 26.86 && wage < 83.27) {
        return grossPay - (grossPay * TAX_RATES[1]);
    }
    if (wage > 83.27) {
        return grossPay - (grossPay * TAX_RATES[0]);
    }
    worker->currentHours = 0.0;
    return -1.0;
}
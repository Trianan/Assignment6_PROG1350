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

const double TAX_RATES[] = { 0.15, 0.26, 0.33 };

typedef struct {
    char* name;
    unsigned int id;
    char* trade;
    double hourlyWage;
    double currentHours;
} Worker;

// ----------------------------------------------------------------------------
double calculateNetPay(Worker* worker);
void printWorker(Worker*);

// ----------------------------------------------------------------------------
int main(void) {
    Worker johnDoe = { "John Doe", 123456, "Carpenter", 26.75, 40.0 };
    printWorker(&johnDoe);
    printf("%s's gross pay: $%.2lf\n", johnDoe.name, johnDoe.hourlyWage * johnDoe.currentHours);
    printf("%s's net pay: $%.2lf\n", johnDoe.name, calculateNetPay(&johnDoe));
    return 0;
}

// ----------------------------------------------------------------------------
void printWorker(Worker* worker) {
    printf(
        "Name: %s\n  ID: %u\n  Trade: %s\n  Wage: $%.2lf\n  Current hours worked: %.1lf\n",
        worker->name,
        worker->id,
        worker->trade,
        worker->hourlyWage,
        worker->currentHours
    );
}

double calculateNetPay(Worker* worker) {
    double hoursWorked = worker->currentHours;
    double wage = worker->hourlyWage;
    double grossPay = hoursWorked * wage;
    if (wage < 26.86) {
        return grossPay - (grossPay * TAX_RATES[0]);
    }
    if (wage > 26.86 && wage < 83.27) {
        return grossPay - (grossPay * TAX_RATES[1]);
    }
    if (wage > 83.27) {
        return grossPay - (grossPay * TAX_RATES[2]);
    }
    worker->currentHours = 0.0;
    return -1.0;
}
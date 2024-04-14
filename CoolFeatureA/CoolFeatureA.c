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

const double TAX_RATE = 0.205;

typedef struct {
    unsigned int id;
    char* trade;
    double hourlyWage;
    double currentHours;
} Worker;

// ----------------------------------------------------------------------------
double getGrossPay(Worker*);
double calculateNetPay(double);
void printWorker(Worker*);

// ----------------------------------------------------------------------------
int main(void) {

    Worker johnDoe = { 123456, "Carpenter", 26.75, 40.0 };
    printWorker(&johnDoe);
    printf("Gross pay for %u (%.1lf hours): ", johnDoe.id, johnDoe.currentHours);
    double johnGrossPay = getGrossPay(&johnDoe);
    printf("$%.2lf\n", johnGrossPay);
    printf("\tTake-home pay: $%.2lf\n", calculateNetPay(johnGrossPay));
    return 0;
}

// ----------------------------------------------------------------------------
double getGrossPay(Worker* worker) {
    double hoursWorked = worker->currentHours;
    worker->currentHours = 0.0;
    return hoursWorked * worker->hourlyWage;
}

void printWorker(Worker* worker) {
    printf(
        "Worker ID: %u\n  Trade: %s\n  Wage: $%.2lf\n  Current hours worked: %.1lf\n",
        worker->id,
        worker->trade,
        worker->hourlyWage,
        worker->currentHours
    );
}

double calculateNetPay(double grossPay) {
    return grossPay - (grossPay * TAX_RATE);
}
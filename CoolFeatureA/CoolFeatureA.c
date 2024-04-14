#include <stdio.h>

typedef struct {
    unsigned int id;
    char* trade;
    double hourlyWage;
    double currentHours;
} Worker;

double getGrossPay(Worker*);
void printWorker(Worker*);

int main(void) {

    Worker johnDoe = { 123456, "Carpenter", 26.75, 40.0 };
    printWorker(&johnDoe);
    printf("Gross pay for %u (%.1lf hours): ", johnDoe.id, johnDoe.currentHours);
    printf("$%.2lf\n", getGrossPay(&johnDoe));
    return 0;
}

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
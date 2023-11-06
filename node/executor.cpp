#include "executor.h"

Executor::Executor(QObject* executedobj, QObject* parent) : QObject(parent), obj(executedobj)
{}

Executor::~Executor()
{}
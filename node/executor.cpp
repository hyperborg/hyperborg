#include "executor.h"

Executor::Executor(HFS_Interface *hfsi, QObject* parent) : QObject(parent), hfs(hfsi)
{}

Executor::~Executor()
{}
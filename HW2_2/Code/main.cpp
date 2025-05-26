#include "CommandBoundary.h"

int main() {
    CommandBoundary boundary;
    boundary.processCommands("input.txt", "output.txt");
    return 0;
}

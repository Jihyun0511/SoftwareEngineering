#include "CommandBoundary.h"

int main() {
    CommandBoundary boundary;
    boundary.processCommands("input.txt", "output.txt"); //파일 입출력 함수 실행
    return 0;
}

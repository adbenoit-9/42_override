#include <stdio.h>

int main() {
    char res;

    for (int i = 0; i < 22; i++) {
        res = i ^ 'Q';
        if (res == 'C')
            printf("nb = %d\n", i);
    }
}

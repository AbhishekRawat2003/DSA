// #include <stdio.h>
// int r()
// {
//     static int num = 7;
//     return num --;
// }
// int main()
// {
//     for (r(); r(); r())
//         printf("% d", r());
//     return 0;
// }


#include <stdio.h>

int r() {
    static int num = 7;

    printf("\n[r() called] num before = %d", num);

    int returned_value = num;
    num--;

    printf("\n[r() returns] %d, num after = %d\n",
           returned_value, num);

    return returned_value;
}

int main() {

    printf("\n--- START ---\n");

    for (r(); r(); r()) {
        printf("[BODY] r() output = %d\n", r());
    }

    printf("\n--- END ---\n");

    return 0;
}
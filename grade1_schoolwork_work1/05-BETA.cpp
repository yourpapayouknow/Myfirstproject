#include <iostream>

void exchange_pointer2(int **pa, int **pb) {
    int* temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("%s%d%s%s%d\n", "a=", **pa, ",", "b=", **pb); // Fixed dereference to show values
}

int main() {
    int a = 10;
    int b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;
    
    exchange_pointer2(&ptr1, &ptr2);
    std::cout << "After exchange: *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << std::endl;

    return 0;
}
#include<stdio.h>


typedef unsigned char* byte_pointer;



void show_bytes(byte_pointer start, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

void show_int(int a)
{
    show_bytes((byte_pointer)&a, sizeof(a));
}

void show_float(float a)
{
    show_bytes((byte_pointer)&a, sizeof(a));
}

void show_pointer(void* a)
{
    show_bytes((byte_pointer)&a, sizeof(a));
}

int main()
{
    //int a = 1034;
    //show_int(a);
    //float b = 3.14;
    //show_float(b);

    int val = 0X12345678;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
}
template <class T>
void swap(T *a, T *b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

// #include <iostream>
// int main()
// {
//     int a = 1;
//     int b = 2;
//     swap(a, b);
//     std::cout << "a:" << a << std::endl;
//     return 0;
// }
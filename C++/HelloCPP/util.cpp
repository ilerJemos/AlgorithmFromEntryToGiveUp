template <class T>
void mySwap(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template<class T>
T myMax(T a, T b) {
	return (a + b + abs(a - b)) / 2;
}

template<class T>
T myMin(T a, T b) {
	return(a + b - abs(a - b)) / 2;
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

比较大的数组应该声明在main函数的外面，否则程序可能无法运行
结构体定义 struct Point{double x,y;}; 
常用方式typedef struct{double x, y;}Point;
使用约分避免程序溢出 
对复杂的表达式进行简化不仅能减少计算量，还能避免中间结果溢出
C++中推荐使用const 而不是#define 
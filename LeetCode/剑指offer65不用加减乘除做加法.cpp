//鲤鱼焙面，汇编做法
int add(int a, int b){
    //c语言内联汇编关键字
    __asm(
        "addl %%ecx,%%eax\n"//内联汇编表达式,将ecx寄存器中的值和eax寄存器中的值加起来,存放到eax寄存器中,l表示类型
        :"=a"(a)//"=a"表示将结果存放到eax寄存器中,(a)表示使用变量a存储eax寄存器的值
        :"c"(a),"a"(b)//"c"(a)表示将变量a的值赋给ecx寄存器,"a"(b)同理
    );
    return a;
}

// int add(int a, int b) {
//     while (b) {
//         int c = (unsigned int)(a & b) << 1;
//         a ^= b;
//         b = c;
//     }
//     return a;
// }
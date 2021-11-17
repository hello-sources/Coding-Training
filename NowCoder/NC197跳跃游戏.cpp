/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int整型一维数组 
 * @param numsLen int nums数组长度
 * @return bool布尔型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
#include <stdbool.h>
bool canJump(int* nums, int numsLen ) {
    // write code here
    int max = 0;
    for(int i = 0; i < numsLen; i++){
        if(max < i)
            return false;
        max = max < i + nums[i] ? i + nums[i] : max;
    }
    return true;

}
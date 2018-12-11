# 插入排序(Insertion sort)

>The value of life lies not in the length of days, but on the use we make of them.

####  程序思路

> 假设总共有n组数据

- 令   i = 2  ->  n
- 令	 j=i -> 0 
- 比较 j 和 j-1 
    - 1.如果j-1 > j 
        - j开始-1
        - 如果  j-1  > j
          - 交换 j 和 j - 1 的值

## Code
#### **code-1**
```c
for(int i=1,j; i < n; i++)
{
    for(j=i; i>0; j--)
    {
        if(number[j-1] < number[j])
        {
            int temp = number[j];
            number[j] = number[j-1];
            number[j-1] = temp;
        }
        else
        {
            break;
        }
    }
}
```

#### **code-2**

```c
for(int i=1; i<n; i++)
{
    int key = number[i],j=i-1;
    while(j >= 0 && number[j] > key)
    {
        number[j+1] = number[j];
        j--;
        number[j+1] = key;
   	}
}
```
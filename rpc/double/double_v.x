/*参数结构体*/
struct double_in
{
    long key;
};
/*返回值结构体*/
struct double_out
{
    long value;
};

/*调用程序*/
program DOUBLE_PROG
{
    /*版本号*/
    version DOUBLE_VERS1
    {
        /*调用程序*/
        double_out double_func(double_in)=1;/*这是个程序标号*/
    } = 1;/*这个1就是版本号*/
    version DOUBLE_VERS2
    {
        void double_func(double_in) = 1;
        void double_func2(double_in) = 2;
        
    } = 2;
    version DOUBLE_VERS3
    {
        double_out double_func(string) = 1;
    } =12;
}=0x12345678;


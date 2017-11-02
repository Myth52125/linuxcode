
#include <string.h>
//strcpy()
//改变第二个第一个不变，因此第二个是const
char *strcpy(char *dst, const char *src)
{
    //任意一个空指针，直接返回
    if ((dst == NULL) || (src == NULL))
    {
        return NULL;
    }
    //保存首指针，用来返回
    char *ret = dst;
    //循环拷贝
    //直到最后一个为'\0'，这个字符也拷贝
    while ((*dst++ = *src++) != '\0')
        ;
    //返回头指针
    return ret;
}

//当第一个长度长于第二个，那么在复制第二个的'\0'以后，就被截断了。
//在输出的时候不会输出后面的字符

// 当第一个短的时候，可能引起越界写。因此有strncpy()

// strncpy()
// C和指针》p179给出的答案是：
// “和strcpy一样，strncpy把源字符串的字符复制到目标数组。然而，它总是正好向dst写入len个字符。
// 如果strlen(src)的值小于len，dst数组就用额外的NUL字节填充到len长度，
// 如果strlen(src)的值大于或等于len，那么只有len个字符被复制到dst中。”
// 注意！它的结果将不会以NUL字节结尾。（NUL即‘\0’）.
char *strncpy(char *dest, char *src, unsigned int n)
{
    //保存头指针
    char *strRtn = dest;
    //n != 0,并且
    while (n && (*dest++ = *src++) != '\0' )
    {
        n--;
    }
    if (n)
    {
        while (--n)
            *dest++ = '\0';
    }
    return strRtn;
}

// strncpy并不会负责添加‘\0’到dst结尾，因此，输出该字符串是，会在e字符后面一直找到‘\0’才结束，因此就会出现乱码。

//当源字符串和目标字符串，重叠的时候
// 也就是从字符串中间开始，拷贝到头部。或者是头部向中间拷贝。
// 那么很自然的应该是从后向前拷贝
// 因此需要知道，字符串的长度
char *strncpy(char *dest, char *src, unsigned int n)
{
    //获取源的长度
    int len = strlen(src);
    
    //返回指针
    char *ret = dest;

    if (dest >= src && dest <= src + len - 1)
    {
        //这里要不要防止n越界？应该不用吧,用户来判定。
        // int src_len=strlen(src);
        // if(dest+src_len<src+n)
        // {
        //     n=src_len-(dest-src)-1;
        // }
        while (n && (*(dest + n - 1) = *(src + n - 1)))
        {
            n--;
        }
        dest +=n-1;
        src +=n-1;
        //防止dest没有'\0'
        *dest='\0';
    }
    else
    {
        while (n && (*dest++ = *src++))
        {
            n--;
        }

        while (n--)
        {
            *dest++ = '\0';
        }
    }
    return ret;
}
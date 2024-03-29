template <typename T>

void iter(T arr[],unsigned long len, void (*pf)(T &))
{
    for (unsigned long i = 0; i < len; ++i)
        pf(arr[i]);
}

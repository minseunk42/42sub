template <typename T, typename V>

void iter(T arr[],unsigned long len, void (*pf)(V &v))
{
    for (unsigned long i = 0; i < len; ++i)
        pf(arr[i]);
}

template <typename T, typename U>

void iter(T arr[],unsigned long len, void (*pf)(U))
{
    for (unsigned long i = 0; i < len; ++i)
        pf(arr[i]);
}
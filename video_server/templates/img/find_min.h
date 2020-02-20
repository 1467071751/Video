#ifndef FIND_MIN_H_
#define FIND_MIN_H_

unsigned find_min(const unsigned * v, unsigned n)
{
    unsigned j = 0, i = 1;
    for(; i < n; ++i)
        if(v[i] < v[j])
            j = i;// 记住最小随机数的下标
    return j;
}

#endif // FIND_MIN_H_

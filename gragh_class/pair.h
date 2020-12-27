#ifndef PAIR_H
#define PAIR_H

template <class _T1, class _T2>
class Pair
{

public:
    _T1 first;
    _T2 second;
    Pair(): first(), second() {}  //用无参构造函数初始化 first 和 second
    Pair(const _T1 &__a, const _T2 &__b): first(__a), second(__b) {}    //有参构造

    template <class _U1, class _U2> //拷贝构造
    Pair(const Pair <_U1, _U2> &__p): first(__p.first), second(__p.second) {}

};

#endif // PAIR_H

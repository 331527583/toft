// Copyright (c) 2010, The Toft Authors.
// All rights reserved.
//
// Author: CHEN Feng <chen3feng@gmail.com>

#ifndef TOFT_BASE_STATIC_ASSERT_H
#define TOFT_BASE_STATIC_ASSERT_H

#if __GXX_EXPERIMENTAL_CXX0X__ || defined __MSC_VER && __MSC_VER >= 1600
#define STATIC_ASSERT(e, ...) static_assert(e, "" __VA_ARGS__)
#else

#include "toft/base/preprocess/join.h"

namespace toft {

template <bool x> struct static_assertion_failure;

template <> struct static_assertion_failure<true> {
    enum { value = 1 };
};

template<int x> struct static_assert_test {};

/// �����ڼ�ľ�̬����
/// @param e �������ʽ
/// ���ڱ����ڼ������ĳ��ϣ�ʾ����
/// @code
/// STATIC_ASSERT(sizeof(Foo) == 48, "Foo �Ĵ�С����Ϊ 48");
/// @endcode
#define TOFT_STATIC_ASSERT(e, ...) \
    typedef ::toft::static_assert_test< \
            sizeof(::toft::static_assertion_failure<(bool)(e)>)> \
            TOFT_PP_JOIN(static_assert_failed, __LINE__)

} // namespace toft
#endif // __GXX_EXPERIMENTAL_CXX0X__

#endif // TOFT_BASE_STATIC_ASSERT_H


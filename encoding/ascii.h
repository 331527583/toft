// Copyright (c) 2011, The Toft Authors.
// All rights reserved.
//
// Author: CHEN Feng <chen3feng@gmail.com>

#ifndef TOFT_ENCODING_ASCII_H
#define TOFT_ENCODING_ASCII_H

#include <limits.h>
#include <stdint.h>

namespace toft {

// רΪ ASCII �ض��ĺ���������漰�� locale����ʹ�ñ�׼ C �� ctype.h
// �ﶨ��ĺ�����
struct Ascii
{
private:
    Ascii();
    ~Ascii();
private:
    /// �ַ����͵�����
    enum CharTypeMask
    {
        kUpper = 1 << 0,
        kLower = 1 << 1,
        kDigit = 1 << 2,
        kHexDigit = 1 << 3,
        kBlank = 1 << 4,
        kSpace = 1 << 5,
        kControl = 1 << 6,
        kPunct = 1 << 7,
        kPrint = 1 << 8,
        kGraph = 1 << 9,
    };
public:
    /** �ж��ǲ�����Ч�� ASCII �� */
    static bool IsValid(char c)
    {
        return (c & 0x80) == 0;
    }

    static inline bool IsLower(char c)
    {
        return CharIncludeAnyTypeMask(c, kLower);
    }

    static inline bool IsUpper(char c)
    {
        return CharIncludeAnyTypeMask(c, kUpper);
    }

    /** �ж��Ƿ�Ϊ��ĸ */
    static bool IsAlpha(char c)
    {
        return CharIncludeAnyTypeMask(c, kUpper | kLower);
    }

    /** �ж��Ƿ�Ϊ���� */
    static bool IsDigit(char c)
    {
        return CharIncludeAnyTypeMask(c, kDigit);
    }

    /** �ж��Ƿ�ΪӢ�Ļ�����  */
    static bool IsAlphaNumber(char c)
    {
        return CharIncludeAnyTypeMask(c, kUpper | kLower | kDigit);
    }

    /** �ж��Ƿ�Ϊ�հ��ַ����ո�,'\t', ' ' �����հ��ַ�*/
    static bool IsBlank(char c)
    {
        return CharIncludeAnyTypeMask(c, kBlank);
    }

    /** �ж��Ƿ�Ϊ����ַ���*/
    static inline bool IsSpace(char c)
    {
        return CharIncludeAnyTypeMask(c, kSpace);
    }

    /** �ж��Ƿ�Ϊ�����ַ���*/
    static bool IsControl(char c)
    {
        return CharIncludeAnyTypeMask(c, kControl);
    }

    /** �ж��Ƿ�Ϊ�������ַ���*/
    static inline bool IsPunct(char c)
    {
        return CharIncludeAnyTypeMask(c, kPunct);
    }

    /** �ж��Ƿ�Ϊʮ�����������ַ���*/
    static inline bool IsHexDigit(char c)
    {
        return CharIncludeAnyTypeMask(c, kHexDigit);
    }

    /** �ж��Ƿ�Ϊ�ɼ��ַ���*/
    static inline bool IsGraph(char c)
    {
        return CharIncludeAnyTypeMask(c, kGraph);
    }

    /** �ж��Ƿ�Ϊ�ɴ�ӡ�ַ���*/
    static inline bool IsPrint(char c)
    {
        return CharIncludeAnyTypeMask(c, kPrint);
    }

    static inline char ToAscii(char c)
    {
        return c & 0x7F;
    }

    static inline char ToLower(char c)
    {
        return IsUpper(c) ? c + ('a' - 'A') : c;
    }

    static inline char ToUpper(char c)
    {
        return IsLower(c) ? c - ('a' - 'A') : c;
    }

private:
    static int GetCharTypeMask(char c)
    {
        return table[static_cast<unsigned char>(c)];
    }

    static bool CharIncludeAnyTypeMask(char c, int mask)
    {
        return (GetCharTypeMask(c) & mask) != 0;
    }

    static bool CharIncludeAallTypeMask(char c, int mask)
    {
        return (GetCharTypeMask(c) & mask) == mask;
    }

private:
    static const uint16_t table[UCHAR_MAX + 1];
};

} // namespace toft

#endif // TOFT_ENCODING_ASCII_H

// Copyright 2011, The Toft Authors.
// All rights reserved.
//
// Author: CHEN Feng <chen3feng@gmail.com>

#ifndef TOFT_ENCODING_PERCENT_H
#define TOFT_ENCODING_PERCENT_H

#include <ctype.h>
#include <stdint.h>
#include <string>
#include "toft/base/string/string_piece.h"

namespace toft {

/// @brief percent encoding, majorly for url
/// @see http://en.wikipedia.org/wiki/Percent-encoding
struct PercentEncoding {
public:
    // Same as escape in javascript

    /// @brief ����׷������� output
    static void EncodeAppend(const StringPiece& input, std::string* output);

    /// @brief ��������� output
    static void EncodeTo(const StringPiece& input, std::string* output);

    /// @brief ���������滻ԭ��������
    static void Encode(std::string *str);

    /// @brief ���ر����Ľ��
    static std::string Encode(const StringPiece& input);

    // Same as encodeURI in javascript

    /// @brief ����׷������� output
    static void EncodeUriAppend(const StringPiece& input, std::string* output);

    /// @brief ��������� output
    static void EncodeUriTo(const StringPiece& input, std::string* output);

    /// @brief ���������滻ԭ��������
    static void EncodeUri(std::string *str);

    /// @brief ���ر����Ľ��
    static std::string EncodeUri(const StringPiece& input);

    // Same as encodeURIComponent in javascript

    /// @brief ����׷������� output
    static void EncodeUriComponentAppend(const StringPiece& input, std::string* output);

    /// @brief ��������� output
    static void EncodeUriComponentTo(const StringPiece& input, std::string* output);

    /// @brief ���������滻ԭ��������
    static void EncodeUriComponent(std::string *str);

    /// @brief ���ر����Ľ��
    static std::string EncodeUriComponent(const StringPiece& input);


    /// @brief �����׷�ӷ�ʽ����� output ��
    static bool DecodeAppend(const StringPiece& input, std::string* output);

    /// @brief ���������� output ��
    /// @return �Ƿ�ɹ�
    static bool DecodeTo(const StringPiece& input, std::string* output);

    /// @brief ���������滻ԭ��������
    static bool Decode(std::string* str);
};

} // namespace toft

#endif // TOFT_ENCODING_PERCENT_H

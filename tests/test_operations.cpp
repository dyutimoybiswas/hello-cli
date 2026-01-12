// MIT License
//
// Copyright (c) 2024-2026 Dyutimoy Biswas
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <gtest/gtest.h>
#include <string>
#include "operations.hpp"

namespace operations {

// Casing operations
TEST(CasingTest, LowercaseAllUppercase) {
    Casing casing_op("lowercase", "HELLO");
    EXPECT_EQ(casing_op.Operate(), "hello");
}

TEST(CasingTest, LowercaseAllLowercase) {
    Casing casing_op("lowercase", "hello");
    EXPECT_EQ(casing_op.Operate(), "hello");
}

TEST(CasingTest, LowercaseMixedCase) {
    Casing casing_op("lowercase", "HeLLo");
    EXPECT_EQ(casing_op.Operate(), "hello");
}

TEST(CasingTest, LowercaseWithNumbers) {
    Casing casing_op("lowercase", "Test123");
    EXPECT_EQ(casing_op.Operate(), "test123");
}

TEST(CasingTest, LowercaseWithSymbols) {
    Casing casing_op("lowercase", "Hello, World!");
    EXPECT_EQ(casing_op.Operate(), "hello, world!");
}

TEST(CasingTest, LowercaseEmptyString) {
    Casing casing_op("lowercase", "");
    EXPECT_EQ(casing_op.Operate(), "");
}

TEST(CasingTest, UppercaseAllLowercase) {
    Casing casing_op("uppercase", "hello");
    EXPECT_EQ(casing_op.Operate(), "HELLO");
}

TEST(CasingTest, UppercaseAllUppercase) {
    Casing casing_op("uppercase", "HELLO");
    EXPECT_EQ(casing_op.Operate(), "HELLO");
}

TEST(CasingTest, UppercaseWithNumbers) {
    Casing casing_op("uppercase", "Test123");
    EXPECT_EQ(casing_op.Operate(), "TEST123");
}

TEST(CasingTest, UppercaseWithSymbols) {
    Casing casing_op("uppercase", "Hello, World!");
    EXPECT_EQ(casing_op.Operate(), "HELLO, WORLD!");
}

TEST(CasingTest, UppercaseEmptyString) {
    Casing casing_op("uppercase", "");
    EXPECT_EQ(casing_op.Operate(), "");
}

TEST(CasingTest, TogglecaseAllLowercase) {
    Casing casing_op("togglecase", "hello");
    EXPECT_EQ(casing_op.Operate(), "HELLO");
}

TEST(CasingTest, TogglecaseAllUppercase) {
    Casing casing_op("togglecase", "HELLO");
    EXPECT_EQ(casing_op.Operate(), "hello");
}

TEST(CasingTest, TogglecaseMixedCase) {
    Casing casing_op("togglecase", "HeLLo");
    EXPECT_EQ(casing_op.Operate(), "hEllO");
}

TEST(CasingTest, TogglecaseWithNumbers) {
    Casing casing_op("togglecase", "Test123");
    EXPECT_EQ(casing_op.Operate(), "tEST123");
}

TEST(CasingTest, TogglecaseWithSymbols) {
    Casing casing_op("togglecase", "Hello, World!");
    EXPECT_EQ(casing_op.Operate(), "hELLO, wORLD!");
}

TEST(CasingTest, TogglecaseEmptyString) {
    Casing casing_op("togglecase", "");
    EXPECT_EQ(casing_op.Operate(), "");
}

TEST(CasingTest, SpongeBobCaseBasic) {
    Casing casing_op("spongebobcase", "Spongebob Squarepants");
    EXPECT_EQ(casing_op.Operate(), "spOnGeBOB sqUaRePaNtS");
}

TEST(CasingTest, SpongeBobCaseAllLowercase) {
    Casing casing_op("spongebobcase", "spongebobb");
    EXPECT_EQ(casing_op.Operate(), "SpOnGeBOBB");
}

TEST(CasingTest, SpongeBobCaseAllUppercase) {
    Casing casing_op("spongebobcase", "SPONGEBOBB");
    EXPECT_EQ(casing_op.Operate(), "sPoNgEbobb");
}

TEST(CasingTest, SpongeBobCaseWithAlphanumericAndSymbols) {
    // No effect on non-alphabetic characters
    Casing casing_op("spongebobcase", "8e9L01?3! 2o#l^H");
    EXPECT_EQ(casing_op.Operate(), "8e9L01?3! 2o#l^H");
}

TEST(CasingTest, SpongeBobCaseEmptyString) {
    Casing casing_op("spongebobcase", "");
    EXPECT_EQ(casing_op.Operate(), "");
}

// Pattern operations
TEST(PatternTest, ReverseBasic) {
    Pattern pattern_op("reverse", "hello");
    EXPECT_EQ(pattern_op.Operate(), "olleh");
}

TEST(PatternTest, ReversePalindrome) {
    Pattern pattern_op("reverse", "madam");
    EXPECT_EQ(pattern_op.Operate(), "madam");
}

TEST(PatternTest, ReverseSingleCharacter) {
    Pattern pattern_op("reverse", "a");
    EXPECT_EQ(pattern_op.Operate(), "a");
}

TEST(PatternTest, ReverseWithSpaces) {
    Pattern pattern_op("reverse", "a b c");
    EXPECT_EQ(pattern_op.Operate(), "c b a");
}

TEST(PatternTest, ReverseEmptyString) {
    Pattern pattern_op("reverse", "");
    EXPECT_EQ(pattern_op.Operate(), "");
}

TEST(PatternTest, SpacingValueOne) {
    Pattern pattern_op("spacing", "hello", 1);
    EXPECT_EQ(pattern_op.Operate(), "h e l l o");
}

TEST(PatternTest, SpacingValueTwo) {
    Pattern pattern_op("spacing", "hello", 2);
    EXPECT_EQ(pattern_op.Operate(), "h  e  l  l  o");
}

TEST(PatternTest, SpacingValueZero) {
    Pattern pattern_op("spacing", "hello", 0);
    EXPECT_EQ(pattern_op.Operate(), "hello");
}

TEST(PatternTest, SpacingLargeValue) {
    Pattern pattern_op("spacing", "hi", 5);
    EXPECT_EQ(pattern_op.Operate(), "h     i");
}

TEST(PatternTest, SpacingSingleCharacter) {
    Pattern pattern_op("spacing", "A", 3);
    EXPECT_EQ(pattern_op.Operate(), "A");
}

TEST(PatternTest, SpacingWithSpacesInText) {
    Pattern pattern_op("spacing", "a b", 1);
    EXPECT_EQ(pattern_op.Operate(), "a   b");
}

TEST(PatternTest, WaveValueZero) {
    Pattern pattern_op("wave", "hello", 0);
    EXPECT_EQ(pattern_op.Operate(), "hello");
}

TEST(PatternTest, WaveValueOne) {
    Pattern pattern_op("wave", "hello", 1);
    // Wave creates 2*value+1 = 3 rows, each char at col*2 position
    EXPECT_EQ(pattern_op.Operate(),
              "  e       \n"
              "h   l   o \n"
              "      l   \n");
}

TEST(PatternTest, WaveValueTwo) {
    Pattern pattern_op("wave", "hello", 2);
    // Wave creates 2*value+1 = 5 rows
    EXPECT_EQ(pattern_op.Operate(),
              "    l     \n"
              "  e   l   \n"
              "h       o \n"
              "          \n"
              "          \n");
}

TEST(PatternTest, WaveEmptyString) {
    Pattern pattern_op("wave", "", 2);
    // Empty string with value>0 produces empty rows
    EXPECT_EQ(pattern_op.Operate(), "\n\n\n\n\n");
}

// Cipher operations
TEST(CipherTest, AtbashBasicLowercase) {
    Cipher cipher_op("atbash", "abc");
    EXPECT_EQ(cipher_op.Operate(), "zyx");
}

TEST(CipherTest, AtbashBasicUppercase) {
    Cipher cipher_op("atbash", "ABC");
    EXPECT_EQ(cipher_op.Operate(), "ZYX");
}

TEST(CipherTest, AtbashMixedCase) {
    Cipher cipher_op("atbash", "AbC");
    EXPECT_EQ(cipher_op.Operate(), "ZyX");
}

TEST(CipherTest, AtbashFullAlphabet) {
    Cipher cipher_op("atbash", "abcdefghijklmnopqrstuvwxyz");
    EXPECT_EQ(cipher_op.Operate(), "zyxwvutsrqponmlkjihgfedcba");
}

TEST(CipherTest, AtbashSelfInverse) {
    Cipher first_pass("atbash", "Hello, World!");
    std::string encrypted = first_pass.Operate();
    Cipher second_pass("atbash", encrypted);
    EXPECT_EQ(second_pass.Operate(), "Hello, World!");
}

TEST(CipherTest, AtbashWithNumbers) {
    Cipher cipher_op("atbash", "a1b2c3");
    EXPECT_EQ(cipher_op.Operate(), "z1y2x3");
}

TEST(CipherTest, AtbashWithSymbols) {
    Cipher cipher_op("atbash", "a@b!");
    EXPECT_EQ(cipher_op.Operate(), "z@y!");
}

TEST(CipherTest, AtbashEmptyString) {
    Cipher cipher_op("atbash", "");
    EXPECT_EQ(cipher_op.Operate(), "");
}

TEST(CipherTest, CaesarShiftOne) {
    Cipher cipher_op("caesar", "abc", 1);
    EXPECT_EQ(cipher_op.Operate(), "bcd");
}

TEST(CipherTest, CaesarShiftThree) {
    Cipher cipher_op("caesar", "abc", 3);
    EXPECT_EQ(cipher_op.Operate(), "def");
}

TEST(CipherTest, CaesarWrapAround) {
    Cipher cipher_op("caesar", "xyz", 3);
    EXPECT_EQ(cipher_op.Operate(), "abc");
}

TEST(CipherTest, CaesarShiftZero) {
    Cipher cipher_op("caesar", "abc", 0);
    EXPECT_EQ(cipher_op.Operate(), "abc");
}

TEST(CipherTest, CaesarShift26) {
    // Full rotation returns original
    Cipher cipher_op("caesar", "abc", 26);
    EXPECT_EQ(cipher_op.Operate(), "abc");
}

TEST(CipherTest, CaesarPreservesCase) {
    Cipher cipher_op("caesar", "AbC", 1);
    EXPECT_EQ(cipher_op.Operate(), "BcD");
}

TEST(CipherTest, CaesarWithNumbers) {
    Cipher cipher_op("caesar", "a1b2", 1);
    EXPECT_EQ(cipher_op.Operate(), "b1c2");
}

TEST(CipherTest, CaesarWithSymbols) {
    Cipher cipher_op("caesar", "a@b!", 1);
    EXPECT_EQ(cipher_op.Operate(), "b@c!");
}

TEST(CipherTest, CaesarEmptyString) {
    Cipher cipher_op("caesar", "", 3);
    EXPECT_EQ(cipher_op.Operate(), "");
}

TEST(CipherTest, CaesarLargeShift) {
    Cipher cipher_op("caesar", "abc", 100);
    EXPECT_EQ(cipher_op.Operate(), "wxy");
}

}   // namespace operations
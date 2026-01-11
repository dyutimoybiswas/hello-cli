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
#include "inputhandler.hpp"

namespace inputhandler {

// Test fixture to suppress stdout during tests
class InputHandlerTest : public ::testing::Test {
 protected:
    void SetUp() override {
        testing::internal::CaptureStdout();
    }
    void TearDown() override {
        testing::internal::GetCapturedStdout();
    }
};

// Valid combinations
// Basic flags
TEST_F(InputHandlerTest, NoArguments) {
    const char* argv[] = {"hello-cli"};
    InputHandler handler(1, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, VersionShort) {
    const char* argv[] = {"hello-cli", "-v"};
    InputHandler handler(2, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, VersionLong) {
    const char* argv[] = {"hello-cli", "--version"};
    InputHandler handler(2, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, HelpShort) {
    const char* argv[] = {"hello-cli", "-h"};
    InputHandler handler(2, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, HelpLong) {
    const char* argv[] = {"hello-cli", "--help"};
    InputHandler handler(2, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

// Casing operations
TEST_F(InputHandlerTest, LowercaseShortWithoutText) {
    const char* argv[] = {"hello-cli", "-c", "lowercase"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}
    
TEST_F(InputHandlerTest, LowercaseLongWithoutText) {
    const char* argv[] = {"hello-cli", "--casing", "lowercase"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, LowercaseShortWithTextShort) {
    const char* argv[] = {"hello-cli", "-c", "lowercase", "-t", "TEST"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}
    
TEST_F(InputHandlerTest, LowercaseLongWithTextShort) {
    const char* argv[] = {"hello-cli", "--casing", "lowercase",
                          "-t", "TEST"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, LowercaseShortWithTextLong) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "--text", "TEST"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, LowercaseLongWithTextLong) {
    const char* argv[] = {"hello-cli", "--casing", "lowercase",
                          "--text", "TEST"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, UppercaseWithoutText) {
    const char* argv[] = {"hello-cli", "-c", "uppercase"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, UppercaseWithText) {
    const char* argv[] = {"hello-cli", "-c", "uppercase",
                          "-t", "test"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, TogglecaseWithoutText) {
    const char* argv[] = {"hello-cli", "-c", "togglecase"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, TogglecaseWithText) {
    const char* argv[] = {"hello-cli", "-c", "togglecase", "-t", "Test"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SpongebobcaseWithoutText) {
    const char* argv[] = {"hello-cli", "-c", "spongebobcase"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SpongebobcaseWithText) {
    const char* argv[] = {"hello-cli", "-c", "spongebobcase", "-t", "tEST"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CasingShortWithHelpShort) {
    const char* argv[] = {"hello-cli", "-c", "-h"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CasingShortWithHelpLong) {
    const char* argv[] = {"hello-cli", "-c", "--help"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CasingLongWithHelpShort) {
    const char* argv[] = {"hello-cli", "--casing", "-h"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CasingLongWithHelpLong) {
    const char* argv[] = {"hello-cli", "--casing", "--help"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

// Pattern operations
TEST_F(InputHandlerTest, ReversePatternShortWithoutText) {
    const char* argv[] = {"hello-cli", "-p", "reverse"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, ReversePatternLongWithoutText) {
    const char* argv[] = {"hello-cli", "--pattern", "reverse"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, ReversePatternShortWithTextShort) {
    const char* argv[] = {"hello-cli", "-p", "reverse", "-t", "abracadabra"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, ReversePatternLongWithTextShort) {
    const char* argv[] = {"hello-cli", "--pattern", "reverse",
                          "-t", "abracadabra"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, ReversePatternShortWithTextLong) {
    const char* argv[] = {"hello-cli", "-p", "reverse",
                          "--text", "abracadabra"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, ReversePatternLongWithTextLong) {
    const char* argv[] = {"hello-cli", "--pattern", "reverse",
                          "--text", "abracadabra"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SpacingPatternWithoutTextAndValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SpacingPatternWithoutTextButWithValueShort) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "4"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SpacingPatternWithoutTextButWithValueLong) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "--pattern-value", "4"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SpacingPatternWithTextButWithoutValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-t", "astronaut"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SpacingPatternWithTextAndValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "3", "-t", "astronaut"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, WavePatternWithoutTextAndValue) {
    const char* argv[] = {"hello-cli", "-p", "wave"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, WavePatternWithoutTextButWithValue) {
    const char* argv[] = {"hello-cli", "-p", "wave",
                          "-pv", "2"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, WavePatternWithTextButWithoutValue) {
    const char* argv[] = {"hello-cli", "-p", "wave",
                          "-t", "swimming"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, WavePatternWithTextAndValue) {
    const char* argv[] = {"hello-cli", "-p", "wave",
                          "-pv", "2", "-t", "swimming"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternShortWithHelpShort) {
    const char* argv[] = {"hello-cli", "-p", "-h"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternShortWithHelpLong) {
    const char* argv[] = {"hello-cli", "-p", "--help"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternLongWithHelpShort) {
    const char* argv[] = {"hello-cli", "--pattern", "-h"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternLongWithHelpLong) {
    const char* argv[] = {"hello-cli", "--pattern", "--help"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternValueShortWithHelpShort) {
    const char* argv[] = {"hello-cli", "-p", "spacing", "-pv", "-h"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternValueShortWithHelpLong) {
    const char* argv[] = {"hello-cli", "-p", "spacing", "-pv", "--help"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternValueLongWithHelpShort) {
    const char* argv[] = {"hello-cli", "--pattern", "spacing",
                          "--pattern-value", "-h"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternValueLongWithHelpLong) {
    const char* argv[] = {"hello-cli", "--pattern", "spacing",
                          "--pattern-value", "--help"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

// Cipher operations
TEST_F(InputHandlerTest, AtbashCipherWithoutTextAndValue) {
    const char* argv[] = {"hello-cli", "-C", "atbash"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AtbashCipherLongWithoutText) {
    const char* argv[] = {"hello-cli", "--cipher", "atbash"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AtbashCipherLongWithText) {
    const char* argv[] = {"hello-cli", "--cipher", "atbash",
                          "-t", "Howdy-doo!"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AtbashCipherWithoutTextButWithValueShort) {
    const char* argv[] = {"hello-cli", "-C", "atbash",
                          "-Cv", "4"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AtbashCipherWithoutTextButWithValueLong) {
    const char* argv[] = {"hello-cli", "-C", "atbash",
                          "--cipher-value", "4"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AtbashCipherWithTextAndWithoutValue) {
    const char* argv[] = {"hello-cli", "-C", "atbash",
                          "-t", "Howdy-doo!"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AtbashCipherWithTextAndValue) {
    const char* argv[] = {"hello-cli", "-C", "atbash",
                          "-Cv", "5", "-t", "Howdy-doo!"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CaesarCipherWithoutTextAndValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CaesarCipherLongWithoutText) {
    const char* argv[] = {"hello-cli", "--cipher", "caesar"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CaesarCipherLongWithText) {
    const char* argv[] = {"hello-cli", "--cipher", "caesar",
                          "-t", "Et tu, Brute?"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CaesarCipherWithoutTextButWithValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "2"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CaesarCipherWithTextButWithoutValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-t", "Et tu, Brute?"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CaesarCipherWithTextAndValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "2", "-t", "Et tu, Brute?"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherShortWithHelpShort) {
    const char* argv[] = {"hello-cli", "-C", "-h"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherShortWithHelpLong) {
    const char* argv[] = {"hello-cli", "-C", "--help"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherLongWithHelpShort) {
    const char* argv[] = {"hello-cli", "--cipher", "-h"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherLongWithHelpLong) {
    const char* argv[] = {"hello-cli", "--cipher", "--help"};
    InputHandler handler(3, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherValueShortWithHelpShort) {
    const char* argv[] = {"hello-cli", "-C", "caesar", "-Cv", "-h"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherValueShortWithHelpLong) {
    const char* argv[] = {"hello-cli", "-C", "caesar", "-Cv", "--help"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherValueLongWithHelpShort) {
    const char* argv[] = {"hello-cli", "--cipher", "caesar",
                          "--cipher-value", "-h"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CipherValueLongWithHelpLong) {
    const char* argv[] = {"hello-cli", "--cipher", "caesar",
                          "--cipher-value", "--help"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

// Combined operations
TEST_F(InputHandlerTest, CasingAndPatternCombined) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-p", "reverse", "-t", "CASING AND PATTERN"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, CasingAndCipherCombined) {
    const char* argv[] = {"hello-cli", "-c", "uppercase",
                          "-C", "caesar", "-t", "casing and cipher"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, PatternAndCipherCombined) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-C", "atbash", "-t", "Pattern and Cipher"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AllOperationsCombined) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-p", "reverse", "-C", "caesar",
                          "-t", "AlL oPeRaTiOnS"};
    InputHandler handler(9, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AllOperationsCombinedWithValues) {
    const char* argv[] = {"hello-cli", "-c", "uppercase",
                          "-p", "spacing", "-pv", "2",
                          "-C", "caesar", "-Cv", "3",
                          "-t", "ALl oPeRaTiOns"};
    InputHandler handler(13, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}
    
TEST_F(InputHandlerTest, OperationsInDifferentOrder) {
    const char* argv[] = {"hello-cli", "-C", "atbash",
                          "-p", "wave", "-c", "togglecase",
                          "-t", "Any OrDeR"};
    InputHandler handler(9, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, MultipleWordsAsText) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-t", "word1", "word2", "word3"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, MixedFlagStyles) {
    const char* argv[] = {"hello-cli", "--casing", "lowercase",
                          "-p", "reverse", "--text", "hello"};
    InputHandler handler(7, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, TextHelpShort) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-t", "-h"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, TextHelpLong) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-t", "--help"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

// Invalid inputs
// Invalid flags
TEST_F(InputHandlerTest, InvalidOperation) {
    const char* argv[] = {"hello-cli", "--invalid"};
    InputHandler handler(2, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, TextBeforeOperation) {
    const char* argv[] = {"hello-cli", "-t", "hello"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, MissingValueForCasingOperation) {
    const char* argv[] = {"hello-cli", "-c"};
    InputHandler handler(2, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, RepeatedCasingOperation) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-c", "uppercase"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, InvalidCasingValue) {
    const char* argv[] = {"hello-cli", "-c", "invalidcase"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, EmptyTextForCasingOperation) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-t"};
    InputHandler handler(4, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

// Invalid pattern inputs
TEST_F(InputHandlerTest, MissingValueForPatternOperation) {
    const char* argv[] = {"hello-cli", "-p"};
    InputHandler handler(2, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, RepeatedPatternOperation) {
    const char* argv[] = {"hello-cli", "-p", "reverse",
                          "-p", "spacing"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, InvalidPatternValue) {
    const char* argv[] = {"hello-cli", "-p", "invalidpattern"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, EmptyTextForPatternOperation) {
    const char* argv[] = {"hello-cli", "-p", "reverse",
                          "-t"};
    InputHandler handler(4, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, PatternValueWithoutPattern) {
    const char* argv[] = {"hello-cli", "-pv", "3"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, MissingPatternValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv"};
    InputHandler handler(4, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, RepeatedPatternValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "2", "-pv", "4"};
    InputHandler handler(7, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, VeryLargePatternValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "99999999999999999999"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

// Invalid cipher inputs
TEST_F(InputHandlerTest, MissingValueForCipherOperation) {
    const char* argv[] = {"hello-cli", "-C"};
    InputHandler handler(2, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, RepeatedCipherOperation) {
    const char* argv[] = {"hello-cli", "-C", "atbash",
                          "-C", "caesar"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, InvalidCipherOperation) {
    const char* argv[] = {"hello-cli", "-C", "invalidcipher"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, EmptyTextForCipherOperation) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-t"};
    InputHandler handler(4, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, CipherValueWithoutCipher) {
    const char* argv[] = {"hello-cli", "-Cv", "3"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, MissingCipherValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv"};
    InputHandler handler(4, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, RepeatedCipherValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "2", "-Cv", "4"};
    InputHandler handler(7, argv);
    EXPECT_THROW(handler.ProcessInput(), std::logic_error);
}

TEST_F(InputHandlerTest, VeryLargeCipherValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "99999999999999999999"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

// Special inputs - edge cases
TEST_F(InputHandlerTest, NumericCasingOperation) {
    const char* argv[] = {"hello-cli", "-c", "123"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, SpecialCharacterCasingOperation) {
    const char* argv[] = {"hello-cli", "-c", "@!#$$%"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, AlphanumericCasingOperation) {
    const char* argv[] = {"hello-cli", "-c", "c1aSe"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, NumericPatternOperation) {
    const char* argv[] = {"hello-cli", "-p", "123"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, SpecialCharacterPatternOperation) {
    const char* argv[] = {"hello-cli", "-p", "@!#$$%"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, AlphanumericPatternOperation) {
    const char* argv[] = {"hello-cli", "-p", "8att3rn"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, AlphabeticPatternValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "abc"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, SpecialCharacterPatternValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "@#$$%"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, AlphanumericPatternValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "4b2"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, NegativePatternValue) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-pv", "-3"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, AlphabeticCipherValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "abc"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, SpecialCharacterCipherValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "@#$$%"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, AlphanumericCipherValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "4b2"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, NegativeCipherValue) {
    const char* argv[] = {"hello-cli", "-C", "caesar",
                          "-Cv", "-3"};
    InputHandler handler(5, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, NumericCipherOperation) {
    const char* argv[] = {"hello-cli", "-C", "123"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, SpecialCharacterCipherOperation) {
    const char* argv[] = {"hello-cli", "-C", "@!#$$%"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

TEST_F(InputHandlerTest, AlphanumericCipherOperation) {
    const char* argv[] = {"hello-cli", "-C", "8aTb4h"};
    InputHandler handler(3, argv);
    EXPECT_THROW(handler.ProcessInput(), std::invalid_argument);
}

// Text edge cases
TEST_F(InputHandlerTest, EmptyText) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-t", ""};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, SingleCharacterText) {
    const char* argv[] = {"hello-cli", "-c", "uppercase",
                          "-t", "a"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, WhitespaceOnlyText) {
    const char* argv[] = {"hello-cli", "-p", "spacing",
                          "-t", "   "};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, QuotesInText) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-t", "He said \"hello\""};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, NewlinesAndTabsText) {
    const char* argv[] = {"hello-cli", "-p", "reverse",
                          "-t", "line1\nline2\ttabbed"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, AlphanumericAndSymbolsText) {
    const char* argv[] = {"hello-cli", "-c", "togglecase",
                          "-t", "?59U1s!e3&4r!"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, NumericOnlyText) {
    const char* argv[] = {"hello-cli", "-c", "uppercase",
                          "-t", "12345"};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, TextWithTrailingSpaces) {
    const char* argv[] = {"hello-cli", "-c", "lowercase",
                          "-t", "hello   "};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

TEST_F(InputHandlerTest, LargeText) {
    std::string large_text(10000, 'a');
    const char* argv[] = {"hello-cli", "-c", "uppercase",
                          "-t", large_text.c_str()};
    InputHandler handler(5, argv);
    EXPECT_NO_THROW(handler.ProcessInput());
}

}   // namespace inputhandler
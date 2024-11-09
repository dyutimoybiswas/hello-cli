#ifndef INC_OPERATIONS_HPP_
#define INC_OPERATIONS_HPP_

#include <string>
#include <algorithm>

namespace operations {

class Operation {
 public:
    Operation(const std::string& op, const std::string& t):
    option(op), text(t) {}
    virtual std::string& getOption() final { return option; }
    virtual std::string& getText() final { return text; }
    virtual std::string& operate() noexcept = 0;
    virtual ~Operation() = default;

 protected:
    std::string result;

 private:
    std::string option;
    std::string text;
};

class Casing: public Operation {
 public:
    Casing(const std::string& op, const std::string& t): Operation(op, t) {}
    std::string& operate() noexcept override;

 private:
    std::string& lowercase();
    std::string& uppercase();
    std::string& togglecase();
    std::string& spongebobcase();
};

class Pattern: public Operation {
 public:
    Pattern(const std::string& op, size_t val, const std::string& t):
    Operation(op, t), value(val) {}
    std::string& operate() noexcept override;

 private:
    std::string& reverse();
    std::string& spacing();
    std::string& wave();
    size_t value;
};

class Cipher: public Operation {
 public:
    Cipher(const std::string& op, size_t val, const std::string& t):
    Operation(op, t), value(val) {}
    std::string& operate() noexcept override;

 private:
    std::string& atbash();
    std::string& caesar();
    const std::string ALPHABETS {"abcdefghijklmnopqrstuvwxyz"};
    size_t value;
};
}   // namespace operations

#endif  // INC_OPERATIONS_HPP_

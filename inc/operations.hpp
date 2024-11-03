#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <string>

namespace operations {

    class Operation {

        public:

            Operation(const std::string& op, const std::string& t): option(op), text(t) {}
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

            Casing(const std::string& op, const std::string& t = "Hello, CLI"): Operation(op, t) {}
            std::string& operate() noexcept override;

        private:

            std::string& lowercase();
            std::string& uppercase();
            std::string& togglecase();
            std::string& spongebobcase();
    };

    class Pattern: public Operation {

        public:

            Pattern(const std::string& op, size_t val, const std::string& t = "Hello, CLI"): Operation(op, t), value(val) {}
            std::string& operate() noexcept override;

        private:

            size_t value;
    };

    class Cipher: public Operation {

        public:

            Cipher(const std::string& op, const std::string& t = "Hello, CLI"): Operation(op, t) {}
            std::string& operate() noexcept override;
    };
}

#endif

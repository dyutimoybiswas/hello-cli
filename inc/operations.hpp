#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <string>

namespace operations {

    class Operation {

        public:

            Operation(const std::string op): option(op) {}
            virtual std::string& getOption() final { return option; }
            virtual std::string& operate() = 0;

        protected:

            std::string result;

        private:

            std::string option;
    };

    class Casing: public Operation {

        public:

            Casing(const std::string op): Operation(op) {}
            std::string& operate() override;
    };

    class Pattern: public Operation {

        public:

            Pattern(const std::string op, size_t val): Operation(op), value(val) {}
            std::string& operate() override;

        private:

            size_t value;
    };

    class Cipher: public Operation {

        public:

            Cipher(const std::string op): Operation(op) {}
            std::string& operate() override;
    };
}

#endif

# Testing

## Information
- This directory contains unit tests covering all use cases of `hello-cli`
- These tests use **Gtest v.1.14.0**
- Use [run_tests.sh](run_tests.sh) to generate the test executable and run it


## CI/CD
This project uses [GitHub Actions](https://github.com/features/actions) to automatically build platform-specific test executables (Linux, Windows, and macOS) whenever a new pull request is raised.

## TODO
- use coverage tool, ensure 100% coverage
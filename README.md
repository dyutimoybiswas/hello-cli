# hello-cli

A demonstrative command line application to perform simple operations on text, coded entirely in C++. 

Provided a string as input with the help of `--text` or `-t` [flag](#text), the application formats the input string subject to one or more of [operations](#operations) specified by the user and outputs the result after padding blank lines to the top and bottom of the formatted string. [Operations](#operations) can be specified in any order and any number of times, without duplicates. Examples on how to use can be found in [samples](samples/).



## Flags
### Operations
* `--casing` / `-c` : Change the casing of input [text](#text) to one of the following values - `lowercase`, `uppercase`, `togglecase` or [`spongebobcase`](https://knowyourmeme.com/memes/mocking-spongebob).

* `--pattern` / `-p` : Format the input [text](#text) based on one of the following values - `reverse`, `spacing` (characters are spaced apart) or `wave` (characters are arranged in a triangular wave).

* `--pattern-value` / `-pv` (optional): Specify the value as a non-negative integer, corresponding to number of spaces (`spacing`) to separate the characters by, or the amplitude of the triangular wave (`wave`). Assumes a default value of `1` when not provided. Has no effect when used with `reverse`.

* `--cipher` / `-C` : Encrypt the input [text](#text) based on one of the following values - [`atbash`](https://en.wikipedia.org/wiki/Atbash) or [`caesar`](https://en.wikipedia.org/wiki/Caesar_cipher).

* `--cipher-value` / `-Cv` (optional): Specify the value as a non-negative integer, corresponding to alphabet shift (`caesar`). Assumes a default value of `3` when not provided. Has no effect when used with `atbash`.
* _Note:_ text is operated based on alphabetical ordering of operation flags.
### Text
* `--text` / `-t` : Specify the string to operate on. Should be specified only at the end.
### Help
* `--help` / `-h` : Display a custom help text subject to any of the [operation](#operations) flags, or a general guide about the application behavior when no flag is specified.
### Versioning
* `--version` / `-v` : Display the version of the application being run.



## Special behaviors
* When run without any [arguments](#flags), it behaves the same as: `echo Hello, CLI!` , subject to padding blank lines.
* When operation(s) are specified without specifying a [text](#text), the application assumes the default value of [text](#text) as `Hello, CLI!`.



## Project information
### Source code
Source code can be found in `inc` and `src` directories.
### Requirements
This application requires [cmake](https://cmake.org/) >=3.10 and C++14 or above to run.
### Building
To build, simply execute the [build.sh](build.sh) script. It auto-detects the host OS, compiles and generates the executable accordingly
### Running
Navigate to the build directory based on your host OS (`build-linux` for Linux, `build-windows` for Windows & `build-macos` for macOS) created after building, and run the `hello-cli` executable.



## CI/CD
This project uses [GitHub Actions](https://github.com/features/actions) to automatically build platform-specific executables (Linux, Windows, and macOS) whenever a new release is published.

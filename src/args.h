//
// Copyright 2026 Amr Saqr
//

#ifndef ARGS_H_
#define ARGS_H_

#include <string>

using std::string_view;

class Args {
 public:
  Args() = default;

  /**
   * Reads the parameters passed to the program.
   * Expects 3 arguments:
   * 1- '-e' or '-d' for encoding or decoding respectively
   * 2- Input file path
   * 3- Output file path
   * @param argc The arguments count (not including the program name)
   * @param argv The arguments passed to the program
   * @return true if the arguments count and contents are valid, false otherwise
   */
  bool Read(int argc, const char* const* argv);

  [[nodiscard]] bool IsEncoding() const;
  [[nodiscard]] string_view GetInputFile() const;
  [[nodiscard]] string_view GetOutputFile() const;

 private:
  bool is_encoding_{false};
  string_view input_file_;
  string_view output_file_;
};

#endif  // ARGS_H_

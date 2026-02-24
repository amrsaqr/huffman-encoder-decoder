//
// Copyright 2026 Amr Saqr
//

#include "args.h"
#include <string>

using std::string_view;

bool Args::Read(int argc, const char* const* argv) {
  if (argc < 3) {
    return false;
  }

  string_view action = argv[0];
  if (action == "-e") {
    is_encoding_ = true;
  } else if (action == "-d") {
    is_encoding_ = false;
  } else {
    return false;
  }

  input_file_ = argv[1];
  output_file_ = argv[2];
  return true;
}

bool Args::IsEncoding() const {
  return is_encoding_;
}

string_view Args::GetInputFile() const {
  return input_file_;
}

string_view Args::GetOutputFile() const {
  return output_file_;
}

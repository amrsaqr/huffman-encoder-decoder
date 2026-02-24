//
// Copyright 2026 Amr Saqr
//

#include <gtest/gtest.h>
#include "args.h"

TEST(ArgsTest, TestsZeroArgs) {
  Args args;
  bool valid = args.Read(0, {});
  ASSERT_EQ(valid, false);
}

TEST(ArgsTest, TestsOneArg) {
  Args args;
  const char* argv[] = {"-e"};
  bool valid = args.Read(1, argv);
  ASSERT_EQ(valid, false);
}

TEST(ArgsTest, TestsTwoArgs) {
  Args args;
  const char* argv[] = {"-e", "input.txt"};
  bool valid = args.Read(2, argv);
  ASSERT_EQ(valid, false);
}

TEST(ArgsTest, TestsInvalidThreeArgs) {
  Args args;
  const char* argv[] = {"-x", "input.txt", "output.txt"};
  bool valid = args.Read(3, argv);
  ASSERT_EQ(valid, false);
}

TEST(ArgsTest, TestsValidEncodingArgs) {
  Args args;
  const char* argv[] = {"-e", "input.txt", "output.txt"};
  bool valid = args.Read(3, argv);
  ASSERT_EQ(valid, true);
}

TEST(ArgsTest, TestsValidDecodingArgs) {
  Args args;
  const char* argv[] = {"-d", "input.txt", "output.txt"};
  bool valid = args.Read(3, argv);
  ASSERT_EQ(valid, true);
}

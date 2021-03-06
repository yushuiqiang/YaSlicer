#pragma once

#include <stdexcept>

#define NOMINMAX
#include <windows.h>

#define STRINGIZE_IMPL(x) #x
#define STRINGIZE(x) STRINGIZE_IMPL(x)

#define CONCAT_IMPL(x, y) x ## y
#define CONCAT(x, y) CONCAT_IMPL(x, y)

#define FILE_LINE CONCAT(__FILE__": ", STRINGIZE(__LINE__))

#define ASSERT(x) if(!(x)) { MessageBoxA(nullptr, #x, "Assertion failed", MB_ICONERROR | MB_OK); }

#define CHECK(x) if (!(x)) { throw std::runtime_error("Check failed at "FILE_LINE); }
#define CHECK_EX(x, msg) if (!(x)) { throw std::runtime_error(msg" at "FILE_LINE); }

#define EXPECT(x) if (!(x)) { ASSERT(x); throw std::logic_error("Expectation failed at "FILE_LINE); }
#define EXPECT_EX(x, msg) if (!(x)) { ASSERT(x); throw std::logic_error(msg" at "FILE_LINE); }

#define REQUIRE(x) ASSERT(x)
#define INVARIANT(x) ASSERT(x)

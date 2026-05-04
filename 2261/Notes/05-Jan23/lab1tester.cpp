// main.cpp - Tester for Name (GNU g++17 / Linux)
// ~fardad.soleimanloo/submit 345/lab1<ENTER>

#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

#include "Name.h"

using std::cout;
using std::endl;

namespace test {

   struct Results {
      int passed;
      int failed;

      Results() : passed(0), failed(0) {}

      void report(const std::string& title, bool ok, const std::string& details = std::string()) {
         if (ok) {
            ++passed;
            cout << "[PASS] " << title << '\n';
         }
         else {
            ++failed;
            cout << "[FAIL] " << title;
            if (!details.empty()) cout << " -> " << details;
            cout << '\n';
         }
      }

      void summary() const {
         cout << "\n----------------------------------------\n";
         cout << "Passed: " << passed << "\nFailed: " << failed << '\n';
         cout << (failed == 0 ? "ALL TESTS PASSED\n" : "Some tests FAILED\n");
         cout << "----------------------------------------\n";
      }
   };

   std::string toStr(const seneca::Name& n) {
      std::ostringstream oss;
      oss << n;
      return oss.str();
   }

   void expectEq(Results& r, const std::string& title,
      const std::string& actual, const std::string& expected) {
      if (actual == expected) {
         r.report(title, true);
      }
      else {
         r.report(title, false, "Expected: [" + expected + "], Got: [" + actual + "]");
      }
   }

   void expectTrue(Results& r, const std::string& title, bool condition, const std::string& whyFail = std::string()) {
      r.report(title, condition, whyFail);
   }

} // namespace test

int main() {
   test::Results R;

   cout << "Rule of five tester\n";
   cout << "========================================\n\n";

   // Compile-time (type trait) checks
   {
      test::expectTrue(R, "Type trait: Name is NOT default constructible",
         !std::is_default_constructible<seneca::Name>::value);

      test::expectTrue(R, "Type trait: Name is copy constructible",
         std::is_copy_constructible<seneca::Name>::value);

      test::expectTrue(R, "Type trait: Name is copy assignable",
         std::is_copy_assignable<seneca::Name>::value);

      test::expectTrue(R, "Type trait: Name is move constructible",
         std::is_move_constructible<seneca::Name>::value);

      test::expectTrue(R, "Type trait: Name is move assignable",
         std::is_move_assignable<seneca::Name>::value);
   }

   cout << "\n--- Runtime behaviour tests ---\n\n";

   // 1) Construction + ostream insertion
   {
      seneca::Name n("Fardad");
      test::expectEq(R, "Construct with a valid name and stream it",
         test::toStr(n), "Fardad");
   }

   // 2) Empty / null input policy (based on the Name solution: prints empty output)
   {
      seneca::Name a("");
      test::expectEq(R, "Construct with empty string -> prints empty output",
         test::toStr(a), "");

      seneca::Name b(nullptr);
      test::expectEq(R, "Construct with nullptr -> prints empty output",
         test::toStr(b), "");
   }

   // 3) Copy constructor deep copy behaviour (indirect test)
   {
      seneca::Name original("Alice");
      seneca::Name copy(original);

      test::expectEq(R, "Copy constructor copies content",
         test::toStr(copy), "Alice");

      // Change original; copy should remain unchanged if deep copy
      original = seneca::Name("Changed");
      test::expectEq(R, "Deep copy check: copy unaffected when original changes",
         test::toStr(copy), "Alice");
      test::expectEq(R, "Original updated after assignment",
         test::toStr(original), "Changed");
   }

   // 4) Copy assignment + self-assignment safety
   {
      seneca::Name a("First");
      seneca::Name b("Second");

      b = a;
      test::expectEq(R, "Copy assignment overwrites destination",
         test::toStr(b), "First");

      // Self-assignment should keep object valid and unchanged
      std::string before = test::toStr(b);
      b = b;
      test::expectEq(R, "Copy self-assignment keeps value unchanged",
         test::toStr(b), before);
   }

   // 5) Move constructor behaviour
   {
      seneca::Name src("MoveMe");
      seneca::Name moved(std::move(src));

      test::expectEq(R, "Move constructor transfers value to new object",
         test::toStr(moved), "MoveMe");

      // After move, source should be safe/empty
      test::expectEq(R, "Moved-from object is empty/safe",
         test::toStr(src), "");
   }

   // 6) Move assignment behaviour (including overwriting existing content)
   {
      seneca::Name a("AAA");
      seneca::Name b("BBB");

      b = std::move(a);
      test::expectEq(R, "Move assignment transfers value",
         test::toStr(b), "AAA");
      test::expectEq(R, "Moved-from object after move assignment is empty/safe",
         test::toStr(a), "");

      // Move assign into an object that already owns memory
      seneca::Name x("X");
      seneca::Name y("Y");
      y = std::move(x);
      test::expectEq(R, "Move assignment overwrites existing content safely",
         test::toStr(y), "X");
      test::expectEq(R, "Moved-from object becomes empty/safe (again)",
         test::toStr(x), "");
   }

   // 7) Mixed operations "stress" check (should not throw/crash)
   {
      try {
         seneca::Name n1("One");
         seneca::Name n2("Two");
         seneca::Name n3("Three");

         n2 = n1;                         // copy assign
         n3 = std::move(n2);              // move assign
         seneca::Name n4(n3);             // copy ctor
         seneca::Name n5(std::move(n3));  // move ctor

         test::expectEq(R, "Stress: n2 after being moved-from is empty/safe",
            test::toStr(n2), "");
         test::expectEq(R, "Stress: n4 (copy) has expected value",
            test::toStr(n4), "One");
         test::expectEq(R, "Stress: n5 (move) has expected value",
            test::toStr(n5), "One");
         test::expectEq(R, "Stress: n3 after move ctor is empty/safe",
            test::toStr(n3), "");
      }
      catch (...) {
         R.report("Stress operations should not throw/crash", false, "Exception thrown");
      }
   }

   R.summary();
   return (R.failed == 0) ? 0 : 1;
}

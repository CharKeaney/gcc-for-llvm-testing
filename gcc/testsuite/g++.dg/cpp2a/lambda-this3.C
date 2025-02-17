// P0806R2
// { dg-do compile }
// { dg-options "-std=c++17" }

struct X {
  int x;
  void foo (int n) {
    auto a1 = [=] { x = n; }; // { dg-bogus "implicit capture" }
    auto a2 = [=, this] { x = n; };
    // { dg-warning "explicit by-copy capture" "" { target c++17_down } .-1 }
    auto a3 = [=, *this]() mutable { x = n; };
    auto a4 = [&] { x = n; };
    auto a5 = [&, this] { x = n; };
    auto a6 = [&, *this]() mutable { x = n; };

    auto a7 = [=] { // { dg-bogus "implicit capture" }
      auto a = [=] { // { dg-bogus "implicit capture" }
	 auto a2 = [=] { x = n; }; // { dg-bogus "implicit capture" }
      };
    };

    auto a8 = [=, this] {
    // { dg-warning "explicit by-copy capture" "" { target c++17_down } .-1 }
      auto a = [=, this] {
    // { dg-warning "explicit by-copy capture" "" { target c++17_down } .-1 }
	 auto a2 = [=, this] { x = n; };
    // { dg-warning "explicit by-copy capture" "" { target c++17_down } .-1 }
      };
    };

    auto a9 = [=, *this]() mutable {
      auto a = [=, *this]() mutable {
	 auto a2 = [=, *this]() mutable { x = n; };
      };
    };

    auto a10 = [&] {
      auto a = [&] {
	 auto a2 = [&] { x = n; };
      };
    };

    auto a11 = [&, this] {
      auto a = [&, this] {
	 auto a2 = [&, this] { x = n; };
      };
    };

    auto a12 = [&, *this]() mutable {
      auto a = [&, *this]() mutable {
	 auto a2 = [&, *this]() mutable { x = n; };
      };
    };
  }
};

#ifndef LOGIC_H
#define LOGIC_H

#include <boost/sml.hpp>
#include "spaghettiCode.h"

namespace sml = boost::sml;
namespace test = spaghettiCode;

namespace spaghettiCode::logic {

 struct event1 {};
 struct event2 {};
 struct event3 {};
 struct event4 {};

 struct Data {
    test::Input i{};
    test::Output o{};
 };

 struct guard {
   bool operator()(Data& d) { return !d.o.z; };
 } guard;

 struct action {
   void operator()(Data& d) { d.o.z = d.i.x + d.i.y; };
 } action;

 struct testing {
  auto operator()() const noexcept {
    using namespace sml;
    return make_transition_table(

      *"idle"_s + event<event1> = "state1"_s
      , "state1"_s + event<event2> [ guard ] / action = "state2"_s
      , "state2"_s + event<event3> [ guard ] = "state1"_s
      , "state2"_s + event<event4> / action = X

    );
  }
 };
} // namespace


#endif // _H


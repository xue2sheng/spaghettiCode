#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE UnitTest

#include <boost/test/unit_test.hpp>

#include <boost/sml.hpp>
#include <cassert> 
#include "spaghettiCode.h"
#include "logic.h"
#include "utils/sml2plantuml.h"

namespace sml = boost::sml;
namespace test = spaghettiCode;

// just logging something ( --log_level=message )

struct GlobalInit {
  GlobalInit() { 
      test::logic::Data data{{},{}};
      dump(sml::sm<test::logic::testing, sml::testing>{data}, "logic.png");
  }
 ~GlobalInit() {}
};
BOOST_GLOBAL_FIXTURE( GlobalInit );

BOOST_AUTO_TEST_CASE( test000 ) {
   BOOST_TEST_MESSAGE( "\ntest000: Basic example" );
   test::Input input{5,3};
   test::Output output{};
   if( test::mess(input, output) ) {
     BOOST_TEST_MESSAGE( output.toStdString() );

     // test the logic
     using namespace sml;
     using namespace test::logic;
     Data data{{5,3}, {}};
     sml::sm<test::logic::testing, sml::testing> sm{data};
     sm.__set_current_states("state2"_s);
     sm.process_event(event3{});
     BOOST_CHECK( sm.is(X) ); 
     BOOST_CHECK( output.z == data.o.z ); 

   } else {
     BOOST_TEST_MESSAGE( output.toStdString() );
     BOOST_CHECK( false ); 
   }
}


#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE UnitTest

#include <boost/test/unit_test.hpp>

#include "spaghettiCode.h"
#include "boost/sml.hpp"
namespace sml = boost::sml;

// just logging something ( --log_level=message )

struct GlobalInit {
  GlobalInit() {}
  ~GlobalInit() {}
};
BOOST_GLOBAL_FIXTURE( GlobalInit );

BOOST_AUTO_TEST_CASE( test000 ) {
   BOOST_TEST_MESSAGE( "\ntest000: Basic example" );
   using namespace spaghettiCode;
   Input input {5,3};
   Output output {};
   if( mess(input, output) ) {
     BOOST_TEST_MESSAGE( output.toStdString() );
     BOOST_CHECK( output.z == (input.x + input.y) ); 
   } else {
     BOOST_TEST_MESSAGE( output.toStdString() );
     BOOST_CHECK( false ); 
   }
}


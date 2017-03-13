/** @file spaghettiCode.h 
 * @brief Basic example.
 *
 */

#ifndef SPAGHETTICODE_H
#define SPAGHETTICODE_H

#include <string>

/// @brief Spaghetti Code Namespace in order to avoid interferencies.
namespace spaghettiCode
{
     /// @brief general input
     struct Input {
        int x {};
        int y {};
     };

     /// @brief general output
     struct Output {
        int error {};
        inline std::string toStdString() const { if(not error) {return "z="+std::to_string(z);} else {return std::string{};} }

        int z {};
     };

     /// @brief typical functionality that grew into a moster after several years of not refactoring.
     /// @param [in] input source data.
     /// @param [out] output results to produce.
     /// @return true if success, false otherwise.
     bool mess(const spaghettiCode::Input& input, spaghettiCode::Output& output);
}


/**
 * @example
 *
 * Some involved and confusing function that became that mess due to the lack of time to refactor.
 *
 * @code
 *     if( mess(input, output) ) {
 *        std::cout << "Success: " << output.toStdString() << std::endl;
 *     } else {
 *        std::cout << "Failed: " << output.error << std::endl;
 *    }
 * @endcode
 *
 */

#endif // _H

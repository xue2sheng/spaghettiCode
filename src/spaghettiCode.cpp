/** @file spaghettiCode.cpp
 * @brief Basic funcionality to show some out of control function.
 *
 */

#include "spaghettiCode.h"
#include "version.h"

bool spaghettiCode::mess(const spaghettiCode::Input& input, spaghettiCode::Output& output)
{
     output.z = input.x + input.y;
     return true;
}

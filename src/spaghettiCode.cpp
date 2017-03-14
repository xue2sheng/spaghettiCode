/** @file spaghettiCode.cpp
 * @brief Basic funcionality to show some out of control function.
 *
 */

#include "spaghettiCode.h"
#include "version.h"

static void superImportantConditionToMaintain1(const spaghettiCode::Input& input) { return; }
static void superImportantConditionToMaintain2(const spaghettiCode::Input& input, const spaghettiCode::Output& output) { return; }

static bool superImportantEventFromUser1(const spaghettiCode::Input& input) { return true; }
static bool superImportantEventFromUser2(const spaghettiCode::Input& input) { return true; }
static bool superImportantEventFromUser3(const spaghettiCode::Input& input) { return true; }
static bool superImportantEventFromUser4(const spaghettiCode::Input& input) { return true; }

static void superImportantDDBBAccess1(const spaghettiCode::Input& input) { return; }
static void superImportantDDBBAccess2(const spaghettiCode::Input& input) { return; }
static void superImportantDDBBAccess3(const spaghettiCode::Input& input) { return; }
static void superImportantDDBBAccess4(const spaghettiCode::Input& input) { return; }

bool spaghettiCode::mess(const spaghettiCode::Input& input, spaghettiCode::Output& output)
{
    if(output.z == 135) { return false; }

    superImportantConditionToMaintain1(input);

    if(input.x > 12 && input.y < 13) { superImportantDDBBAccess1(input); }
    else if(input.y < 23 && superImportantEventFromUser1(input) ) { superImportantDDBBAccess2(input); }
    else if(output.z == 0 && superImportantEventFromUser2(input) ) {
        switch(input.y) {
            case 1: superImportantDDBBAccess3(input); break;
            case 14: superImportantDDBBAccess4(input); break;
            default: superImportantConditionToMaintain1(input);
        }
    } else {
        superImportantDDBBAccess3(input);
        if(superImportantEventFromUser3(input)) { int zzz = input.x + input.y * 2; }
        else if(superImportantEventFromUser4(input)) { int yyy = input.x + input.y * 5; }
        else { int xxx = 235; }
        superImportantDDBBAccess4(input);
    }
        
    superImportantConditionToMaintain2(input, output);

    output.z = input.x + input.y;
    return true;
}

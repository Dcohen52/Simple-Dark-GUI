/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   background_wlabels_png;
    const int            background_wlabels_pngSize = 39998;

    extern const char*   more_small_png;
    const int            more_small_pngSize = 1763;

    extern const char*   backpreset_std_png;
    const int            backpreset_std_pngSize = 221;

    extern const char*   nextpreset_std_png;
    const int            nextpreset_std_pngSize = 207;

    extern const char*   nextpreset_png;
    const int            nextpreset_pngSize = 162;

    extern const char*   backpreset_png;
    const int            backpreset_pngSize = 181;

    extern const char*   background_png;
    const int            background_pngSize = 37713;

    extern const char*   more_png;
    const int            more_pngSize = 309;

    extern const char*   Aaux_ProRegular_Regular_ttf;
    const int            Aaux_ProRegular_Regular_ttfSize = 42144;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 9;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}

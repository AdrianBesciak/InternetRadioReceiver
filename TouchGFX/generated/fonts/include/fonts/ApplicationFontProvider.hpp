/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId SMALLER = 1;
    static const touchgfx::FontId BIGGER = 2;
    static const touchgfx::FontId LARGE = 3;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0; // verdana_20_4bpp
    static const touchgfx::FontId SMALLER = 1; // verdana_16_4bpp
    static const touchgfx::FontId BIGGER = 2;  // verdana_24_4bpp
    static const touchgfx::FontId LARGE = 3;   // verdana_30_4bpp
    static const uint16_t NUMBER_OF_FONTS = 4;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /* flashReader */)
    {
    }
    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

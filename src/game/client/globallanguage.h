/**
 * @file
 *
 * @author OmniBlade
 *
 * @brief Handles font configurations for current language.
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once

#ifndef GLOBALLANGUAGE_H
#define GLOBALLANGUAGE_H

#include "asciistring.h"
#include "ini.h"
#include "subsysteminterface.h"
#include <list>

#ifndef THYME_STANDALONE
#include "hooker.h"
#endif

class FontDesc
{
    friend class GlobalLanguage;

public:
    FontDesc() : m_name("Arial Unicode MS"), m_pointSize(12), m_bold(false) {}
    FontDesc(const char *name, int size = 12, bool bold = false) : m_name(name), m_pointSize(size), m_bold(bold) {}

    const AsciiString &Name() const { return m_name; }
    int Point_Size() const { return m_pointSize; }
    bool Bold() const { return m_bold; }
    void Set_Name(AsciiString name) { m_name = name; }
    void Set_Point_Size(int size) { m_pointSize = size; }
    void Set_Bold(bool bold) { m_bold = bold; }

private:
    AsciiString m_name;
    int m_pointSize;
    bool m_bold;
};

class GlobalLanguage : public SubsystemInterface
{
public:
    GlobalLanguage();
    virtual ~GlobalLanguage() {}

    virtual void Init() override;
    virtual void Reset() override {}
    virtual void Update() override {}

    int Adjust_Font_Size(int size);

    const FontDesc &Tooltip() const { return m_tooltipFont; }

    static void Parse_Language_Defintions(INI *ini);
    static void Parse_Font_Filename(INI *ini, void *formal, void *store, void const *user_data);
    static void Parse_FontDesc(INI *ini, void *formal, void *store, void const *user_data);

private:
    AsciiString m_unicodeFontName;
    AsciiString m_unkAsciiString;
    bool m_useHardWordWrap;
    int m_militaryCaptionSpeed;
    int m_militaryCaptionDelayMs;
    FontDesc m_copyrightFont;
    FontDesc m_messageFont;
    FontDesc m_militaryCaptionTitleFont;
    FontDesc m_militaryCaptionFont;
    FontDesc m_superweaponCountdownNormalFont;
    FontDesc m_superweaponCountdownReadyFont;
    FontDesc m_namedTimerCountdownNormalFont;
    FontDesc m_namedTimerCountdownReadyFont;
    FontDesc m_drawableCaptionFont;
    FontDesc m_defaultWindowFont;
    FontDesc m_defaultDisplayStringFont;
    FontDesc m_tooltipFont;
    FontDesc m_nativeDebugDisplayFont;
    FontDesc m_drawGroupInfoFont;
    FontDesc m_creditsTitleFont;
    FontDesc m_creditsMinorTitleFont;
    FontDesc m_creditsNormalFont;
    float m_resolutionFontAdjustment;
    std::list<AsciiString> m_localFontFiles;

    static FieldParse s_languageParseTable[];
};

#ifndef THYME_STANDALONE
extern GlobalLanguage *&g_theGlobalLanguage;
#else
extern GlobalLanguage *g_theGlobalLanguage;
#endif

#endif // GLOBALLANGUAGE_H

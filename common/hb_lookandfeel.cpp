/**************************************************************************
**                                                                       **
** Copyright(C) 2020 - 2024 Imre Nagy                                    **
** Contact: https://hyperborg.com                                        **
**                                                                       **
** This file is part of HyperBorg.                                       **
**                                                                       **
** This file is based on/inspired on the work of Lukas Spies and his     **
** phenomenal PhotoQt application. His project can be found at           **
** https://photoqt.org                                                   **
**                                                                       **
** HyperBorg is free software : you can redistribute it and /or modify   **
** it under the terms of the GNU General Public License as published by  **
** the Free Software Foundation, either version 2 of the License, or     **
** (at your option) any later version.                                   **
**                                                                       **
** HyperBorg is distributed in the hope that it will be useful,          **
** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
** GNU General Public License for more details.                          **
**                                                                       **
** You should have received a copy of the GNU General Public License     **
** along with HyperBorg. If not, see <http://www.gnu.org/licenses/>.     **
**                                                                       **
**************************************************************************/

#include "hb_lookandfeel.h"
#include <QColor>
#include <QFont>
#include <QtDebug>

HB_LookAndFeel::HB_LookAndFeel()
    : lightness_threshold(96),
    m_fontWeightBold(QFont::Bold),
    m_fontWeightNormal(QFont::Normal)
{
    // Initialize color hexes and names
    colorHexes = { "#222222", "#110505", "#051105", "#050b11", "#110b02", "#dddddd", "#ff8080", "#a4c4a4", "#a4a4ff", "#ffd7c0" };
    colorNames = { "dark gray", "dark red", "dark green", "dark blue", "dark orange", "light gray", "light red", "light green", "light blue", "light orange" };

    calculateFontSizes(11);
    setInterfaceAccentColor(QVariant("#2233ff"));

    connect(&testtimer, &QTimer::timeout, this, &HB_LookAndFeel::testtimer_timeout);
    testtimer.setSingleShot(false);
    testtimer.start(1000);
}

HB_LookAndFeel& HB_LookAndFeel::get()
{
    static HB_LookAndFeel instance;
    return instance;
}

HB_LookAndFeel::~HB_LookAndFeel() {}

QString HB_LookAndFeel::getInterfaceAccentColor()
{
    return m_interfaceAccentColor;
}

void HB_LookAndFeel::setInterfaceAccentColor(QVariant var)
{
    m_interfaceAccentColor = var.toString();
    calculateColors(m_interfaceAccentColor.startsWith("#") ? m_interfaceAccentColor : QColor(m_interfaceAccentColor).name(QColor::HexArgb));
    emitColorsChanged();
}

void HB_LookAndFeel::calculateColors(const QString& name)
{
    QString base = name.startsWith("#") ? name : QColor(name).name(QColor::HexArgb);
    QColor col = QColor::fromString(base);
    QColor colTrans = col;
    colTrans.setAlpha(222);

    m_baseColor = base;
    m_transColor = colTrans.name(QColor::HexArgb);

    colTrans.setAlpha(20);
    m_faintColor = colTrans.name(QColor::HexArgb);

    int val = qMax(col.red(), qMax(col.green(), col.blue()));
    QColor invcol(255 - val, 255 - val, 255 - val);
    m_inverseColor = invcol.name(QColor::HexArgb);
    QColor transinvcol = invcol;
    transinvcol.setAlpha(222);
    m_transInverseColor = transinvcol.name(QColor::HexArgb);

    constexpr int accent = 75;
    constexpr int highlight = 150;
    constexpr int active = 225;

    if (col.lightness() < lightness_threshold) {
        setLightColors(col, colTrans, invcol, accent, highlight, active);
    }
    else {
        setDarkColors(col, colTrans, invcol, accent, highlight, active);
    }
}

void HB_LookAndFeel::setLightColors(const QColor& col, QColor& colTrans, const QColor& invcol, int accent, int highlight, int active)
{
    m_iconShade = "light";

    m_baseColorAccent = col.lighter(accent).name(QColor::HexArgb);
    m_baseColorHighlight = col.lighter(highlight).name(QColor::HexArgb);
    m_baseColorActive = col.lighter(active).name(QColor::HexArgb);

    m_transColorAccent = colTrans.lighter(accent).name(QColor::HexArgb);
    m_transColorHighlight = colTrans.lighter(highlight).name(QColor::HexArgb);
    m_transColorActive = colTrans.lighter(active).name(QColor::HexArgb);

    QColor coltxt(255, 255, 255);
    m_textColor = coltxt.name(QColor::HexArgb);
    m_textColorDisabled = coltxt.darker(highlight).name(QColor::HexArgb);

    m_inverseColorHighlight = invcol.darker(highlight).name(QColor::HexArgb);
    m_inverseColorActive = invcol.darker(active).name(QColor::HexArgb);

    QColor invcoltxt(75, 75, 75);
    m_textInverseColor = invcoltxt.name(QColor::HexArgb);
    m_textInverseColorHighlight = invcoltxt.lighter(highlight).name(QColor::HexArgb);
    m_textInverseColorActive = invcoltxt.lighter(active).name(QColor::HexArgb);
}

void HB_LookAndFeel::setDarkColors(const QColor& col, QColor& colTrans, const QColor& invcol, int accent, int highlight, int active)
{
    m_iconShade = "dark";

    m_baseColorAccent = col.darker(accent).name(QColor::HexArgb);
    m_baseColorHighlight = col.darker(highlight).name(QColor::HexArgb);
    m_baseColorActive = col.darker(active).name(QColor::HexArgb);

    m_transColorAccent = colTrans.darker(accent).name(QColor::HexArgb);
    m_transColorHighlight = colTrans.darker(highlight).name(QColor::HexArgb);
    m_transColorActive = colTrans.darker(active).name(QColor::HexArgb);

    QColor coltxt(0, 0, 0);
    m_textColor = coltxt.name(QColor::HexArgb);
    m_textColorDisabled = coltxt.lighter(highlight).name(QColor::HexArgb);

    m_inverseColorHighlight = invcol.lighter(highlight).name(QColor::HexArgb);
    m_inverseColorActive = invcol.lighter(active).name(QColor::HexArgb);

    QColor invcoltxt(180, 180, 180);
    m_textInverseColor = invcoltxt.name(QColor::HexArgb);
    m_textInverseColorHighlight = invcoltxt.darker(highlight).name(QColor::HexArgb);
    m_textInverseColorActive = invcoltxt.darker(active).name(QColor::HexArgb);
}

void HB_LookAndFeel::emitColorsChanged()
{
    Q_EMIT iconShadeChanged();
    Q_EMIT baseColorChanged();
    Q_EMIT baseColorAccentChanged();
    Q_EMIT baseColorHighlightChanged();
    Q_EMIT baseColorActiveChanged();
    Q_EMIT inverseColorChanged();
    Q_EMIT inverseColorHighlightChanged();
    Q_EMIT inverseColorActiveChanged();
    Q_EMIT faintColorChanged();
    Q_EMIT transColorChanged();
    Q_EMIT transColorAccentChanged();
    Q_EMIT transColorHighlightChanged();
    Q_EMIT transColorActiveChanged();
    Q_EMIT transInverseColorChanged();
    Q_EMIT textColorChanged();
    Q_EMIT textColorDisabledChanged();
    Q_EMIT textInverseColorChanged();
    Q_EMIT textInverseColorHighlightChanged();
    Q_EMIT textInverseColorActiveChanged();
}

void HB_LookAndFeel::testtimer_timeout()
{
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;

    QString str = QString("#%1%2%3").arg(r, 2, 16, QChar('0')).arg(g, 2, 16, QChar('0')).arg(b, 2, 16, QChar('0'));

    setInterfaceAccentColor(str);
}

QString HB_LookAndFeel::getIconShade()
{
    return m_iconShade;
}

// Base color handling

QString HB_LookAndFeel::getBaseColor()
{
    return m_baseColor;
}

QString HB_LookAndFeel::getBaseColorAccent()
{
    return m_baseColorAccent;
}

QString HB_LookAndFeel::getBaseColorActive()
{
    return m_baseColorActive;
}

QString HB_LookAndFeel::getBaseColorHighlight()
{
    return m_baseColorHighlight;
}

void HB_LookAndFeel::setBaseColor(const QString& val)
{
    if (val != m_baseColor) {
        calculateColors(val);
        emitColorsChanged();
    }
}

/******************************************************/

QString HB_LookAndFeel::getInverseColor()
{
    return m_inverseColor;
}

QString HB_LookAndFeel::getInverseColorActive()
{
    return m_inverseColorActive;
}

QString HB_LookAndFeel::getInverseColorHighlight()
{
    return m_inverseColorHighlight;
}

/******************************************************/

QString HB_LookAndFeel::getTransColor()
{
    return m_transColor;
}

QString HB_LookAndFeel::getFaintColor()
{
    return m_faintColor;
}

QString HB_LookAndFeel::getTransColorAccent()
{
    return m_transColorAccent;
}

QString HB_LookAndFeel::getTransColorActive()
{
    return m_transColorActive;
}

QString HB_LookAndFeel::getTransColorHighlight()
{
    return m_transColorHighlight;
}

QString HB_LookAndFeel::getTransInverseColor()
{
    return m_transInverseColor;
}

// Text color handling

QString HB_LookAndFeel::getTextColor()
{
    return m_textColor;
}

QString HB_LookAndFeel::getTextColorDisabled()
{
    return m_textColorDisabled;
}

// Text inverse color handling

QString HB_LookAndFeel::getTextInverseColor()
{
    return m_textInverseColor;
}

QString HB_LookAndFeel::getTextInverseColorActive()
{
    return m_textInverseColorActive;
}

QString HB_LookAndFeel::getTextInverseColorHighlight()
{
    return m_textInverseColorHighlight;
}

// Font size handling

void HB_LookAndFeel::setFontSize(int val)
{
    if (val != m_fontSize) {
        calculateFontSizes(val);
        Q_EMIT fontSizeChanged();
        Q_EMIT fontSizeSChanged();
        Q_EMIT fontSizeLChanged();
        Q_EMIT fontSizeXLChanged();
        Q_EMIT fontSizeXXLChanged();
    }
}

int HB_LookAndFeel::getFontSize()
{
    return m_fontSize;
}

int HB_LookAndFeel::getFontSizeS()
{
    return m_fontSizeS;
}

int HB_LookAndFeel::getFontSizeL()
{
    return m_fontSizeL;
}

int HB_LookAndFeel::getFontSizeXL()
{
    return m_fontSizeXL;
}

int HB_LookAndFeel::getFontSizeXXL()
{
    return m_fontSizeXXL;
}

void HB_LookAndFeel::calculateFontSizes(int sze)
{
    m_fontSize = sze;
    m_fontSizeS = sze - 3;
    m_fontSizeL = sze + 4;
    m_fontSizeXL = sze + 9;
    m_fontSizeXXL = sze + 14;
}

// Font weight handling

int HB_LookAndFeel::getFontWeightBold()
{
    return m_fontWeightBold;
}

void HB_LookAndFeel::setFontWeightBold(int val)
{
    if (val != m_fontWeightBold) {
        m_fontWeightBold = val;
        Q_EMIT fontWeightBoldChanged();
    }
}

int HB_LookAndFeel::getFontWeightNormal()
{
    return m_fontWeightNormal;
}

void HB_LookAndFeel::setFontWeightNormal(int val)
{
    if (val != m_fontWeightNormal) {
        m_fontWeightNormal = val;
        Q_EMIT fontWeightNormalChanged();
    }
}

// Color names and hexes

QStringList HB_LookAndFeel::getColorNames()
{
    return colorNames;
}

QStringList HB_LookAndFeel::getColorHexes()
{
    return colorHexes;
}
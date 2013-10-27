#include "ConsoleScreen.hpp"

#include <algorithm>

#include <cstdio>
#include <cassert>

using namespace std;

ConsoleScreen::ConsoleScreen(unsigned width, unsigned height) :
                m_Width(width), m_Height(height) {
    const size_t realWidth = width + 1;
    const size_t pixels = realWidth * m_Height;
    m_BlankScreen.resize(pixels);
    m_Screen.resize(pixels);
    fill(m_Screen.begin(), m_Screen.end(), ' ');
    for (unsigned i = 0; i < m_Height; ++i)
        pixel(width, i) = '\n';
    pixel(width, height - 1) = '\0';
    m_BlankScreen = m_Screen;
}

size_t ConsoleScreen::coord(const unsigned x, const unsigned y) const {
    assert(x <= m_Width);
    assert(y <= m_Height);
    return y * (m_Width + 1) + x;
}

char& ConsoleScreen::pixel(const unsigned x, const unsigned y) {
    return m_Screen.at(coord(x, y));
}

void ConsoleScreen::setPixel(const unsigned x, const unsigned y, const char c) {
    const unsigned invertedY = m_Height - y;
    if (x < m_Width && invertedY < m_Height)
        pixel(x, invertedY) = c;
}

void ConsoleScreen::setPixelRelative(const float x, const float y, const char c) {
    const unsigned xpos = x * (m_Width - 1);
    const unsigned ypos = y * (m_Height - 1);
    setPixel(xpos, ypos, c);
}

void ConsoleScreen::clear() {
    copy(m_BlankScreen.begin(), m_BlankScreen.end(), m_Screen.begin());
}

void ConsoleScreen::show() {
    puts(m_Screen.data());
    printf("\033[%dA\r", m_Height);
}

unsigned ConsoleScreen::width() const {
    return m_Width;
}

unsigned ConsoleScreen::height() const {
    return m_Height;
}


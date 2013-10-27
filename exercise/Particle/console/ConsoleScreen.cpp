#include "ConsoleScreen.hpp"

#include <algorithm>

#include <cstdio>
#include <cassert>

using namespace std;

ConsoleScreen::ConsoleScreen(unsigned width, unsigned height) :
                m_Width(width), m_Height(height), m_BlankScreen(width + 2 + 1, height + 2), m_Screen(0, 0) {
    // preparing blank screen
    const unsigned lastX = m_BlankScreen.width() - 2;
    const unsigned lastY = m_BlankScreen.height() - 1;
    for (int x = 0; x < lastX; ++x) {
        m_BlankScreen.pixel(x, 0) = '-';
        m_BlankScreen.pixel(x, lastY) = '-';
    }
    for (int y = 0; y < m_BlankScreen.height(); ++y) {
        m_BlankScreen.pixel(0, y) = '|';
        m_BlankScreen.pixel(lastX, y) = '|';
        m_BlankScreen.pixel(lastX + 1, y) = '\n';
    }
    m_BlankScreen.pixel(0, 0) = '+';
    m_BlankScreen.pixel(0, lastY) = '+';
    m_BlankScreen.pixel(lastX, 0) = '+';
    m_BlankScreen.pixel(lastX, lastY) = '+';
    m_Screen = m_BlankScreen;
}

char& ConsoleScreen::pixel(const unsigned x, const unsigned y) {
    return m_Screen.pixel(x + 1, y + 1);
}

void ConsoleScreen::setPixel(const unsigned x, const unsigned y, const char c) {
    const unsigned invertedY = m_Height - y - 1;
    if (x < m_Width && invertedY < m_Height) pixel(x, invertedY) = c;
}

void ConsoleScreen::setPixelRelative(const float x, const float y, const char c) {
    const unsigned xpos = x * (m_Width - 1);
    const unsigned ypos = y * (m_Height - 1);
    setPixel(xpos, ypos, c);
}

void ConsoleScreen::clear() {
    m_Screen = m_BlankScreen;
}

void ConsoleScreen::show() {
    puts(m_Screen);
    printf("\033[%dA\r", m_Height + 3);
}

unsigned ConsoleScreen::width() const {
    return m_Width;
}

unsigned ConsoleScreen::height() const {
    return m_Height;
}

ConsoleScreen::Buffer::Buffer(unsigned width, unsigned height) :
                m_Width(width), m_Height(height), m_Data(m_Width * m_Height, ' ') {
}

ConsoleScreen::Buffer& ConsoleScreen::Buffer::operator=(const Buffer& other) {
    m_Width = other.m_Width;
    m_Height = other.m_Height;
    m_Data = other.m_Data;
    return *this;
}

char& ConsoleScreen::Buffer::pixel(const unsigned x, const unsigned y) {
    return m_Data.at(coord(x, y));
}

size_t ConsoleScreen::Buffer::coord(const unsigned x, const unsigned y) const {
    assert(x <= m_Width);
    assert(y <= m_Height);
    return y * m_Width + x;
}

unsigned ConsoleScreen::Buffer::width() const {
    return m_Width;
}
unsigned ConsoleScreen::Buffer::height() const {
    return m_Height;
}
ConsoleScreen::Buffer::operator const char*() const {
    return m_Data.data();
}

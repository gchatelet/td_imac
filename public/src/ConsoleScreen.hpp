#pragma once

#include <vector>

#include <cstring>

/**
 * Text buffer to draw in the console
 */
class ConsoleScreen {
public:
    ConsoleScreen(unsigned width, unsigned height);

    // sets the character 'c' to display at coordinates (x,y)
    void setPixel(const unsigned x, const unsigned y, const char c);
    // sets the character 'c' to display at normalized coordinates (x,y)
    void setPixelRelative(const float x, const float y, const char c);

    // displays the current state of the buffer
    void show();
    // clears the buffer
    // Note : add a call to show() if you also want to display the cleaned buffer.
    void clear();

    // size of the current buffer
    unsigned width() const;
    unsigned height() const;

private:
    size_t coord(const unsigned x, const unsigned y) const;
    char& pixel(const unsigned x, const unsigned y);

    const unsigned m_Width;
    const unsigned m_Height;
    std::vector<char> m_Screen;
    std::vector<char> m_BlankScreen;
};

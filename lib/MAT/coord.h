#ifndef COORD_h
#define COORD_h

struct coord {
    int x, y;

    coord operator+(const coord& other) const {
        return { x + other.x, y + other.y };
    }

    coord operator-(const coord& other) const {
        return { x - other.x, y - other.y };
    }

    bool operator==(const coord& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const coord& other) const {
        return !(*this == other);
    }
};

#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
};

// Ray-casting point-in-polygon
bool pointInPolygon(double px, double py, const std::vector<Point>& poly) {
    bool inside = false;
    int n = poly.size();
    for (int i = 0, j = n - 1; i < n; j = i++) {
        double xi = poly[i].x, yi = poly[i].y;
        double xj = poly[j].x, yj = poly[j].y;
        bool intersect = ((yi > py) != (yj > py)) &&
                         (px < (xj - xi) * (py - yi) / (yj - yi + 1e-9) + xi);
        if (intersect) inside = !inside;
    }
    return inside;
}

// Distance from point to segment with thickness
bool nearLine(double px, double py, Point a, Point b, double thickness) {
    double dx = b.x - a.x, dy = b.y - a.y;
    double len2 = dx*dx + dy*dy;
    if (len2 == 0.0) return false;
    double t = ((px - a.x)*dx + (py - a.y)*dy) / len2;
    t = std::max(0.0, std::min(1.0, t));
    double lx = a.x + t*dx, ly = a.y + t*dy;
    double dist = std::sqrt((px - lx)*(px - lx) + (py - ly)*(py - ly));
    return dist < thickness;
}

int main() {
    const int width  = 400;
    const int height = 400;
    const double radius = 150.0;
    const double thickness = 5.0; // X stroke thickness

    std::ofstream out("TitanLogo.ppm");
    if (!out) {
        std::cerr << "Error: Could not open file\n";
        return 1;
    }

    out << "P3\n" << width << " " << height << "\n255\n";

    double cx = width / 2.0;
    double cy = height / 2.0;

    // Perfect hexagon with tips at top/bottom (start angle = 90°)
    std::vector<Point> hex;
    for (int i = 0; i < 6; ++i) {
        double angle = M_PI/3.0 * i + M_PI/2.0; // 60° steps, rotated to put a tip at 12 o'clock
        hex.push_back({ cx + radius * std::cos(angle),
                        cy + radius * std::sin(angle) });
    }

    // Vertex mapping with this orientation:
    // 0: top, 1: top-left, 2: bottom-left, 3: bottom, 4: bottom-right, 5: top-right
    Point top        = hex[0];
    Point topLeft    = hex[1];
    Point bottomLeft = hex[2];
    Point bottom     = hex[3];
    Point bottomRight= hex[4];
    Point topRight   = hex[5];

    // X through side vertices: top-left ↔ bottom-right and top-right ↔ bottom-left
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int r, g, b;
            if (pointInPolygon(x, y, hex)) {
                bool onX = nearLine(x, y, topLeft, bottomRight, thickness) ||
                           nearLine(x, y, topRight, bottomLeft, thickness);
                if (onX) {
                    r = g = b = 0;      // black X
                } else {
                    r = 200; g = 0; b = 0; // red fill
                }
            } else {
                r = g = b = 0; // black background
            }
            out << r << " " << g << " " << b << " ";
        }
        out << "\n";
    }

    out.close();
    std::cout << "TitanLogo.ppm (" << width << "x" << height << ")\n";
    return 0;
}

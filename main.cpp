// 1) На вхід подається послідовність точок цілочислового тривимірного простору.
// Знайти та вивести y-координату, яку має найбільша кількість точок.
// Якщо таких кілька, то вивести всі такі у-координати. Також вивести кількість точок.
// Вхід: послідовність точок тривимірного простору, по одній на рядок;
// введення припиняється на першій помилці.
// формат точок:
// ( ціле, ціле, ціле)
// Вихід:
// на першому рядку  *****
// на другому рядку кількість зчитаних точок
// на третьому рядку найбільша кількість точок зі спільною у-координатою
// на подальших рядках: усі такі точки у форматі ( ціле, ціле, ціле),
// по одній на рядок (точки сортуються лексикографічно).

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <regex>

struct Point {
    int x, y, z;
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
    bool operator<(const Point& other) const {
        if (x != other.x) { return x < other.x; }
        if (y != other.y) { return y < other.y; }
        return z < other.z;
    }
};

bool read_point(const std::string& line, Point& point) {
    static const std::regex pattern(R"(^\(\s(-?\d+),\s(-?\d+),\s(-?\d+)\)$)");
    std::smatch matches;
    if (std::regex_match(line, matches, pattern)) {
        point.x = std::stoi(matches[1]);
        point.y = std::stoi(matches[2]);
        point.z = std::stoi(matches[3]);
        return true;
    }
    return false;
}

void print_result(std::smatch& matches, const std::set<Point>& all_points) {
    std::cout << "*****" << std::endl;
    std::cout << matches.size() << std::endl;

}

int main() {
    std::set<Point> all_points;
    std::map<int, int> y_counts;
    std::string str;

    while (std::getline(std::cin, str)) {
        Point point(0, 0, 0);
        if (!read_point(str, point)) { break; }
        all_points.insert(point);
        y_counts[point.y]++;
    }



    return 0;
}


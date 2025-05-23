#include <iostream>
#include <string>
#include <set>
#include <map>
#include <regex>
#include <stdexcept>

struct Point {
    int x, y, z;
    bool operator<(const Point& other) const {
        if (x != other.x) { return x < other.x; }
        if (y != other.y) { return y < other.y; }
        return z < other.z;
    }
};

bool read_point(const std::string& line, Point& point) {
    std::smatch matches;
    static const std::regex pattern(R"(^\(\s(-?\d+),\s(-?\d+),\s(-?\d+)\)$)");
    if (std::regex_match(line, matches, pattern)) {
        point.x = std::stoi(matches[1]);
        point.y = std::stoi(matches[2]);
        point.z = std::stoi(matches[3]);
        return true;
    }
    return false;
}

void check_input(const std::set<Point>& points) {
    if (points.empty()) {
        throw std::logic_error("No points given or wrong format. Expected format: ( x, y, z)");
    }
}

std::pair<int, int> find_max_y(const std::map<int, int>& y_counts) {
    int res {0}, count_max {0};
    for (const auto& [y, count] : y_counts) {
        if (count > count_max) {
            count_max = count;
            res = y;
        }
    }
    return {res, count_max};
}

void print_result(const std::set<Point>& points, const std::map<int, int>& y_counts) {
    std::cout << "*****" << std::endl;
    std::cout << points.size() << std::endl;
    std::pair<int, int> max_y = find_max_y(y_counts);
    std::cout << max_y.second << std::endl;
    for (const auto& point : points) {
        if (point.y == max_y.first) {
            std::cout << "( " << point.x << ", " << point.y << ", " << point.z << ")" << std::endl;
        }
    }
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
    try {
        check_input(all_points);
        print_result(all_points, y_counts);
    } catch (const std::logic_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


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
#include <set>
#include <string>
#include <map>


struct Point3 {
    int x;
    int y;
    int z;

    Point3(int x, int y, int z) : x(x), y(y), z(z) {}

    bool operator<(const Point3& other) const {
        if (y != other.y) return y < other.y;
        if (x != other.x) return x < other.x;
        return z < other.z;
    }
};

std::ostream& operator<<(std::ostream& os, const Point3& point) {
    os << "( " << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}

void read_points(std::set<Point3>& points) {
    std::string str;
    while (std::getline(std::cin, str)) {
        int x, y, z;
        if (sscanf_s(str.c_str(), "( %d , %d , %d)", &x, &y, &z) != 3) {
            return;
        }
        points.insert(Point3(x, y, z));
    }
}

void count_points(std::set<Point3>& points, std::map<int, int>& count) {

}

int main() {
    std::map<int, int> y_count; // maybe will be changed in future
    std::set<Point3> points;
    read_points(points);
    count_points(points, y_count);


    return 0;
}
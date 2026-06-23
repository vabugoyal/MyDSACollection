#include "string"
#include "vector"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
#include <tuple>
#include <utility>

#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>


int main() {
    using namespace boost::gregorian;

    date d(2026, 6, 24);

    std::cout << "Date: " << to_simple_string(d) << "\n";
}

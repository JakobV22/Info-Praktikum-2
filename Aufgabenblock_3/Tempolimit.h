#include <math.h>
/**
 * enum class zur speicherung der 3 Tempolimits
 */
enum class Tempolimit {
	Innerorts = 50, Außerorts = 100, Autobahn = std::numeric_limits<int>::max()
};

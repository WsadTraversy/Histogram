#include <string>
#include <map>

class digits {
	std::string stored_digits;
public:
	digits() = default;

	void load();
	void change_values(std::string value);
	std::string stored() const;
	void menu_main();
	void menu_second();
	long int digits_ammount() const;
	int median_min_max(int n) const;

private:
	std::map<int, std::string> prepare_values();
	void draw_histogram();
};

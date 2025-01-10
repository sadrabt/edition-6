import <print>;


int main()
{
	float myFloat{ 3.14f };
	int i1{ (int)myFloat };                // method 1
	int i2{ int(myFloat) };                // method 2
	int i3{ static_cast<int>(myFloat) };   // method 3

	short someShort{ 16 };
	long someLong{ someShort };          // no explicit cast needed
	

	// floating point checks
	float nan { 0.0f / 0 };
	float in { 10.0f / 0};
	std::println("0/0 = {}", nan);
	std::println("10/0 = {}", in);
}

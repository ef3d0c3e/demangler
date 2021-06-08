#include <iostream>
#include <memory>
#include <cxxabi.h>

std::string demangle(const char* name)
{
	std::unique_ptr<char, void (*)(void*)> own(abi::__cxa_demangle(name, nullptr, nullptr, nullptr), std::free);
	return own != nullptr ? own.get() : name;
}

int main(int argc, char* argv[])
{
	if (argc < 1)
	{
		std::cerr << "USAGE: " << argv[0] << " TYPENAME...\n";
		return 1;
	}

	for (int i = 1; i < argc; ++i)
		std::cout << demangle(argv[i]) << "\n";

	return 0;
}

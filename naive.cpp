#include <cstdint>
#include <cstring>
#include <iostream>

struct match
{
	size_t pos;
};

struct naive_match_iterator
{
	const uint8_t * x;
	size_t n;
	const uint8_t * p;
	size_t m;
	size_t current_index;

	naive_match_iterator(
		const uint8_t * px,
		size_t vn,
		const uint8_t * pp,
		size_t vm
	)
		: x(px)
		, n(vn)
		, p(pp)
		, m(vm)
		, current_index(0)
	{}
};

bool next_naive_match(naive_match_iterator & iter, match & result)
{
	auto n = iter.n;
	auto m = iter.m;
	auto x = iter.x;
	auto p = iter.p;

	if(m > n)
	{
		return false;
	}

	if(m == 0)
	{
		return false;
	}

	for(size_t base = iter.current_index; base <= n - m; ++base)
	{
		size_t offset = 0;
		while(offset < m && x[base + offset] == p[offset])
		{
			++offset;
		}

		if(offset == m)
		{
			iter.current_index = base + 1;
			result.pos = base;
			return true;
		}
	}

	return false;
}

int main()
{
	const uint8_t * s = reinterpret_cast<const uint8_t *>("foo bar foobar");
	const uint8_t * p = reinterpret_cast<const uint8_t *>("foo");

	naive_match_iterator i(
		s,
		strlen(reinterpret_cast<const char *>(s)),
		p,
		strlen(reinterpret_cast<const char *>(p))
	);
	match result { 0 };

	while(next_naive_match(i, result))
	{
		std::cout.write(reinterpret_cast<const char *>(s + result.pos), i.m) << std::endl;
	}
}

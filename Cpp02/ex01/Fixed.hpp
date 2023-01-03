#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& f);
		~Fixed(void);
		int				getRawBits(void) const;
		float			toFloat(void) const;
		int				toInt(void) const;
		Fixed&			operator=(const Fixed& f);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif

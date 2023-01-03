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
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;

		Fixed&			operator=(const Fixed& f);
		bool			operator>(const Fixed& f) const;
		bool			operator<(const Fixed& f) const;
		bool			operator>=(const Fixed& f) const;
		bool			operator<=(const Fixed& f) const;
		bool			operator==(const Fixed& f) const;
		bool			operator!=(const Fixed& f) const;

		Fixed			operator+(const Fixed& f) const;
		Fixed			operator-(const Fixed& f) const;
		Fixed			operator*(const Fixed& f) const;
		Fixed			operator/(const Fixed& f) const;

		Fixed&			operator++(void);
		Fixed			operator++(int);
		Fixed&			operator--(void);
		Fixed			operator--(int);

		static Fixed&	min(Fixed& f1, Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
  private:
    int               _f_point_val;
    static const int  _frac_bits = 8; // literal cannot initialize with member initializer

  public:
    Fixed(void);
    Fixed(const int);
    Fixed(const float);
    
    ~Fixed(void);
    Fixed(const Fixed& f);

    Fixed&  operator=(const Fixed& f);
    bool    operator<(const Fixed& f) const;
    bool    operator>(const Fixed& f) const;
    bool    operator>=(const Fixed& f) const;
    bool    operator<=(const Fixed& f) const;
    bool    operator==(const Fixed& f) const;
    bool    operator!=(const Fixed& f) const;

    Fixed   operator+(const Fixed &f) const;
    Fixed   operator-(const Fixed &f) const;
    Fixed   operator*(const Fixed &f) const;
    Fixed   operator/(const Fixed &f) const;
    Fixed&  operator++(void); // pre-increment
    Fixed   operator++(int); // post-increment
    Fixed&  operator--(void); // pre-decrement
    Fixed   operator--(int); // post-decrements

    static Fixed& min(Fixed& f1, Fixed& f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);
    static Fixed& max(Fixed& f1, Fixed& f2);
    static const Fixed& max(const Fixed& f1, const Fixed& f2);

    int     getRawbits(void) const;
    void    setRawbits(int const raw);
    int     toInt(void) const;
    float   toFloat(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed& f);

#endif
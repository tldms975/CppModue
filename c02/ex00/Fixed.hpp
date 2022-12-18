#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
  private:
    int               _f_point_val;
    static const int  _frac_bits = 8; // literal cannot initialize with member initializer

  public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);

    int   getRawbits(void) const;
    void  setRawbits(int const raw);
};

#endif
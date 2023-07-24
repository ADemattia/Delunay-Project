#ifndef __sqrt_HPP__
#define __sqrt_HPP__

#include <math.h>

class IPen {
  public:
    virtual ~IPen() {};
    virtual void PenUp() const = 0;
    virtual void PenDown() const = 0;
    virtual void Forward(const unsigned int& distance) = 0;
    virtual void Turn(const int& degrees) = 0;
    virtual void GoTo(const int& x,
                      const int& y) const = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};

class Painter
{
  private:
    const IPen& pen;
  public:
    Painter(const IPen& pen) :
      pen(pen) { }
    bool DrawCircle(const int& x,
                    const int& y,
                    const unsigned int& radius)
    {
      pen.GoTo(x, y);
      pen.PenDown();

      if (radius > 0)
      {
        // draw cirlce...
      }

      pen.PenUp();
      return (pen.GetX() == 1);
    }
};

// Get the Square root of a number. 
double squareRoot(const double a) 
{
  const double b = sqrt(a);

  if (b != b) // NaN check
    return -1.0;
  else
    return b;
}

#endif // __sqrt_HPP__

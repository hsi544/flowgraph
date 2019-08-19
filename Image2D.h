#include <vector>

class Image2D{
public:
  Image2D():m_sizex(0), m_sizey(0){}
  Image2D(const Image2D& other):m_sizex(other.m_sizex), m_sizey(other.m_sizey), m_pixels(other.m_pixels){}
  Image2D(size_t szx, size_t szy):m_sizex(szx), m_sizey(szy){ m_pixels.resize(m_sizex*m_sizey); }
  size_t size() const {return m_sizex*m_sizey;}
  size_t sizex() const {return m_sizex;}
  size_t sizey() const {return m_sizey;}
  void resize(size_t szx, size_t szy) { 
     m_sizex = szx;
     m_sizey = szy;
     m_pixels.resize(m_sizex*m_sizey);}
  float checkSum();
  float& operator() (size_t x, size_t y) { return m_pixels[y*m_sizex+x];} 
  float& operator[] (size_t index) { return m_pixels[index];} 
  const float& operator[] (size_t index) const { return m_pixels[index];} 
private:
   size_t m_sizex;
   size_t m_sizey;
   std::vector<float> m_pixels;
   

};


void imSub(Image2D& res, Image2D& im1, Image2D& im2);
void imFilter(Image2D& res, Image2D& im1, Image2D& im2);


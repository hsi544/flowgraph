#include "Image2D.h"
#include <iostream>


float Image2D::checkSum() {
   float sum = 0.0f;
   for(int i = 0 ; i < m_sizey ; i++) {
      for(int j = 0 ; j < m_sizex ; j++) {
         sum+=m_pixels[i*m_sizex+j];
      }
   }
   return sum;
}

void imSub(Image2D& res, Image2D& im1, Image2D& im2) {
   assert(im1.size() == im2.size());
   for(int i = 0 ; i < im1.sizey() ; i++) {
      for(int j = 0 ; j < im1.sizex() ; j++) {
         res(i,j)=im1(i,j)-im2(i,j);
      }
   }
}

void imFilter(Image2D& res, Image2D& im1, Image2D& filter) {

   int radius = filter.sizex()/2;
   for(int i = 1 ; i < im1.sizey()-1 ; i++) {
      for(int j = 1 ; j < im1.sizex()-1 ; j++) {
         float sum = 0.0;
         for(int k = 0 ; k < filter.sizex() ; k++) {
            for(int l = 0 ; l < filter.sizey() ; l++) {
               sum+=im1(i-radius+k,j-radius+l)*filter(k,l);
            }
         }
         res(i,j)=sum;
      }
   }
}
